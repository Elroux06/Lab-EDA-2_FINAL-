#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <windows.h> //for Sleep()

// for time (); rand() and srand()
#include <time.h> 
#include <stdlib.h> 
#define MAX_TURNS 10
#define MAX_CHAR 100
#define MAX_DECISION 2
#define MAX_DESC 5000
#define MAX_Q 1000
#define MAX_OPT 4
#define OPT_SKILLS 8
#define MAX_SKILLS 16
#define YOUR_SKILLS 4
#define MAX_TEXT 5000
#define MAX_ENEMIES 8
#define MAX_SCENARIOS 4
#define SINGLE_ROUND_MODIFIER 1 
#define MULTIPLE_ROUND_MODIFIER 2
#define DEF_TO_SUBSTRACT 3

/* THESE ARE THINGS NEEDED FOR FIGHT, WE NEED TO IMPLEMENT THEM WITH THE OTHER STUFF
const int MAX_SKILLS = 10; // Maximum number of skills a character can have
const int MAX_ACTIVE_SKILLS = 10; // Maximum number of active skills
const int MAX_NAME_LENGTH = 50; // Maximum length for character and skill names
const int QUEUE_SIZE = 2; // Size of the turn queue
*/ 

#endif
