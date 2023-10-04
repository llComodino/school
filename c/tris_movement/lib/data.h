#include <stdio.h>

typedef struct {
    char *name;
    int wins;
    int draws;
    int losses;
    int games;
} Character;

void welcome (void) {
    puts("==============================================================");
    puts("Welcome to my tris game!");
    puts("In this game you select the cell by moving with the arrow keys");
    puts("==============================================================");

    return;
}

Character friend (void) {
    
}

Character ai (void) {

}

(Character *)(void) opponent (void) {
    puts("Would you like to verse a friend [1] or an AI [2]?");

    int sel;
    
    do {
        scanf("%i", &sel);
    } while (sel != 1 && sel != 2);

    if (sel) {
        return &friend;
    } else {
        return &ai;
    }

    puts("Something has gone wrong, you'll be playing AI");
    return &ai;
}
