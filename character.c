




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