#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <malloc.h>
#include "../lib/info.h"

int main (void) {
    
    // Struct per contenere le informazioni dei mondi
    typedef struct {

        char *name;
        double mult;
    } worlds;

    worlds world1;


    // Struct per contenere le statistiche del player
    typedef struct {

        char *name;
        double dmg_mul;
    } characters;

    return 0;
}
