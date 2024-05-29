#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "common.h"

typedef struct{
    char name[MAX_CHAR];
    char description[MAX_DESC];
    int type;
    int duration;
    int hpmodifier;
    int atkmodifier;
    int DEFmodifier;
}Skill;

typedef struct{
    char name[MAX_CHAR];
    int hp;
    int atk;
    int def;
    int credits;
    int weeks;
    Skill *skills[MAX_SKILLS];
}Character;


typedef struct{
    char name[MAX_CHAR];
    char description[MAX_TEXT];
    int hp;
    int atk;
    int def;
    Skill skill;
}Enemy;

typedef struct{
    char response_text[MAX_TEXT];
    char pre_narrative[MAX_TEXT];
    char post_narrative[MAX_TEXT];
    Enemy enemy;
}Option;

typedef struct{
    char question[MAX_Q];
    int num_options; 
    Option options[MAX_OPT];
}Decision;

typedef struct{
    char name[MAX_CHAR];
    char description[MAX_DESC];
    Decision decisions[MAX_DECISION];
    int available_scenarios[MAX_SCENARIOS];
}Scenario;

#endif