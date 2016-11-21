/*=============================================================================
 * Quick Battle
 * This program allows for quick estimations of relative strength between a
 * player group and an enemy group, spitting out a percent success of the
 * player group. Players and Enemies are more or less treated as the same type
 * of entity, they both attack as often as possible to maximize damage per
 * turn.
 *===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define E_STATS 7
#define P_STATS 7

///int NUM_ENEMIES; for arguments?

void sleep (int time) {
    struct timespec req = {0};
    req.tv_sec = 0;
    req.tv_nsec = time * 1000000L;
    nanosleep(&req, (struct timespec *)NULL);
}

void initEnemies(int numEn, int** Enemies) {

    char* input = malloc(15 * sizeof(char));//will need later to check inputs
    int j;
    for (j = 0; j < numEn; j++) {
        printf("\nPlease only input numbers for the following Enemies:\n");
        printf("\nHealth? ");
        scanf("%d", &Enemies[j][0]);
        printf("\nDR? ");
        scanf("%d", &Enemies[j][1]);
        printf("\nArmour %%? ");
        scanf("%d", &Enemies[j][2]);
        printf("\nDamage? ");
        scanf("%d", &Enemies[j][3]);
        printf("\nMiss %%? ");
        scanf("%d", &Enemies[j][4]);
        printf("\nCover Bonus (0/25/50)? ");
        scanf("%d", &Enemies[j][5]);
        printf("\nHunkered (0/25)? ");
        scanf("%d", &Enemies[j][6]);
        
        /*printf("\nHealth? 100");
        Enemies[j][0] = 100;
        printf("\nDR? 30");
        Enemies[j][1] = 30;
        printf("\nArmour %%? 35");
        Enemies[j][2] = 35;
        printf("\nDamage? 57");
        Enemies[j][3] = 57;
        printf("\nMiss %%? 30");
        Enemies[j][4] = 30;
        printf("\nCover Bonus (0/25/50)? 0");
        Enemies[j][5] = 0;
        printf("\nHunkered (0/25)? 0");
        Enemies[j][6] = 0;
        printf("\n");*/
    }
    printf("\n");

    free(input);
}

void initPlayers(int numPlay, int** Players) {
    char* input = malloc(15 * sizeof(char));//will need later to check inputs
    int j;
    for (j = 0; j < numPlay; j++) {
        printf("\nPlease only input numbers for the following Players:\n");
        printf("\nHealth? ");
        scanf("%d", &Players[j][0]);
        printf("\nDR? ");
        scanf("%d", &Players[j][1]);
        printf("\nArmour %%?");
        scanf("%d", &Players[j][2]);
        printf("\nDamage? ");
        scanf("%d", &Players[j][3]);
        printf("\nMiss %%? ");
        scanf("%d", &Players[j][4]);
        printf("\nCover Bonus (0/25/50)? ");
        scanf("%d", &Players[j][5]);
        printf("\nHunkered (0/25)? ");
        scanf("%d", &Players[j][6]);
        
        /*printf("\nHealth? 120");
        Players[j][0] = 120;
        printf("\nDR? 35");
        Players[j][1] = 35;
        printf("\nArmour %%? 60");
        Players[j][2] = 60;
        printf("\nDamage? 50");
        Players[j][3] = 50;
        printf("\nMiss %%? 15");
        Players[j][4] = 15;
        printf("\nCover Bonus (0/25/50)? 0");
        Players[j][5] = 0;
        printf("\nHunkered (0/25)? 0");
        Players[j][6] = 0;
        printf("\n");*/
    }
    printf("\n");
    free(input);
}


void report (int* results, int numEn, int numPlay, int** Enemies, int** Players) {
    int x;
    printf("Results:\n");
    printf("Remaining Players: %d\n", results[1]);
    for (x = 0; x < numPlay; x++) {
        if (Players[x][0] > 0) {
            printf("Player %d: %d HP\n", x+1, Players[x][0]);
        }
    }
    printf("Remaining Enemies: %d\n", results[0]);
    for (x = 0; x < numEn; x++) {
        if (Enemies[x][0] > 0) {
            printf("Enemy %d: %d HP\n", x+1, Enemies[x][0]);
        }
    }
}

//takes 3 integers: Target, Miss chance, Damage.
//The function randomly attacks the target, dealing Damage to them
//based on the provided Miss chance; if the random value out of 100
//is greater than the miss chance, the target is hit.
int pAttack (int aTarget, int aMiss, int aDamage) {
    int toReturn = 0;
    
    return toReturn;
}

//randomly do things. Members will usually Aim and then fire as many
//times as they can.
void Turn (int group, int member) {
    //4 half actions
    int i;
    
}


//prints the status of all objects in the battle.
void printStats () {


}

int getValue(int** memList, int mem, int stat) {
    return memList[stat][mem];
}

int qBattle (int numEn, int numPlay, int** Enemies, int** Players) {

    int enAli = numEn;//Alive Enemies
    int plAli = numPlay;//Alive Players
    //randomly decide if players of enemies go first
    int order = rand()%2;
    //TODO replace with full initiative list
    
    int turn = 1;
    while (enAli > 0 && plAli > 0 && turn < 100) {
        turn++;

        int m,n;
        int target = 0;
        int count = 0;
        if (order == 1) {
            //Players
            for (m = 0; m < numPlay; m++) {//Each Player's Turn
                if (Players[m][0] > 0) {
                    int action;
                    for (action = 0; action < 4; action++) {
                        if (action > 0) {
                            count = 0;
                            do {
                                target = rand()%numEn;
                                count++;
                            } while (Enemies[target][0] <= 0 && count < 3*numEn);
                            if (rand()%100+1 > Players[m][4] + Enemies[target][5] && Enemies[target][0] > 0) {
                                if (rand()%100+1 > Enemies[target][2]) {//roll to see if it hits armour
                                    //if the roll is greater than armour%, deal full damage
                                    Enemies[target][0] -= (Players[m][3]);
                                } else {
                                    //else we will reduce the damage by the enemy's DR
                                    Enemies[target][0] -= (Players[m][3] - Enemies[target][1]);
                                }
                                if (Enemies[target][0] <= 0) {
                                    enAli--;
                                }
                            }
                        }//End of Action
                    }//End of Turn
                }
            }
            //Enemies
            for (m = 0; m < numEn; m++) {//Each Enemy's turn
                if (Enemies[m][0] > 0) {
                    int action;
                    for (action = 0; action < 4; action++) {
                        if (action > 0) {
                            count = 0;
                            do {
                                target = rand()%numPlay;
                                count++;
                            } while (Players[target][0] <= 0 && count < 3*numPlay);
                            if (rand()%100+1 > Enemies[m][4] + Players[target][5] && Players[target][0] > 0) {
                                if (rand()%100+1 > Players[target][2]) {//roll to see if it hits armour
                                    //if the roll is greater than armour%, deal full damage
                                    Players[target][0] -= (Enemies[m][3]);
                                } else {
                                    //else we will reduce the damage by the enemy's DR
                                    Players[target][0] -= (Enemies[m][3] - Players[target][1]);
                                }
                                if (Players[target][0] <= 0) {
                                    plAli--;
                                }
                            }
                        }//End of Action
                    }//End of Turn
                }
            }
        } else {
            //Enemies
            for (m = 0; m < numEn; m++) {//Each Enemy's turn
                if (Enemies[m][0] > 0) {
                    int action;
                    for (action = 0; action < 4; action++) {
                        if (action > 0) {
                            count = 0;
                            do {
                                target = rand()%numPlay;
                                count++;
                            } while (Players[target][0] <= 0 && count < 3*numPlay);
                            if (rand()%100+1 > Enemies[m][4] + Players[target][5] && Players[target][0] > 0) {
                                if (rand()%100+1 > Players[target][2]) {//roll to see if it hits armour
                                    //if the roll is greater than armour%, deal full damage
                                    Players[target][0] -= (Enemies[m][3]);
                                } else {
                                    //else we will reduce the damage by the enemy's DR
                                    Players[target][0] -= (Enemies[m][3] - Players[target][1]);
                                }
                                if (Players[target][0] <= 0) {
                                    plAli--;
                                }
                            }
                        }//End of Action
                    }//End of Turn
                }
            }
            //Players
             for (m = 0; m < numPlay; m++) {//Each Player's Turn
                if (Players[m][0] > 0) {
                    int action;
                    for (action = 0; action < 4; action++) {
                        if (action > 0) {
                            count = 0;
                            do {
                                target = rand()%numEn;
                                count++;
                            } while (Enemies[target][0] <= 0 && count < 3*numEn);
                            if (rand()%100+1 > Players[m][4] + Enemies[target][5] && Enemies[target][0] > 0) {
                                if (rand()%100+1 > Enemies[target][2]) {//roll to see if it hits armour
                                    //if the roll is greater than armour%, deal full damage
                                    Enemies[target][0] -= (Players[m][3]);
                                } else {
                                    //else we will reduce the damage by the enemy's DR
                                    Enemies[target][0] -= (Players[m][3] - Enemies[target][1]);
                                }
                                if (Enemies[target][0] <= 0) {
                                    enAli--;
                                }
                            }
                        }//End of Action
                    }//End of Turn
                }
            }
        }
    }
    return plAli - enAli;
}

int battle (int numEn, int numPlay, int** Enemies, int** Players) {

    int enAli = numEn;//Alive Enemies
    printf("Living Enemies: %d\n", enAli);
    int plAli = numPlay;//Alive Players
    printf("Living Players: %d\n", plAli);
    //randomly decide if players of enemies go first
    int order = rand()%2;
    //TODO replace with full initiative list
    
    int turn = 1;
    while (enAli > 0 && plAli > 0 && turn < 100) {
        printf("======= Turn %d: =======\n", turn);
        turn++;

        int m,n;
        int target = 0;
        int count = 0;
        if (order == 1) {
            //Players
            for (m = 0; m < numPlay; m++) {//Each Player's Turn
                if (Players[m][0] > 0) {
                    printf("Player %d's HP: %d\n", m+1, Players[m][0]);
                    int action;
                    for (action = 0; action < 4; action++) {
                        if (action > 0) {
                            count = 0;
                            do {
                                target = rand()%numEn;
                                count++;
                            } while (Enemies[target][0] <= 0 && count < 3*numEn);
                            if (rand()%100+1 > Players[m][4] + Enemies[target][5] && Enemies[target][0] > 0) {
                                if (rand()%100+1 > Enemies[target][2]) {//roll to see if it hits armour
                                    //if the roll is greater than armour%, deal full damage
                                    Enemies[target][0] -= (Players[m][3]);
                                    printf("Player %d hit Enemy %d for %d Damage!\n", m+1, target+1, Players[m][3]);
                                } else {
                                    //else we will reduce the damage by the enemy's DR
                                    Enemies[target][0] -= (Players[m][3] - Enemies[target][1]);
                                    printf("Player %d hit Enemy %d for %d Damage!\n", m+1, target+1, Players[m][3] - Enemies[target][1]);
                                }
                                if (Enemies[target][0] <= 0) {
                                    enAli--;
                                    printf("Enemy %d has been defeated!\n", target+1);
                                }
                            } else {
                                printf("Player %d missed Enemy %d!\n", m+1, target+1);
                            }
                        }//End of Action
                    }//End of Turn
                }
            }
            //Enemies
            for (m = 0; m < numEn; m++) {//Each Enemy's turn
                if (Enemies[m][0] > 0) {
                    printf("Enemy %d's HP: %d\n", m+1, Enemies[m][0]);
                    int action;
                    for (action = 0; action < 4; action++) {
                        if (action > 0) {
                            count = 0;
                            do {
                                target = rand()%numPlay;
                                count++;
                            } while (Players[target][0] <= 0 && count < 3*numPlay);
                            if (rand()%100+1 > Enemies[m][4] + Players[target][5] && Players[target][0] > 0) {
                                if (rand()%100+1 > Players[target][2]) {//roll to see if it hits armour
                                    //if the roll is greater than armour%, deal full damage
                                    Players[target][0] -= (Enemies[m][3]);
                                    printf("Enemy %d hit Player %d for %d Damage!\n", m+1, target+1, Enemies[m][3]);
                                } else {
                                    //else we will reduce the damage by the enemy's DR
                                    Players[target][0] -= (Enemies[m][3] - Players[target][1]);
                                    printf("Enemy %d hit Player %d for %d Damage!\n", m+1, target+1, Enemies[m][3] - Players[target][1]);
                                }
                                if (Players[target][0] <= 0) {
                                    plAli--;
                                    printf("Player %d has been defeated!\n", target+1);
                                }
                            } else {
                                printf("Enemy %d missed Player %d!\n", m+1, target+1);
                            }
                        }//End of Action
                    }//End of Turn
                }
            }
        } else {
            //Enemies
            for (m = 0; m < numEn; m++) {//Each Enemy's turn
                if (Enemies[m][0] > 0) {
                    printf("Enemy %d's HP: %d\n", m+1, Enemies[m][0]);
                    int action;
                    for (action = 0; action < 4; action++) {
                        if (action > 0) {
                            count = 0;
                            do {
                                target = rand()%numPlay;
                                count++;
                            } while (Players[target][0] <= 0 && count < 3*numPlay);
                            if (rand()%100+1 > Enemies[m][4] + Players[target][5] && Players[target][0] > 0) {
                                if (rand()%100+1 > Players[target][2]) {//roll to see if it hits armour
                                    //if the roll is greater than armour%, deal full damage
                                    Players[target][0] -= (Enemies[m][3]);
                                    printf("Enemy %d hit Player %d for %d Damage!\n", m+1, target+1, Enemies[m][3]);
                                } else {
                                    //else we will reduce the damage by the enemy's DR
                                    Players[target][0] -= (Enemies[m][3] - Players[target][1]);
                                    printf("Enemy %d hit Player %d for %d Damage!\n", m+1, target+1, Enemies[m][3] - Players[target][1]);
                                }
                                if (Players[target][0] <= 0) {
                                    plAli--;
                                    printf("Player %d has been defeated!\n", target+1);
                                }
                            } else {
                                printf("Enemy %d missed Player %d!\n", m+1, target+1);
                            }
                        }//End of Action
                    }//End of Turn
                }
            }
            //Players
             for (m = 0; m < numPlay; m++) {//Each Player's Turn
                if (Players[m][0] > 0) {
                    printf("Player %d's HP: %d\n", m+1, Players[m][0]);
                    int action;
                    for (action = 0; action < 4; action++) {
                        if (action > 0) {
                            count = 0;
                            do {
                                target = rand()%numEn;
                                count++;
                            } while (Enemies[target][0] <= 0 && count < 3*numEn);
                            if (rand()%100+1 > Players[m][4] + Enemies[target][5] && Enemies[target][0] > 0) {
                                if (rand()%100+1 > Enemies[target][2]) {//roll to see if it hits armour
                                    //if the roll is greater than armour%, deal full damage
                                    Enemies[target][0] -= (Players[m][3]);
                                    printf("Player %d hit Enemy %d for %d Damage!\n", m+1, target+1, Players[m][3]);
                                } else {
                                    //else we will reduce the damage by the enemy's DR
                                    Enemies[target][0] -= (Players[m][3] - Enemies[target][1]);
                                    printf("Player %d hit Enemy %d for %d Damage!\n", m+1, target+1, Players[m][3] - Enemies[target][1]);
                                }
                                if (Enemies[target][0] <= 0) {
                                    enAli--;
                                    printf("Enemy %d has been defeated!\n", target+1);
                                }
                            } else {
                                printf("Player %d missed Enemy %d!\n", m+1, target+1);
                            }
                        }//End of Action
                    }//End of Turn
                }
            }
        }
    }
    int* results = malloc(2*sizeof(int));
    results[0] = enAli;
    printf("Enemies: %d", enAli);
    results[1] = plAli;
    printf("Players: %d", plAli);
    report(results, numEn, numPlay, Enemies, Players);
    return plAli - enAli;
}

void resetList (int type, int numMem, int** resList, int** masList) {
    int i, j;
    int numStats = type == 0 ? E_STATS : P_STATS;//type 0 = enemy, 1 = player
    for (i = 0; i < numMem; i++) {
        for (j = 0; j < numStats; j++) {
            resList[i][j] = masList[i][j];
        }
    }
}


//Diferent Run Modes:
//Quiet mode simply takes the two groups and simulates a basic battle.
//Quite Custom gives you the opportunity to input a few options up front, then runs the battle.
//Full mode stops at each turn to ask if anything has changed.

void main() {
    printf("Welcome to QuickBattle version 0.5, this is an alpha release. Currently,\n");
    printf("you are able to specify the number of enemies and players on each side\n");
    printf("and specify weather you want to run in one of three modes:\n");
    printf("Verbose mode takes you through a single battle, outlining each player's\n");
    printf("Health at the start of their turn, as well as who they attack and what\n");
    printf("damage they deal, if any. At the end of the battle, the number of alive\n");
    printf("Players and Enemies is displayed, along with the healths of the winning\n");
    printf("side.\n");
    printf("Quiet mode runs through a single battle without spitting out any data\n");
    printf("other than the number of Enemies and Players alive at the end of the\n");
    printf("battle, as well as the healths of the winning team.\n");
    printf("Multi-Battle mode is similar to quiet mode, but runs as many times as\n");
    printf("specified, then reports the win/loss ratio of the player team.\n");
    while (1 < 2) {
        int numEn, numPlay;
        char mode = 'Q';
        int x, y;
        printf("How many enemies?: ");
        scanf("%d", &numEn);
        printf("\n");
        printf("How many players?: ");
        scanf("%d", &numPlay);
        printf("\n");
        printf("Verbose / Quiet (V/Q)? ");
        scanf("%c", &mode);
        mode = getchar();
        printf("\n");

        int i;
        //Enemy List
        int** Enemies;
        Enemies = malloc (numEn * sizeof(int*));
        for (i = 0; i < numEn; i++) {
            Enemies[i] = malloc(E_STATS * sizeof(int));//enemies have 7 stats: Health, DR,
                                    // Armour %, Dam, Hit %, Cover bonus, hunkered;
        }
        //Copy of Enemy List
        int** EnCopy;
        EnCopy = malloc (numEn * sizeof(int*));
        for (i = 0; i < numEn; i++) {
            EnCopy[i] = malloc(E_STATS * sizeof(int));
        }
        //Player List
        int** Players;
        Players = malloc (numPlay * sizeof(int*));
        for (i = 0; i < numPlay; i++) {
            Players[i] = malloc(P_STATS * sizeof(int));//Same stats as enemy (for now)
        }
        //Copy of Player List
        int** PlCopy;
        PlCopy = malloc (numPlay * sizeof(int*));
        for (i = 0; i < numPlay; i++) {
            PlCopy[i] = malloc(P_STATS * sizeof(int));
        }

        if (mode == 'V' || mode == 'v') {
            //Initialize members of each group.
            printf("=== Enemies Initializing ===\n");
            initEnemies(numEn, Enemies);
            printf("=== EnCopy Initializing ===\n");
            initEnemies(numEn, EnCopy);
            printf("=== Players Initializing ===\n");
            initPlayers(numPlay, Players);
            printf("=== PlCopy Initializing ===\n");
            initPlayers(numPlay, PlCopy);
            printf("| HP | DR | A%% | Dm | M%% |\n");
            printf("=== Players ===\n");
            for (x = 0; x < numPlay; x++) {
                printf("Player %d:\n", x+1);
                for (y = 0; y < P_STATS; y++) {
                    printf("| %d ", Players[x][y]);
                }
                printf("|\n");
            }
            printf("=== Enemies ===\n");
            for (x = 0; x < numEn; x++) {
                printf("Enemy %d:\n", x+1);
                for (y = 0; y < E_STATS; y++) {
                    printf("| %d ",Enemies[x][y]);
                }
                printf("|\n");
            }

            printf("=== PlCopy ===\n");
            for (x = 0; x < numPlay; x++) {
                printf("Player %d:\n", x+1);
                for (y = 0; y < P_STATS; y++) {
                    printf("| %d ", PlCopy[x][y]);
                }
                printf("|\n");
            }
            printf("=== EnCopy ===\n");
            for (x = 0; x < numEn; x++) {
                printf("Enemy %d:\n", x+1);
                for (y = 0; y < E_STATS; y++) {
                    printf("| %d ",EnCopy[x][y]);
                }
                printf("|\n");
            }
        } else {
            //Initialize members of each group.
            initEnemies(numEn, Enemies);
            initEnemies(numEn, EnCopy);
            initPlayers(numPlay, Players);
            initPlayers(numPlay, PlCopy);
        }

        
        int* results = malloc(2*sizeof(int));
        results[0] = 0;
        results[1] = 0;

        printf("Determining Battle Mode . . .\n");
        if (mode == 'V' || mode == 'v') {
            printf("Verbose Mode\n");
            battle(numEn, numPlay, Enemies, Players);
        } else if (mode == 'Q' || mode == 'q') {
            printf("Quiet Mode\n");
            qBattle(numEn, numPlay, Enemies, Players);
        } else if (mode == 'M' || mode == 'm') {
            printf("Multi-Battle Mode\n");
            printf("How many battles? ");
            int battles, b, result;
            int wins = 0;
            int loss = 0;
            scanf("%d", &battles);
            for (b = 0; b < battles; b++) {
                result = qBattle(numEn, numPlay, Enemies, Players);
                resetList(0, numEn, Enemies, EnCopy);
                resetList(1, numPlay, Players, PlCopy);
                if (result > 0) {
                    wins++;
                } else {
                    loss++;
                }
            }
            printf("Win/Loss ratio: %d/%d\n", wins, loss);
        }
        char rep;
        printf ("Repeat? Y/N ");
        scanf("%c", &rep);
        rep = getchar();
        if (rep == 'N' || rep == 'n') {
            return;
        }
    }
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