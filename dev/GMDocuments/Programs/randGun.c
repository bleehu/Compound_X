/*======================================
 * Random Weapon Generator for Compound X
 *====================================*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define LEVEL 10//specify either 0, 5, 10, 15 or 20 for appropriate
                //scaling with enemy strength

//Gun Types to be stored in stat[0]
#define PISTOL 0
#define SMG 1
#define SHOTGUN 2
#define CARBINE 3
#define AUTOMATIC 4
#define HEAVY 5
#define LONG_RIFLE 6

//stats in the stat array
#define TYPE 0
#define RANGE 1
#define MISS 2
#define CAPACITY 3
#define DAMAGE 4
#define FIRE_TYPE 5
#define COST 6

//Firetypes
#define SINGLEFIRE 0
#define SEMI_AUTO 1
#define FULL_AUTO 2

 int main () {
    printf("Running Weapon Generator Version A_1.1\n");

    time_t t;
    srand((unsigned) time(&t));

    char* wepType = malloc(sizeof(char)*15);

    //6 price; 0 Type; 1 range; 2 percent miss; 3 rds/mag; 4 damage;
    //5 fire type: {0 = bolt/pump, 1 = semi-auto., 2 = fully auto.}
    int* stats = malloc(sizeof(int) * 7);
    int i = 0;
    for (i = 0; i < 7; i++) {
        stats[i] = 0;
    }

    //Each weapon type should have an equal liklihood of being
    //generated, so we have 7 "type" outcomes. based on what "type"
    //it is, we generate different values for most of the stats.
    stats[TYPE] = rand()%7;


    //determine range, 1
    if (stats[TYPE] == PISTOL) {//Pistol
        stats[RANGE] = (5 * (rand() % 6)) + 30 + (LEVEL*2); //30-55 base
    } else if (stats[TYPE] == SMG) {//SMG
        stats[RANGE] = (5 * (rand() % 8)) + 45 + (LEVEL*2); //45-80 base
    } else if (stats[TYPE] == SHOTGUN) {//Shotgun
        stats[RANGE] = 20 + LEVEL;//20 base
    } else if (stats[TYPE] == CARBINE) {//Carbines/BRs
        stats[RANGE] = (5 * (rand() % 16)) + 75 + (LEVEL*4); //75-150 base
    } else if (stats[TYPE] == AUTOMATIC) {//Automatic Rifles
        stats[RANGE] = (5 * (rand() % 11)) + 80 + (LEVEL*4); //80-130 base
    } else if (stats[TYPE] == HEAVY) {//Heavy Weapons
        //50-200 base
        int raw = rand() % 12;
        if (raw > 5) {
            raw *= 10;
            raw += 80;
        } else {
            raw *= 5;
            raw += 50;
        }
        stats[RANGE] = raw + (3 * LEVEL);
    } else if (stats[TYPE] == LONG_RIFLE) {//Long Rifles
        stats[RANGE] = (5 * (rand() % 7)) + 30 + (LEVEL*15); //150-500 base
    }
    

    //determine percent miss, 2
    stats[MISS] = (rand()%(30 - LEVEL));

    //Determine fire type, 5; 0 single, 1 semi, 2 full
    if (stats[TYPE] == PISTOL) {//Pistol
        stats[FIRE_TYPE] = rand()%2;
    } else if (stats[TYPE] == SMG) {//Smg
        stats[FIRE_TYPE] = FULL_AUTO;
    } else if (stats[TYPE] == SHOTGUN) { //Shotgun
        stats[FIRE_TYPE] = rand()%2;
    } else if (stats[TYPE] == CARBINE) {//Carbine
        stats[FIRE_TYPE] = SINGLEFIRE; 
    } else if (stats[TYPE] == AUTOMATIC) {//Assault Rifle
        stats[FIRE_TYPE] = FULL_AUTO;
    } else if (stats[TYPE] == HEAVY) {//Heavy Weapon
        stats[FIRE_TYPE] = rand()%3;
    } else if (stats[TYPE] == LONG_RIFLE) {//Long Rifle
        stats[FIRE_TYPE] = rand()%2;
    }

    //determine capacity, 3
    if (stats[TYPE] == PISTOL) {//Pistol
        if (stats[FIRE_TYPE]) {
            stats[CAPACITY] = rand()%10 + 7;
        } else {
            stats[CAPACITY] = rand()%3 + 5;
        }
    } else if (stats[TYPE] == SMG) {//Smg
        stats[CAPACITY] = (5*rand()%3)+25;
    } else if (stats[TYPE] == SHOTGUN) { //Shotgun
        int cap = rand()%3;
        if (cap == 0) {
            stats[CAPACITY] = 5;
        } else if (cap == 1) {
            stats[CAPACITY] = 6;
        } else {
            stats[CAPACITY] = 7;
        }
    } else if (stats[TYPE] == CARBINE) {//Carbine
        stats[CAPACITY] = (5*rand()%3)+15;
    } else if (stats[TYPE] == AUTOMATIC) {//Assault Rifle
        stats[CAPACITY] = (5*rand()%3)+25;
    } else if (stats[TYPE] == HEAVY) {//Heavy Weapon
        stats[CAPACITY] = (5*rand()%3)+25;
    } else if (stats[TYPE] == LONG_RIFLE) {//Long Rifle
        stats[CAPACITY] = (rand()%10)+5;
    }

    //Determine Damage, 4
    //30, 35, 41, 43, 44, 46, 47, 52, 56, 60
    //60, 75, 90, 50, 55, 56, 57
    //62, 68, 70, 95, 115, 74, 85

    int damType;
    if (stats[TYPE] == 0 || stats[TYPE] == 1) {//Pistol & SMG
        damType = rand()%10;
        switch (damType) {
            case 0:
                stats[DAMAGE] = 30;
            break;
            case 1:
                stats[DAMAGE] = 35;
            break;
            case 2:
                stats[DAMAGE] = 41;
            break;
            case 3:
                stats[DAMAGE] = 43;
            break;
            case 4:
                stats[DAMAGE] = 44;
            break;
            case 5:
                stats[DAMAGE] = 46;
            break;
            case 6:
                stats[DAMAGE] = 47;
            break;
            case 7:
                stats[DAMAGE] = 52;
            break;
            case 8:
                stats[DAMAGE] = 56;
            break;
            case 9:
                stats[DAMAGE] = 60;
            break;
        }
    } else if (stats[TYPE] == SHOTGUN) {//Shotgun
        stats[DAMAGE] = 80;
    } else if (stats[TYPE] == CARBINE || stats[TYPE] == AUTOMATIC) {//Carbine / BR & Automatic Rifles
        damType = rand()%7;
        switch (damType) {
            case 0:
                stats[DAMAGE] = 60;
            break;
            case 1:
                stats[DAMAGE] = 75;
            break;
            case 2:
                stats[DAMAGE] = 90;
            break;
            case 3:
                stats[DAMAGE] = 50;
            break;
            case 4:
                stats[DAMAGE] = 55;
            break;
            case 5:
                stats[DAMAGE] = 56;
            break;
            case 6:
                stats[DAMAGE] = 57;
            break;
        }
    } else if (stats[TYPE] == HEAVY) {//Heavy Weapon
        stats[TYPE] = 0;
    } else if (stats[TYPE] == LONG_RIFLE) {//Long Rifle
        damType = rand()%7;
        switch (damType) {
            case 0:
                stats[DAMAGE] = 62;
            break;
            case 1:
                stats[DAMAGE] = 68;
            break;
            case 2:
                stats[DAMAGE] = 70;
            break;
            case 3:
                stats[DAMAGE] = 95;
            break;
            case 4:
                stats[DAMAGE] = 115;
            break;
            case 5:
                stats[DAMAGE] = 74;
            break;
            case 6:
                stats[DAMAGE] = 85;
            break;
        }
    }

    //Determine range, 6
    //Avg damage * range
    //Avg damage = (100-miss)/100*dam
    //6 price; 0 Type; 1 range; 2 percent miss; 3 rds/mag; 4 damage;
    //5 fire type: {0 = bolt/pump, 1 = semi-auto., 2 = fully auto.}
    double adjMiss = 100 - stats[MISS];
    double avgDam = (adjMiss/100)*stats[DAMAGE];
    stats[COST] = (stats[RANGE] * avgDam)/2;


    //Print off the stats
    //6 price; 0 Type; 1 range; 2 percent miss; 3 rds/mag; 4 damage;
    //5 fire type: {0 = bolt/pump, 1 = semi-auto., 2 = fully auto.}

    printf("Type: ");
    switch (stats[TYPE]) {
        case PISTOL:
            printf("Pistol");
        break;
        case SMG:
            printf("SMG");
        break;
        case SHOTGUN:
            printf("Shotgun");
        break;
        case CARBINE:
            printf("Carbine / BR");
        break;
        case AUTOMATIC:
            printf("Automatic Rifle");
        break;
        case HEAVY:
            printf("Heavy Weapon");
        break;
        case LONG_RIFLE:
            printf("Long Rifle");
        break;
    }
    printf("\n");

    printf("Range: %d m\n", stats[RANGE]);
    printf("Percent Miss: %d%%\n",stats[MISS]);
    printf("Rounds: %d\n",stats[CAPACITY]);
    printf("Damage: %d\n",stats[DAMAGE]);
    printf("Fire-type: ");
    switch (stats[FIRE_TYPE]) {
        case SINGLEFIRE:
            printf("Single / Bolt");
        break;
        case SEMI_AUTO:
            printf("Semi-Auto");
        break;
        case FULL_AUTO:
            printf("Automatic");
        break;
    }
    printf("\n");
    printf("Price: $%d\n",stats[COST]);
 }