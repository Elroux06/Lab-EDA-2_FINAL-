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