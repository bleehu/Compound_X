/*=============================================================================
 * Quick Level
 * This program allows users to qickly determine how many Skill Points, Stat
 * Point Increases, Feats, Class Feats, and how much money thy would have at a
 * given inout level.
 *===========================================================================*/
#include <stdlib.h>
#include <stdio.h>

void main () {
    int level, chari, intel;
    printf("What level are you starting at? ");
    scanf("%d", &level);
    printf("Perfect, let me calculate your assets . . .\n");
    printf("What is your Charisma score at level 1? ");
    scanf("%d", &chari);
    printf("And your Intelligence score at level 1? ");
    scanf("%d", &intel);
    printf("Excellent, wait a second.\n");

    int i;
    int skill=0, stat=0, feat=0, cfeat=0; //The assets being acrued.
    for (i = 1; i <= level; i++) {
        if (i == 5 || i == 9 || i == 15 || i == 20) {
            printf("At level %d you get a stat increase. Would this go into Intelligence or Charisma? (y/n) ", i);
            char rep;
            scanf("%c", &rep);
            rep = getchar();
            if (rep == 'Y' || rep == 'y') {
                printf("Which will you spend it on, Int or Cha? (i/c) ");
                char rep2;
                scanf("%c", &rep2);
                rep2 = getchar();
                if (rep2 == 'I' || rep2 == 'i') {
                    intel++;
                } else if (rep2 == 'C' || rep2 == 'c') {
                    chari++;
                }
            }
            stat++;
        }
        //Every Level, skill increases by 2*Intelligence.
        if (i != 1) skill += 2*intel;
        else skill += 50;
        if (i%5 == 0) cfeat++; //every fifth level is a class feat.
        if (i%2 == 0) feat++; //every other level gain a feat.
        if (i%4 == 0 && chari > 8) feat++; //with > 8 chari, bonus feats.
    }
    printf("All done! Lets see what you got:\n");
    printf("Skills points: %d\n", skill);
    printf("Feats: %d\n", feat);
    printf("Class Feats: %d\n", cfeat);
    printf("Stat increases: %d\n", stat);
 }