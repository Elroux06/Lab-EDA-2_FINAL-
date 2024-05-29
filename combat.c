
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>







typedef struct Node
{
    void *fighter; // since it can be either a Charater* or an Enemy* we use void
    struct Node *next;
} Node;
// define the structure of a queue
typedef struct Queue
{
    Node *first; // points to the first of the queue
    Node *last;  // points to the last of the queue
} Queue;

// Create a new node
Node *newNode(void *fighter)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->fighter = fighter;
    temp->next = NULL;
    return temp;
}
void enqueue(Queue *queue, void *fighter)
{
    // create a new node
    Node *node = newNode(fighter);

    // If the queue is empty, then the new node is both first and last
    if (queue->last == NULL)
    {
        queue->first = node;
        queue->last = node;
        return;
    }

    // Add the new node at the end of the queue and update last
    queue->last->next = node;
    queue->last = node;
}

// remove a fighter from the first of the queue
void *dequeue(Queue *queue)
{
    // if the queue is empty, return NULL
    if (queue->first == NULL)
        return NULL;

    // store the previous first and move first one node ahead
    Node *temp = queue->first;
    void *fighter = temp->fighter;

    queue->first = queue->first->next;

    // if first becomes NULL, then change last also as NULL
    if (queue->first == NULL)
        queue->last = NULL;

    free(temp);

    return fighter;
}

// Create a new queue
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}
Skill *getSkillFromPlayer(Character *player)
{
    int skill_number;
    printf("\nChoose a skill:\n\n");
    for (int i = 0; i < YOUR_SKILLS; i++)
    {
        
        
        printf("%d. %s\n", i + 1, player->skills[i]->name);
        printf("HP: %d, ATK: %d, DEF: %d\n",
               player->skills[i]->hpmodifier,
               player->skills[i]->atkmodifier,
               player->skills[i]->DEFmodifier);
        // print type of skill
        if (player->skills[i]->type ==MULTIPLE_ROUND_MODIFIER)
        {
            
            
            printf("Type: Temporary modifier\n");
            printf("rounds: %d \n",player->skills[i]->duration);
           
        }
        else
        {
            
            printf("Type: Direct attack\n");
            printf("rounds: %d \n",player->skills[i]->duration);
           
        }
        // print separator only if it's not the last skill
        if (i != MAX_SKILLS - 1)
        {
            printf("------------------------------------------------\n");
        }
    }
    do // continue asking until the user enters a valid skill number
    {
        printf("\nEnter the number of the skill: ");
        scanf("%d", &skill_number);
        getchar(); // read the newline character
    } while (skill_number < 1 || skill_number > MAX_SKILLS);
    return player->skills[skill_number - 1];
}
bool combat(Character *player, Enemy *enemy, Skill *skills)
{
    srand(time(NULL)); // seed the random number generator. This is needed to generate random numbers.
    /*
     is a built-in function in C and C++ used to set the seed for the pseudo-random number generator.
    srand stands for "seed random".
    It is used to initialize the random number generator in C.
    The time(NULL) function returns the current date and time, so every time your program runs,
    srand gets a different argument and hence, generates a different sequence of random numbers.
    */

    // Initialize the queue with the player and the enemy turns
    Queue *queue = createQueue();

    // Randomly choose the order of turns. In this queue we will store the turns of the player and the enemy
    // we enqueue the player and the enemy in a random order
    for (int i = 0; i < MAX_TURNS; i++)
    {
        if (rand() % 2 == 0)

        { // 50% chance
            enqueue(queue, player);
            
        }
        else
        {
            enqueue(queue, enemy);
            
        }
    }

    // Main combat loop. We traverse the queue and dequeue the player and the enemy turns
    while (queue->first != NULL && player->hp > 0 && enemy->hp > 0) // todo: add isEmpty(queue) function
    {
        if (dequeue(queue) == player) // ----------------------- TURN OF THE PLAYER
        {
            

            printf("\n========= Player's turn ========\n");
            // print name of the player in the character
            printf("Go  %s!!!! it's your turn!\n", player->name);
            Skill *chosen_skill = getSkillFromPlayer(player);

            if (chosen_skill->type == MULTIPLE_ROUND_MODIFIER) // if the skill is a temporary modifier
            {
                player->def += chosen_skill->DEFmodifier;
                player->hp += chosen_skill->hpmodifier;
                player->atk += chosen_skill->atkmodifier;

                chosen_skill->duration--; // decrease the duration of the skill as it has been used
                if (chosen_skill->duration == 0)
                {
                    player->def -= chosen_skill->DEFmodifier;
                    player->hp -= chosen_skill->hpmodifier;
                    player->atk -= chosen_skill->atkmodifier;
                }
            }
            else //direct attack
            {

                if (chosen_skill->atkmodifier == 0)
                {
                    // the player is using a skill that modifies their stats
                    player->hp += chosen_skill->hpmodifier;
                    player->def += chosen_skill->DEFmodifier;
                }
                else
                {
                    // the player is using a skill that attacks the enemy (direct attack)
                    // hp of the enemy is decreased by the ATKmodifier of the chosen skill
                    // minus the DEF of the enemy
                    int real_damage = chosen_skill->atkmodifier + player->atk - enemy->def;
                    
                    if (real_damage < 0)
                    {
                        real_damage = 0;
                        
                    }
                    
                    enemy->hp -= real_damage;
                    if (enemy->hp < 0) // in this case, the player's DEF is higher than the enemy's ATK
                    {
                        enemy->hp = 0;
                    
                    }

                    player->hp += chosen_skill->hpmodifier;
                    // we assume that we don't decrease the DEF of the enemy
                    player->def -= DEF_TO_SUBSTRACT;
                    if (player->def < 0) // in this case, the player's DEF is higher than the enemy's ATK
                    {
                        player->def = 0;
                    
                    }

                }
            }
            
        }
        else // ----------------------- TURN OF THE ENEMY
        {
            
            printf("\n======== Enemy's turn ==========\n");
            // Randomly select a skill from the 10th and the 19th position in the array of available skills
            // as we store the skills of the enemies from index 9
            int skillIndex = rand() % 9 + 8;// Random number between 8 and 16

            Skill *skill = &skills[skillIndex];

            printf("%s used skill: %s\n",enemy->name,skill->name);
            
           
                // we modify the player's stats directly
            if (skill->atkmodifier == 0)
            {
                    // the enemy is using a skill that modifies the their stats
                enemy->hp += skill->hpmodifier;
                enemy->def += skill->DEFmodifier;
            }
            else // if the skill is a direct attack
            {

                // the enemy is using a skill that attacks the player (direct attack
                int real_damage = skill->atkmodifier + enemy->atk - player->def;
                
                if (real_damage < 0) // in this case, the player's DEF is higher than the enemy's ATK
                {
                    real_damage = 0;
                    
                }
                player->hp -= real_damage;
                if (player->hp < 0) // in this case, the player's DEF is higher than the enemy's ATK
                {
                    player->hp = 0;
                    
                }
                enemy->hp += skill->hpmodifier;
                enemy->def += skill->DEFmodifier;
                enemy->def -= DEF_TO_SUBSTRACT;
                if (enemy->def < 0) // in this case, the player's DEF is higher than the enemy's ATK
                {
                    enemy->def = 0;
                    
                }

            }
            
            
        }
        // print stats after the turn
       
        printf("Turn ended!. These are the stats after the turn:\n");
        printf("Player's stats:\n");
        printf("HP: %d, ATK: %d, DEF: %d\n", player->hp, player->atk, player->def);
        printf("Enemy's stats:\n");
        printf("HP: %d, ATK: %d, DEF: %d\n", enemy->hp, enemy->atk, enemy->def);
        
       if (player->hp <= 0)
       {
            printf("Player has %d of HP. You lost...", player->hp);
            return false;
        }
        else if (enemy->hp <= 0)
        {
            printf("Enemy has %d of HP. You won!!", enemy->hp);
            return true;
        }
       
    }

    // Check the result of the combat
    
}
