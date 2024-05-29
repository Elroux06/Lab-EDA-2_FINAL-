






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

