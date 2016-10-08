/*======================================
 * Random Weapon Generator for Compound X
 *====================================*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define LEVEL 10//specify either 0, 5, 10, 15 or 20 for appropriate
                //scaling with enemy strength



 int main () {
    printf("Running Weapon Generator Version A_1.0\n");

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
    stats[0] = rand()%7;


    //determine range, 1
    if (stats[0] == 0) {//Pistol
        stats[1] = (5 * (rand() % 6)) + 30 + (LEVEL*2); //30-55 base
    } else if (stats[0] == 1) {//SMG
        stats[1] = (5 * (rand() % 8)) + 45 + (LEVEL*2); //45-80 base
    } else if (stats[0] == 2) {//Shotgun
        stats[1] = 20 + LEVEL;//20 base
    } else if (stats[0] == 3) {//Carbines/BRs
        stats[1] = (5 * (rand() % 16)) + 75 + (LEVEL*4); //75-150 base
    } else if (stats[0] == 4) {//Automatic Rifles
        stats[1] = (5 * (rand() % 11)) + 80 + (LEVEL*4); //80-130 base
    } else if (stats[0] == 5) {//Heavy Weapons
        //50-200 base
        int raw = rand() % 12;
        if (raw > 5) {
            raw *= 10;
            raw += 80;
        } else {
            raw *= 5;
            raw += 50;
        }
        stats[1] = raw + (3 * LEVEL);
    } else if (stats[0] == 6) {//Long Rifles
        stats[1] = (5 * (rand() % 7)) + 30 + (LEVEL*15); //150-500 base
    }
    

    //determin percent miss, 2
    stats[2] = (rand()%(30 - LEVEL));

    //Determine fire type, 5; 0 single, 1 semi, 2 full
    if (stats[0] == 0) {//Pistol
        stats[5] = rand()%2;
    } else if (stats[0] == 1) {//Smg
        stats[5] = 2;
    } else if (stats[0] == 2) { //Shotgun
        stats[5] = rand()%2;
    } else if (stats[0] == 3) {//Carbine
        stats[5] = 1; 
    } else if (stats[0] == 4) {//Assault Rifle
        stats[5] = 2;
    } else if (stats[0] == 5) {//Heavy Weapon
        stats[5] = rand()%3;
    } else if (stats[0] == 6) {//Long Rifle
        stats[5] = rand()%2;
    }

    //determine capacity, 3
    if (stats[0] == 0) {//Pistol
        if (stats[5]) {
            stats[3] = rand()%10 + 7;
        } else {
            stats[3] = rand()%3 + 5;
        }
    } else if (stats[0] == 1) {//Smg
        stats[3] = (5*rand()%3)+25;
    } else if (stats[0] == 2) { //Shotgun
        int cap = rand()%3;
        if (cap == 0) {
            stats[3] = 5;
        } else if (cap == 1) {
            stats[3] = 6;
        } else {
            stats[3] = 7;
        }
    } else if (stats[0] == 3) {//Carbine
        stats[3] = (5*rand()%3)+15;
    } else if (stats[0] == 4) {//Assault Rifle
        stats[3] = (5*rand()%3)+25;
    } else if (stats[0] == 5) {//Heavy Weapon
        stats[3] = (5*rand()%3)+25;
    } else if (stats[0] == 6) {//Long Rifle
        stats[3] = (rand()%10)+5;
    }

    //Determine Damage, 4
    //30, 35, 41, 43, 44, 46, 47, 52, 56, 60
    //60, 75, 90, 50, 55, 56, 57
    //62, 68, 70, 95, 115, 74, 85

    int damType;
    if (stats[0] == 0 || stats[0] == 1) {//Pistol & SMG
        damType = rand()%10;
        switch (damType) {
            case 0:
                stats[4] = 30;
            break;
            case 1:
                stats[4] = 35;
            break;
            case 2:
                stats[4] = 41;
            break;
            case 3:
                stats[4] = 43;
            break;
            case 4:
                stats[4] = 44;
            break;
            case 5:
                stats[4] = 46;
            break;
            case 6:
                stats[4] = 47;
            break;
            case 7:
                stats[4] = 52;
            break;
            case 8:
                stats[4] = 56;
            break;
            case 9:
                stats[4] = 60;
            break;
        }
    } else if (stats[0] == 2) {//Shotgun
        stats[4] = 80;
    } else if (stats[0] == 3 || stats[0] == 4) {//Carbine / BR & Automatic Rifles
        damType = rand()%7;
        switch (damType) {
            case 0:
                stats[4] = 60;
            break;
            case 1:
                stats[4] = 75;
            break;
            case 2:
                stats[4] = 90;
            break;
            case 3:
                stats[4] = 50;
            break;
            case 4:
                stats[4] = 55;
            break;
            case 5:
                stats[4] = 56;
            break;
            case 6:
                stats[4] = 57;
            break;
        }
    } else if (stats[0] == 5) {//Heavy Weapon
        stats[0] = 0;
    } else if (stats[0] == 6) {//Long Rifle
        damType = rand()%7;
        switch (damType) {
            case 0:
                stats[4] = 62;
            break;
            case 1:
                stats[4] = 68;
            break;
            case 2:
                stats[4] = 70;
            break;
            case 3:
                stats[4] = 95;
            break;
            case 4:
                stats[4] = 115;
            break;
            case 5:
                stats[4] = 74;
            break;
            case 6:
                stats[4] = 85;
            break;
        }
    }

    //Determine range, 6
    //Avg damage * range
    //Avg damage = (100-miss)/100*dam
    //6 price; 0 Type; 1 range; 2 percent miss; 3 rds/mag; 4 damage;
    //5 fire type: {0 = bolt/pump, 1 = semi-auto., 2 = fully auto.}
    double adjMiss = 100 - stats[2];
    double avgDam = (adjMiss/100)*stats[4];
    stats[6] = (stats[1] * avgDam)/2;


    //Print off the stats
    //6 price; 0 Type; 1 range; 2 percent miss; 3 rds/mag; 4 damage;
    //5 fire type: {0 = bolt/pump, 1 = semi-auto., 2 = fully auto.}

    printf("Type: ");
    switch (stats[0]) {
        case 0:
            printf("Pistol");
        break;
        case 1:
            printf("SMG");
        break;
        case 2:
            printf("Shotgun");
        break;
        case 3:
            printf("Carbine / BR");
        break;
        case 4:
            printf("Automatic Rifle");
        break;
        case 5:
            printf("Heavy Weapon");
        break;
        case 6:
            printf("Long Rifle");
        break;
    }
    printf("\n");

    printf("Range: %d m\n", stats[1]);
    printf("Percent Miss: %d%%\n",stats[2]);
    printf("Rounds: %d\n",stats[3]);
    printf("Damage: %d\n",stats[4]);
    printf("Fire-type: ");
    switch (stats[5]) {
        case 0:
            printf("Single / Bolt");
        break;
        case 1:
            printf("Semi-Auto");
        break;
        case 2:
            printf("Automatic");
        break;
    }
    printf("\n");
    printf("Price: $%d\n",stats[6]);
 }
 
 //===================================================================
//Copyright 2016 Taylor Rowland
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.
//===================================================================