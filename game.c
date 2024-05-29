#include "common.h"
#include "structures.h"
#include "combat.c"
#include "scenarios.c"
#include "skills.c"
#include "character.c"
#include "tutorial.c"











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
    printf("What will you  do? \n");
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
    
    while(character->weeks > 0){
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
