#include "common.h"
#include "structures.h"
#include "combat.c"

void createEnemy(Enemy *enemy, char *name, char *description, int hp, int atk, int def) {
    strcpy(enemy->name, name);
    strcpy(enemy->description, description);
    enemy->hp = hp;
    enemy->atk = atk;
    enemy->def = def;
}

void createscenario1(Scenario *scenario)
{
    strcpy(scenario->name , "Theory Class");
    strcpy(scenario->description, "This is your theory class at university, and you have to learn some content to solve the final exam.");

    // Decision 1: Sit alone or find a friend
    strcpy(scenario->decisions[0].question,"You see your friends in class. What will you do?");
    
    // Option 1: Sit alone
    strcpy(scenario->decisions[0].options[0].response_text,"You decide to sit alone.(1)");
    strcpy(scenario->decisions[0].options[0].pre_narrative, "As you sit alone, a bully notices you and approaches.");
    createEnemy(&scenario->decisions[0].options[0].enemy,"Bully","He has some trauma and wants to steal your money",60,10,5);

    strcpy(scenario->decisions[0].options[0].post_narrative, "You manage to handle the bully and continue with the class, earning 5 academic credits.");

    // Option 2: Sit with friends
    strcpy(scenario->decisions[0].options[1].response_text,"You decide to sit with your friends.(2)");
    strcpy(scenario->decisions[0].options[1].pre_narrative, "Your friends turn out to be manipulators who distract you.");
    createEnemy(&scenario->decisions[0].options[1].enemy,"Manipulator","Master of social manipulation",50,20,5);
    strcpy(scenario->decisions[0].options[1].post_narrative, "You overcome their manipulation and manage to focus on the class, earning 5 academic credits.");

    // Decision 2: Class is boring. Sleep or stay focused
    strcpy(scenario->decisions[1].question,"The class is boring. What will you do?");
    
    // Option 1: Sleep
    strcpy(scenario->decisions[1].options[0].response_text,"You decide to sleep.(1)");
    strcpy(scenario->decisions[1].options[0].pre_narrative, "The teacher notices you sleeping and gets angry.");
    createEnemy(&scenario->decisions[1].options[0].enemy,"Theory Teacher","He is punishing you",50,10,15);
    strcpy(scenario->decisions[1].options[0].post_narrative, "You manage to avoid trouble and continue with the class, but it was a close call.");

    // Option 2: Stay focused
    strcpy(scenario->decisions[1].options[1].response_text,"You decide to stay focused(2).");
    strcpy(scenario->decisions[1].options[1].pre_narrative, "Another student tries to distract you.");
    createEnemy(&scenario->decisions[1].options[1].enemy,"Student","He is distracting you",40,15,20);
    strcpy(scenario->decisions[1].options[1].post_narrative, "You ignore the distractions and manage to stay focused, earning 5 academic credits.");

    scenario->available_scenarios[0] = 0;
    scenario->available_scenarios[1] = 1;
    scenario->available_scenarios[2] = 1;
    scenario->available_scenarios[3] = 0;
}

void createscenario2 (Scenario *scenario)
{
    strcpy(scenario->name,"Library"); 
    strcpy(scenario->description, "It's a normal morning on campus, and you are entering the library building after your class hours.");
    
    // edges in graph (possible paths between scenarios)
    scenario->available_scenarios[0] = 1;
    scenario->available_scenarios[1] = 0;
    scenario->available_scenarios[2] = 1;
    scenario->available_scenarios[3] = 0;

    // Decision 1: Study with friends or alone
    strcpy(scenario->decisions[0].question,"Would you like to join some classmates who are already studying in a room on the second floor, or study on your own?");
    
    // Option 1: Join classmates
    strcpy(scenario->decisions[0].options[0].response_text,"You decide to join your classmates.(1)");
    strcpy(scenario->decisions[0].options[0].pre_narrative, "You study and eat some cookies, but the janitor catches you.");
    createEnemy(&scenario->decisions[0].options[0].enemy,"Janitor","He wants to expel you",50,20,5);
    strcpy(scenario->decisions[0].options[0].post_narrative, "You manage to deal with the janitor and continue studying, earning some study points.");

    // Option 2: Study alone
    strcpy(scenario->decisions[0].options[1].response_text,"You decide to study alone.(2)");
    strcpy(scenario->decisions[0].options[1].pre_narrative, "You get distracted by YouTube videos.");
    createEnemy(&scenario->decisions[0].options[1].enemy,"Youtube Video","Distraction",50,20,5);
    strcpy(scenario->decisions[0].options[1].post_narrative, "You resist the temptation and continue studying, earning some study points.");

    // Decision 2: A colleague needs help
    strcpy(scenario->decisions[1].question,"A colleague wants to copy your work. What will you do?");
    
    // Option 1: Help him
    strcpy(scenario->decisions[1].options[0].response_text,"You decide to help him.(1)");
    strcpy(scenario->decisions[1].options[0].pre_narrative, "The teacher detects plagiarism and demands an explanation.");
    createEnemy(&scenario->decisions[1].options[0].enemy,"Corrector","He wants to expel you",60,10,15);
    strcpy(scenario->decisions[1].options[0].post_narrative, "You manage to handle the situation and avoid trouble.");

    // Option 2: No help
    strcpy(scenario->decisions[1].options[1].response_text,"You decide not to help him(2).");
    strcpy(scenario->decisions[1].options[1].pre_narrative, "Your colleague gets angry and confronts you.");
    createEnemy(&scenario->decisions[1].options[1].enemy,"Colleague","He wants to confront you",35,20,25);
    strcpy(scenario->decisions[1].options[1].post_narrative, "You deal with the confrontation and continue studying peacefully.");
}

void createscenario3 (Scenario *scenario)
{
    strcpy(scenario->name, "Labs"); 
    strcpy(scenario->description, "The Labs room is where theory classes must come to practical use, and Mr. Bean will give you some pretty hard exercises.");

    // edges in graph (possible paths between scenarios)
    scenario->available_scenarios[0] = 1;
    scenario->available_scenarios[1] = 1;
    scenario->available_scenarios[2] = 0;
    scenario->available_scenarios[3] = 0;

    // Decision 1: Doing an exercise. Use ChatGPT or solve it alone
    strcpy(scenario->decisions[0].question, "You are doing an exercise. Do you want to use ChatGPT or solve it on your own?");

    // Option 1: Use ChatGPT
    strcpy(scenario->decisions[0].options[0].response_text, "You decide to use ChatGPT(1).");
    strcpy(scenario->decisions[0].options[0].pre_narrative, "The lab teacher notices and confronts you.");
    createEnemy(&scenario->decisions[0].options[0].enemy,"Lab teacher","He wants to expel you",70,10,5);
    strcpy(scenario->decisions[0].options[0].post_narrative, "You manage to explain your use of ChatGPT and avoid trouble, earning 5 academic credits.");

    // Option 2: Solve it alone
    strcpy(scenario->decisions[0].options[1].response_text, "You decide to solve it alone.(2)");
    strcpy(scenario->decisions[0].options[1].pre_narrative, "The exercise turns out to be very challenging.");
    createEnemy(&scenario->decisions[0].options[1].enemy,"Challenging exercise","He will finish you",60,10,15);
    strcpy(scenario->decisions[0].options[1].post_narrative, "You manage to solve it and impress the teacher, earning 5 academic credits.");

    // Decision 2: Teacher asks for a volunteer to solve in public
    strcpy(scenario->decisions[1].question, "The teacher asks for a volunteer to solve a problem in front of the class. What will you do?");

    // Option 1: Volunteer
    strcpy(scenario->decisions[1].options[0].response_text, "You decide to volunteer(1).");
    strcpy(scenario->decisions[1].options[0].pre_narrative, "A classmate doubts your solution and challenges you.");
    createEnemy(&scenario->decisions[1].options[0].enemy,"Classmate","He wants to challenge you",45,15,20);
    strcpy(scenario->decisions[1].options[0].post_narrative, "You defend your solution and gain respect, earning 5 academic credits.");

    // Option 2: Not volunteer
    strcpy(scenario->decisions[1].options[1].response_text, "You decide not to volunteer.(2)");
    strcpy(scenario->decisions[1].options[1].pre_narrative, "The teacher notices and calls on you anyway.");
    createEnemy(&scenario->decisions[1].options[1].enemy,"teacher","He wants to challenge you",60,10,15);
    strcpy(scenario->decisions[1].options[1].post_narrative, "You manage to solve the problem under pressure, earning 5 academic credits.");
}

void createscenario4 (Scenario *scenario)
{
    strcpy(scenario->name, "Final Exam"); 
    strcpy(scenario->description, "The time has come. This is your final Scenario, pass the exam and you will have won the game..Good luck!!");

    // edges in graph (possible paths between scenarios)
    scenario->available_scenarios[0] = 0;
    scenario->available_scenarios[1] = 0;
    scenario->available_scenarios[2] = 0;
    scenario->available_scenarios[3] = 0;

    // Decision 1: Choosing a seat. Next to a friend or next to a know-it-all
    strcpy(scenario->decisions[0].question, "You have to look for a seat. Choose wisely: next to a friend or next to a know-it-all.");

    // Option 1: Next to a friend
    strcpy(scenario->decisions[0].options[0].response_text, "You decide to sit next to a friend.(1)");
    strcpy(scenario->decisions[0].options[0].pre_narrative, "One of the teachers notices it and wants to sit you in another place. Defeat him if you want to maintain your seat.");
    createEnemy(&scenario->decisions[0].options[0].enemy,"Final exam teacher","He wants to sit you far from your friend",50,20,20);
    strcpy(scenario->decisions[0].options[0].post_narrative, "You manage to convince him that this will be your seat for the exam.");

    // Option 2: Next to a know-it-all
    strcpy(scenario->decisions[0].options[1].response_text, "You decide to sit next to a know-it-all.(2)");
    strcpy(scenario->decisions[0].options[1].pre_narrative, "He turns out to be a snitch and wants to tell the teacher. Silence him before he says anything!");
    createEnemy(&scenario->decisions[0].options[1].enemy,"Snitch","He wants to tell the teacher",60,15,20);
    strcpy(scenario->decisions[0].options[1].post_narrative, "You manage to silence him, and you can keep your seat.");

    // Decision 2: The exam is very difficult. Use cheat notes or solve it with what you have studied
    strcpy(scenario->decisions[1].question, "You are presented the final exam and it's very difficult. Would you like to try to look at your cheat notes or solve it with what you have studied?");

    // Option 1: Cheat notes
    strcpy(scenario->decisions[1].options[0].response_text, "You decide to look at your cheat notes.(1)");
    strcpy(scenario->decisions[1].options[0].pre_narrative, "The teacher sees it and wants to grab your exam. You will have to fight him if you want to pass.");
    createEnemy(&scenario->decisions[1].options[0].enemy,"Mr. Taixas","He will grab your exam if you don't defeat him",80,15,5);
    strcpy(scenario->decisions[1].options[0].post_narrative, "You defeated him and you have passed your first semester at this university. Congratulations!");

    // Option 2: Try to solve it on your own
    strcpy(scenario->decisions[1].options[1].response_text, "You decide to do it on your own.(2)");
    strcpy(scenario->decisions[1].options[1].pre_narrative, "The exam is really difficult.");
    createEnemy(&scenario->decisions[1].options[1].enemy,"Final Exam","It will make you fail",80,15,5);
    strcpy(scenario->decisions[1].options[1].post_narrative, "You manage to solve the exam and you have survived your first semester at UPF. Congrats!");
}


void createSkills(Skill *skills){
    //first skill
    strcpy(skills[0].name,"Laptop shield");
    strcpy(skills[0].description," You bought a laptop that gives you some knwoledge and this protect you from the rest.10 points extra of hp");
    skills[0].duration = 1;
    skills[0].type = SINGLE_ROUND_MODIFIER;
    skills[0].hpmodifier = 15;
    skills[0].atkmodifier = 0;
    skills[0].DEFmodifier= 0;
    // second skill
    strcpy(skills[1].name,"Mr. Taixas particular classes");
    strcpy(skills[1].description,"You had some particular classes from a good teacher and he gave you wisedom. You earn 10 points of attack for 4 rounds");
    skills[1].duration = 4;
    skills[1].type = MULTIPLE_ROUND_MODIFIER;
    skills[1].hpmodifier = 0;
    skills[1].atkmodifier = 10;
    skills[1].DEFmodifier= 0;
    // third skill
    strcpy(skills[2].name,"Sharp Pen");
    strcpy(skills[2].description,"This pen can be used once to stab your opponent, giving a huge attack bonus.");
    skills[2].duration = 1;
    skills[2].type = SINGLE_ROUND_MODIFIER;
    skills[2].hpmodifier = 0;
    skills[2].atkmodifier = 10;
    skills[2].DEFmodifier= 0;

    strcpy(skills[3].name,"C++ tutorial");
    strcpy(skills[3].description,"You watched a c++ tutorial on youtube that permits you to produce more damage");
    skills[3].duration = 1;
    skills[3].type = SINGLE_ROUND_MODIFIER;
    skills[3].hpmodifier = 0;
    skills[3].atkmodifier = 15;
    skills[3].DEFmodifier= 0;

    strcpy(skills[4].name,"Chat GPT");
    strcpy(skills[4].description,"For 4 rounds, the use of Chat GPT is allowed so you earn some defense skills");
    skills[4].duration = 4;
    skills[4].type = MULTIPLE_ROUND_MODIFIER;
    skills[4].hpmodifier = 0;
    skills[4].atkmodifier = 15;
    skills[4].DEFmodifier= 0;

    strcpy(skills[5].name,"Coffe from the cafeteria");
    strcpy(skills[5].description,"These coffe is so good it gives you 15 extra hp points");
    skills[5].duration = 1;
    skills[5].type = SINGLE_ROUND_MODIFIER;
    skills[5].hpmodifier = 15;
    skills[5].atkmodifier = 0;
    skills[5].DEFmodifier= 0;

    strcpy(skills[6].name,"The magical book");
    strcpy(skills[6].description,"This book has everything you need: 5 extra points in hp, deffense and attack. FOR 10 ROUNDS!!");
    skills[6].duration = 10;
    skills[6].type = MULTIPLE_ROUND_MODIFIER;
    skills[6].hpmodifier = 5;
    skills[6].atkmodifier = 5;
    skills[6].DEFmodifier= 5;

    strcpy(skills[7].name,"Group of friends");
    strcpy(skills[7].description,"Your friends will help you defeat the enemies.You have 20 extra points in defense ");
    skills[7].duration = 4;
    skills[7].type = MULTIPLE_ROUND_MODIFIER;
    skills[7].hpmodifier = 0;
    skills[7].atkmodifier = 15;
    skills[7].DEFmodifier= 0;


    strcpy(skills[8].name, "Library Research");
    strcpy(skills[8].description, "Spending time in the library gives you insights and boosts your knowledge. 10 extra points in attack for 2 rounds.");
    skills[8].duration = 1;
    skills[8].type = SINGLE_ROUND_MODIFIER;
    skills[8].hpmodifier = 0;
    skills[8].atkmodifier = 5;
    skills[8].DEFmodifier = 0;

    strcpy(skills[9].name, "Late Night Study");
    strcpy(skills[9].description, "Studying all night increases your focus and endurance. 5 extra points in defense and 10 extra points in HP for 3 rounds.");
    skills[9].duration = 1;
    skills[9].type = SINGLE_ROUND_MODIFIER;
    skills[9].hpmodifier = 10;
    skills[9].atkmodifier = 0;
    skills[9].DEFmodifier = 5;

    strcpy(skills[10].name, "Professor's Office Hours");
    strcpy(skills[10].description, "Getting advice from a professor boosts your confidence. 10 extra points in attack for 1 round.");
    skills[10].duration = 1;
    skills[10].type = SINGLE_ROUND_MODIFIER;
    skills[10].hpmodifier = 0;
    skills[10].atkmodifier = 10;
    skills[10].DEFmodifier = 0;

    strcpy(skills[11].name, "Group Study Session");
    strcpy(skills[11].description, "Studying with friends gives you different perspectives and enhances your defense. 5 extra points in defense for 5 rounds.");
    skills[11].duration = 1;
    skills[11].type = SINGLE_ROUND_MODIFIER;
    skills[11].hpmodifier = 0;
    skills[11].atkmodifier = 0;
    skills[11].DEFmodifier = 5;

    strcpy(skills[12].name, "Campus Gym Workout");
    strcpy(skills[12].description, "Regular workouts increase your strength. 5 extra points in attack and 5 extra points in defense for 4 rounds.");
    skills[12].duration = 1;
    skills[12].type = SINGLE_ROUND_MODIFIER;
    skills[12].hpmodifier = 0;
    skills[12].atkmodifier = 5;
    skills[12].DEFmodifier = 5;

    strcpy(skills[13].name, "Healthy Cafeteria Meal");
    strcpy(skills[13].description, "Eating a balanced meal at the cafeteria gives you extra energy. 15 extra points in HP for 1 round.");
    skills[13].duration = 1;
    skills[13].type = SINGLE_ROUND_MODIFIER;
    skills[13].hpmodifier = 15;
    skills[13].atkmodifier = 0;
    skills[13].DEFmodifier = 0;

    strcpy(skills[14].name, "Extra Credit Assignment");
    strcpy(skills[14].description, "Completing an extra credit assignment boosts your overall performance. 10 extra points in HP and defense for 3 rounds.");
    skills[14].duration = 1;
    skills[14].type = SINGLE_ROUND_MODIFIER;
    skills[14].hpmodifier = 10;
    skills[14].atkmodifier = 0;
    skills[14].DEFmodifier = 10;

    strcpy(skills[15].name, "Campus Tour");
    strcpy(skills[15].description, "Exploring the campus helps you find hidden resources. 10 extra points in HP and 5 extra points in attack for 2 rounds.");
    skills[15].duration = 1;
    skills[15].type = SINGLE_ROUND_MODIFIER;
    skills[15].hpmodifier = 10;
    skills[15].atkmodifier = 5;
    skills[15].DEFmodifier = 0;

}
void waitForKey()
{
    int c;
    printf("Press Enter to continue...");
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

bool isInList(int chosenSkills[YOUR_SKILLS], int comptaration){
    for (int i=0; i < YOUR_SKILLS; i++){
        if (chosenSkills[i] == comptaration){
            return true;
        }
    }
    return false;
}
void chooseSkills(Character *character, Skill *skills) {
    // Declare an array to store chosen skills
    int chosenSkills[YOUR_SKILLS] = {-1,-1,-1,-1};

    // Display the available skills and prompt the player to choose
    printf("Choose 4 skills from the available list:\n");
    for (int i = 0; i < OPT_SKILLS; ++i) {
        printf("\n");
        printf("%d. %s: %s\n", i + 1, skills[i].name, skills[i].description);
    }
    printf("\nEnter the numbers corresponding to the skills: \n");
   
    // Store chosen skills in the character's skills array
    int option;
    for (int i=0; i < YOUR_SKILLS; i++){
        while(true){
            if (scanf("%d", &option) != 1) { // verifies if the input isn't a number
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n'); // CLeans the enter buffer 
                } 
            else if(option > 0 && option <= OPT_SKILLS && !isInList(chosenSkills, option)) {
                chosenSkills[i] = option;
                character->skills[i] = &(skills[chosenSkills[i] - 1]);
                break;
                } 
            else{
                if(isInList(chosenSkills, option)){
                    printf("Skill already choosen! Please select another one \n");
                }
                else{
                printf("The skill selected dosn't exist!. Please select another one \n");
                }
                }
            }
        }       
}




void personalizeCharacter(Character *character,Skill skills[MAX_SKILLS]) {
    // Declare a character structure
    
    printf("Hello student... We have been waiting for you.\n");
    printf("Please enter your students name:\n");

    // Prompt the player to enter their name
    scanf("%s",&character->name);
    printf("Hello %s, are you ready for this first semester in UPF?\n ",character->name);
    
    // Initialize attributes with default values
    character->hp = 0;
    character->atk = 0;
    character->def = 0;
    character->credits = 0;
    character->weeks = 3;

    printf("You will first have to choose the stats you want to start with \n");
    // Distribute 100 points between life, attack, and defense
    printf("You have 90 points to distribute between life, attack, and defense. Choose wisely!!.\n");
    do {
        printf("Points for life: ");
        scanf("%d", &(character->hp));
        printf("Points for attack: ");
        scanf("%d", &(character->atk));
        printf("Points for defense: ");
        scanf("%d", &(character->def));
        if (character->hp + character->atk + character->def != 90) {
            printf("Total points must equal 90. Please redistribute points.\n");
        }
    } while (character->hp + character->atk + character->def != 90);
    printf("Perfect!! Now that you have your stats, lets choose the skills that will help you defeat your enemies.\n");

    
     // Create the available skills
    chooseSkills(character, skills);
 
    // Display the personalized character
    printf("\nPerfect!! This will be your character:\n");
    printf("Name: %s\n", character->name);
    printf("Life: %d\n", character->hp);
    printf("Attack: %d\n", character->atk);
    printf("Defense: %d\n", character->def);
    printf("Skills: \n");
   for (int i = 0; i < MAX_SKILLS; ++i) {
        if (character->skills[i] != NULL) {
            printf("%d. %s: %s\n", i + 1, character->skills[i]->name,character->skills[i]->description);
            
        }
    }
    
   
}

int choose_scenario(Scenario scenarios[MAX_SCENARIOS], int actual_position) {
    int option;

    if (actual_position == 0) {
        printf("Choose the scenario you want to play:\n");
        printf("2. Library\n");
        printf("3. Lab Class\n");
        printf("Enter the number of the scenario you want to choose: ");
        scanf("%d", &option);
        
        if (option == 2 || option == 3) {
            return option - 1; // Return the correct index (1 for Library, 2 for Lab Class)
        } else {
            printf("Invalid choice! Please enter 2 or 3.\n");
            return choose_scenario(scenarios, actual_position); // Retry if invalid choice
        }
    } else if (actual_position == 1) {
        printf("Choose the scenario you want to play:\n");
        printf("3. Lab Class\n");
        option = 3;
        return option - 1; // Return the correct index (2 for Lab Class)
    }

    return -1; // This should never be reached
}
        
int choose_option(){
    char option;
    printf("What will you to do? \n");
    while (true){
        scanf("%s",&option);
        switch (option) {
            case '1':
                return 0;
                break;
            case '2':
                return 1;
                break;   
            default:
                printf("Invalid choice! Please enter a number (1 or 2).\n");
        }
    }
}

int options(Decision decision){
    int num_options = sizeof(decision.options) / sizeof(decision.options[0]); // number of options in decision
    for (int i = 0; i < num_options; i++) {
        printf("%s \n",decision.options[i].response_text);
    }
    return choose_option();
}

bool fight(Character *character, Enemy *enemy){
    return true;
}

void in_Scenario(Character *character, Scenario *scenario,Skill *skills){
    for (int i = 0; i < MAX_DECISION; i++) {       // iterate through the decisions in the scenario, one after another.
        printf("%s \n",scenario->decisions[i].question);
        int chosen_option = options(scenario->decisions[i]);
        printf("%s \n",scenario->decisions[i].options[chosen_option].pre_narrative);
        printf("The fight starts!!");
        Enemy *enemy = &scenario->decisions[i].options[chosen_option].enemy;
        combat(character,enemy,skills);
        if(combat == false){
            printf("You lost the fight. You have lost a week. \n");
            printf(" ▄▀▀▀▀▄    ▄▀▀█▄   ▄▀▀▄ ▄▀▄  ▄▀▀█▄▄▄▄      ▄▀▀▀▀▄   ▄▀▀▄ ▄▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄\n");
            printf("█         ▐ ▄▀ ▀▄ █  █ ▀  █ ▐  ▄▀   ▐     █      █ █   █    █ ▐  ▄▀   ▐ █   █   █\n");
            printf("█    ▀▄▄    █▄▄▄█ ▐  █    █   █▄▄▄▄▄      █      █ ▐  █    █    █▄▄▄▄▄  ▐  █▀▀█▀ \n");
            printf("█     █ █  ▄▀   █   █    █    █    ▌      ▀▄    ▄▀    █   ▄▀    █    ▌   ▄▀    █ \n");
            printf("▐▀▄▄▄▄▀ ▐ █   ▄▀  ▄▀   ▄▀    ▄▀▄▄▄▄         ▀▀▀▀       ▀▄▀     ▄▀▄▄▄▄   █     █  \n");
            printf("▐         ▐   ▐   █    █     █    ▐                            █    ▐   ▐     ▐  \n");
            printf("                  ▐    ▐     ▐                                 ▐                  \n");

            break;;
        }
        printf("%s \n",scenario->decisions[i].options[chosen_option].post_narrative);
    }
    printf("Good job! You defeated all the enemies in %s. \n", scenario->name);
}

void Game(Character *character, Scenario *scenarios[MAX_SCENARIOS], Skill *skills){
    
    int option = 0; 
    // first obligatory scenario
    //int actual_scenario = option;
    Scenario *current_scenario = scenarios[option];
    printf("You're first scenario is the %s \n",current_scenario->name);
    printf("%s\n",current_scenario->description);
    in_Scenario(character , current_scenario,skills);
    character->weeks--;
    printf("You have %d weeks left. \n",character->weeks);    
    
    while(character->weeks > 1){
        printf("Hello %s, You survived the last  scenario.You can choose now the next  scenarios.\n Choose wisely! \n",character->name);
        int option = choose_scenario(*scenarios, option);
        Scenario *current_scenario = scenarios[option];
        printf("You have chosen the %s\n",current_scenario->name);
        printf("%s",current_scenario->description);
        in_Scenario(character,current_scenario,skills);
        character->weeks--;
        printf("You have %d weeks left. \n",character->weeks);
    }
    printf("  █████▒██▓ ███▄    █  ▄▄▄       ██▓       ▓█████ ▒██   ██▒ ▄▄▄       ███▄ ▄███▓\n");
    printf("▓██   ▒▓██▒ ██ ▀█   █ ▒████▄    ▓██▒       ▓█   ▀ ▒▒ █ █ ▒░▒████▄    ▓██▒▀█▀ ██▒\n");
    printf("▒████ ░▒██▒▓██  ▀█ ██▒▒██  ▀█▄  ▒██░       ▒███   ░░  █   ░▒██  ▀█▄  ▓██    ▓██░\n");
    printf("░▓█▒  ░░██░▓██▒  ▐▌██▒░██▄▄▄▄██ ▒██░       ▒▓█  ▄  ░ █ █ ▒ ░██▄▄▄▄██ ▒██    ▒██ \n");
    printf("░▒█░   ░██░▒██░   ▓██░ ▓█   ▓██▒░██████▒   ░▒████▒▒██▒ ▒██▒ ▓█   ▓██▒▒██▒   ░██▒\n");
    printf(" ▒ ░   ░▓  ░ ▒░   ▒ ▒  ▒▒   ▓▒█░░ ▒░▓  ░   ░░ ▒░ ░▒▒ ░ ░▓ ░ ▒▒   ▓▒█░░ ▒░   ░  ░\n");
    printf(" ░      ▒ ░░ ░░   ░ ▒░  ▒   ▒▒ ░░ ░ ▒  ░    ░ ░  ░░░   ░▒ ░  ▒   ▒▒ ░░  ░      ░ \n");
    printf(" ░ ░    ▒ ░   ░   ░ ░   ░   ▒     ░ ░         ░    ░    ░    ░   ▒   ░      ░    \n");
    printf("        ░           ░       ░  ░    ░  ░      ░  ░ ░    ░        ░  ░       ░    \n");  

    Scenario *final_scenario = scenarios[3];
    printf("You're last scenario is the %s \n",final_scenario->name);
    printf("%s\n",final_scenario->description);
    in_Scenario(character , final_scenario,skills);
    return;
       
    

}

void tutorial(){
    printf("Tutorial");
    return;
}

void introduction_narrative(Character *character){
    printf("You are a new student from UPF, the main objective is to pass the final exam that you will have in 3 weeks,to be able to arrive at the exam\nyou will first have to reach  30 academic credits.You will earn those credits by defeating you enemies. Good luck in your journey!!\n");
    
}


void new_game(){
    int choice;
    Character *character = calloc(1,sizeof(Character));
    Scenario *scenario1 = (Scenario*) malloc(sizeof(Scenario));
    Scenario *scenario2 = (Scenario*) malloc(sizeof(Scenario));
    Scenario *scenario3 = (Scenario*) malloc(sizeof(Scenario));
    Scenario *scenario4 = (Scenario*) malloc(sizeof(Scenario));

    Skill skills[MAX_SKILLS];
    createSkills(skills);
    personalizeCharacter(character,skills); //personalize character, createskills, chooseskills
    introduction_narrative(character); 
    createscenario1(scenario1);
    createscenario2(scenario2);
    createscenario3(scenario3);
    createscenario4(scenario4);
    Scenario *scenarios[MAX_SCENARIOS] = { scenario1, scenario2, scenario3, scenario4};
    Game(character,scenarios,skills);
}

void print_menu()
{
    int choice;
    do {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Tutorial\n");
        printf("2.New game\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1:
                tutorial();
                break;
            case 2:
                new_game();
                break;   
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 3.\n");
        }
    } while (choice != 3);

    
}

int main()
{
    printf("██████╗  ██████╗ ███╗   ███╗██████╗ ███████╗██╗   ██╗\n");
    printf("██╔══██╗██╔═══██╗████╗ ████║██╔══██╗██╔════╝██║   ██║\n");
    printf("██████╔╝██║   ██║██╔████╔██║██████╔╝█████╗  ██║   ██║\n");
    printf("██╔═══╝ ██║   ██║██║╚██╔╝██║██╔═══╝ ██╔══╝  ██║   ██║\n");
    printf("██║     ╚██████╔╝██║ ╚═╝ ██║██║     ███████╗╚██████╔╝\n");
    printf("╚═╝      ╚═════╝ ╚═╝     ╚═╝╚═╝     ╚══════╝ ╚═════╝\n");
    printf("\n");
    printf("██╗  ██╗███████╗██████╗  ██████╗ ███████╗███████╗\n");
    printf("██║  ██║██╔════╝██╔══██╗██╔═══██╗██╔════╝██╔════╝\n");
    printf("███████║█████╗  ██████╔╝██║   ██║█████╗  ███████╗\n");
    printf("██╔══██║██╔══╝  ██╔══██╗██║   ██║██╔══╝  ╚════██║\n");
    printf("██║  ██║███████╗██║  ██║╚██████╔╝███████╗███████║\n");
    printf("╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚══════╝\n");

    print_menu();
    return 0;
}