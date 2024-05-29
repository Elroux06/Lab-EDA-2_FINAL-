#include "common.h"
void waitForKey()
{
    int c;
    printf("Press Enter to continue...");
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void tutorial() 
{

   
    printf("\n=========== Welcome to the Combat Tutorial ===========\n\n");
    Sleep(500);
    
    
    printf ("\nThis Tutorial Scenario will clarify the mechanics of tthe game \n\n");
    Sleep(500);
    printf("\n In this game you will move trough different Scenarios.\n" "\n In every Scenario you will choose Options regarding Questions.\n" "\n Inside the Options you will face some challenges in the form of a FIGHT.\n" "\n Here you will lear how to move trough the game and how to fight\n");
    printf("I hope you are paying attention.");
    Sleep(500);
    waitForKey();
    Sleep(500);
    printf("\n Imagine the following Scenario. You are just thinking what to do woth your life.\n" "\nDo you want to do study Telecos (1) or to pursue your dream of being a country musician (2)??\n");
    printf("\n IMAGINE you decided to study telecos.(1)\n");
    Sleep(500);
    printf("\n\nYou will face the curse of MATHEMATICAL METHODS, now its time to fight for your credits...\n\n");
    Sleep(500);
    
    printf("\n Before the interactive fight, let me explain you the way the fight flow goes=\n\n");
    Sleep(500);
    
    Sleep(500);
    waitForKey();

    // Introduction to the combat system
    printf("In this combat system, you will take turns with an enemy to use skills and attack.\n");
    Sleep(500);
    printf("Each character (you and the enemy) has health points (hp), attack points (atk), defense points (def), and some associated skills.\n\n");
    printf("Let me explain breifly the mechanics before entering the tutorial.");
    Sleep(500);
    printf ("\n In this game you will move trough different Scenarios.\n" "\n In every Scenario you will choose Options regarding Questions.\n" "\n Inside the Options you will face some challenges in the form of a COMBAT.\n" "\n Here you will lear how to move trough the game and how to fight\n");
    
    waitForKey();
    Sleep(500);
    
    // Explanation of the turn order
    printf("At the start of combat, the turn order is randomly decided.\n");
    Sleep(500);
    printf("You or the enemy could go first, so be prepared!\n\n");
    Sleep(500);

    waitForKey();
    // Player's turn
    printf("========== Player's Turn ==========\n");
    Sleep(500);
    printf("When it's your turn, you will choose a skill to use.\n");
    Sleep(500);
    printf("Skills can either be attacks or temporary modifiers.\n");
    Sleep(500);
    printf("1. Direct Attack: Reduces the enemy's hp based on your atk and the skill's atk modifier.\n");
    Sleep(500);
    printf("2. Temporary Modifier: Boosts your hp, atk, or def for a certain duration.\n");
    Sleep(500);
    printf("Choose wisely based on the situation!\n\n");

    waitForKey();
    printf("========== Using Skills ==========\n");
    Sleep(500);
    printf("When you use a skill, its effects are applied immediately.\n");
    Sleep(500);
    printf("For example, if you use a skill with an atk modifier, it reduces the enemy's hp by your atk plus the skill's atk modifier minus the enemy's def.\n");
    Sleep(500);
    printf("If you use a temporary modifier skill, it increases your stats (hp, atk, def) for a set duration.\n");
    Sleep(500);
    printf("Be mindful of the skill's duration, as its effects will wear off after a certain number of turns.\n\n");
    Sleep(500);
    
    
    waitForKey();
    // Enemy's turn
    printf("========== Enemy's Turn ==========\n");
    Sleep(500);
    printf("When it's the enemy's turn, they will randomly choose a skill to use against you.\n");
    Sleep(500);
    printf("Just like you, they can use either direct attacks or temporary modifiers.\n\n");
    Sleep(500);
    waitForKey();
    // Combat ends
    printf("========== End of Combat ==========\n");
    printf("Combat continues in turns until either your hp or the enemy's hp reaches 0.\n");
    Sleep(500);
    printf("If your hp drops to 0, you lose. If the enemy's hp drops to 0, you win!\n");
    Sleep(500);
    printf("Manage your skills and resources wisely to emerge victorious!\n\n");
    
    waitForKey();
    // Closing remarks
    printf("Now that you know the basics, jump into combat and show your skills!. You will be using the OG Pompeu Champion. Make her proud!!!\n");
    Sleep(500);

    

    printf ("Congratulations you have completed the tutorial tutorial\n");
    Sleep(500);
    printf("You will be redirected to the Main Menu. Press Enter to go...\n");
    Sleep(500);
    return ;

}