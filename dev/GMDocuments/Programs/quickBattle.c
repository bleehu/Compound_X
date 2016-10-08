#include <stdio.h>
#include <stdlib.h>

int* Enemies;

//prints a list of the active enemies to be attacked
//returns a number selected by the player.
int playerSelect (int activeEnemies) {
    int toReturn = -1;
    printf("Select which target to attack: ");
    int j;
    for (j = 0; j < activeEnemies; j++) {
        printf("%d; ", j);
    }
    int token;
    scanf("%d", &token);
    printf("\n");

    if (token < activeEnemies && token >= 0) {
        toReturn = token;
    }

    return toReturn;
}

//takes 3 integers: Target, Miss chance, Damage.
//The function randomly attacks the target, dealing Damage to them
//based on the provided Miss chance; if the random value out of 100
//is greater than the miss chance, the target is hit.
int pAttack (int aTarget, int aMiss, int aDamage) {
    toReturn = 0;
    if (rand()%100 > aMiss) {
        Enemies[aTarget] -= aDamage;
        printf("Target %d takes %d damage.\n", aTarget, aDamage);
        if (Enemies[aTarget] <= 0) {
            printf("Target defeated!\n");
            toReturn = 1;
        }
    } else {
        printf("your attack has missed enemy %d.", aTarget);
    }
    return toReturn;
}

//randomly do things. Enemies will usually Aim and then fire as many
//times as they can.
void enemyTurn (int enemy) {
    //4 half actions
    int i;
    for (i = 0; i++; i < 4) {
        //do some half-action
    }
}

//assists the player in performing their actions.
//Actions are: "Fire", "Reload", "Switch"(weapons), "Hunker", "Item",
//"Other".
//"Fire" prompts a target selection out of the current enemy
//combatants.
//Reload resets the current weapon's ammo counter to full, and
//decrements magazines by 1.
//"Switch" prompts a weapon selection when applicable.
//"Hunker" Puts the player in hunkered cover, offering +25 defense.
//"Item" prompts an item selection when applicable.
//"Other" prompts a description of the action, and prints it.
void playerTurn (int activeEnemies, int* player) {
    int ha = 4; //Number of Half-Actions a player has per turn.
    //This is an artifact of the way the pen & paper game is played.

    char* action = malloc(sizeof(char)*8);

    while (ha > 0) {
        //ask player what to do
        printf ("====================\n");
        printf("Half-Actions Remaining: %d\n", ha);
        printf ("What would you like to do?:\n");
        printf (" Fire  [1]|| Reload [2]|| Switch[1]\nHunker [2]||  Item  [1]|| Other [1]\n");
        scanf("%s", action);
        printf("Action selected: \"%s\"\n", action);
        if (strcmp(action, "Fire") == 0 || strcmp(action, "fire") == 0 || strcmp(action, "f") == 0 || strcmp(action, "F") == 0) {
            printf("---Fire---\n");
            pAttack(playerSelect(activeEnemies), player[7], player[8]);//target, miss, damage
            ha--;
        } else if (action == "Reload" || action == "reload" || action == "R" || action == "r") {
            printf("---Reload---\n");
            if (ha > 1) {
                ha-=2;
                if (player[11] > 0) {
                    player[9] = player[10];
                    player[11]--;
                    printf("Lock 'n' load!\n");
                } else {
                    printf("No Mags!\n");
                }
            } else {
                printf("Not enough time!\n");
            }
        } else if (action == "Switch" || action == "switch" || action == "S" || action == "s") {
            printf("---Switch---\n");
            printf("You only have 1 weapon.");
            /*if (ha > 1) {
                ha--
                switch();
            }*/
        } else if (action == "Hunker" || action == "hunker" || action == "H" || action == "h") {
            printf("---Hunker---\n");
            if (ha>2) {
                ha-=2;
                printf("You take cover, +25 Defense");
                player[13] = 25;
                //isHunkered = true;
            }
        } else if (action == "Item" || action == "item" || action == "I" || action == "i") {
            printf("---Item---\n");
            printf("No items :(\n");
        } else if (action == "Other" || action == "other" || action == "O" || action == "o") {
            printf("---Other---\n");
            if (ha > 1) {
                printf("Some time is spent, -1 half action\n");
            }
        }

    }

}

//prints the status of all objects in the battle.
void printStats () {


}

void main() {

    int numEn;
    printf("How many enemies?: ");
    scanf("%d", &numEn);
    printf("\n");
    //Initialize enemy types
    Enemies = malloc(sizeof(int)*numEn);
    int k;
    for (k = 0; k < numEn; k++) {
        Enemies[k] = 100;
    }
    //Initialize player
    //{0 Str; 1 Per; 2 Fort; 3 Cha; 4 Int; 5 Dex; 6 Luk;
    //7 primary miss; 8 primary dam; 9 primary in mag;
    //10 primary mag size; 11 primary mags; 12 Health; 13 Hunkered}
    char* input = malloc(sizeof(char)*10);
    int* playerStats = malloc(sizeof(int)*13);
    printf("Enter player stats:\nStrength: ");
    scanf("%d", &playerStats[0]);
    printf("\nPerception: ");
    scanf("%d", &playerStats[1]);
    printf("\nFortitude: ");
    scanf("%d", &playerStats[2]);
    printf("\nCharisma: ");
    scanf("%d", &playerStats[3]);
    printf("\nIntelligence: ");
    scanf("%d", &playerStats[4]);
    printf("\nDexterity: ");
    scanf("%d", &playerStats[5]);
    printf("\nLuck: ");
    scanf("%d", &playerStats[6]);

    printf("\nMiss Chance of Primary: ");
    scanf("%d", &playerStats[7]);
    printf("\nPrimary Damage: ");
    scanf("%d", &playerStats[8]);
    printf("\nRounds in Magazine: ");
    scanf("%d", &playerStats[9]);
    printf("\nSize of Magazine: ");
    scanf("%d", &playerStats[10]);
    printf("\nNumber of Magazines: ");
    scanf("%d", &playerStats[11]);
    playerStats[12] = (playerStats[2] *10 +50);
    playerStats[13] = 0;
    //roll initiative
    //Take first turn
    while (playerStats[12] > 0) {
        playerTurn(numEn, playerStats);
        int u;
        for (u = 0; u < numEn; u++) {
            if ()
            enemyTurn(u);
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