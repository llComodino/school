#include <stdio.h>
#include "../lib/info.h"
#include "../lib/data.h"
#include "../lib/battle.h"

Player loadedCharacter;
enum Status status = ongoing;

int main(void) {

    // world_info();
    create_character(&loadedCharacter);

    while (status == ongoing) {
        while (!(loadedCharacter.hp = battle(&loadedCharacter, "IronJaw"))) {
            printf("\nAre you willing to test your luck yet another time? [0/1]");
            int z;
            do {
                scanf("%d", &z);
            } while (z != 1 && z != 0);

            if (z) {
                printf("We'll meet again, %s, just wait ...\n\n", loadedCharacter.name);
                return 1;
            }
        }

        status = won;
        
        print_character_info(&loadedCharacter);
        save_data(&loadedCharacter, loadedCharacter.name);

        puts("Do you wish to explore further in this messed reality?");
    }

    puts("What now?");


    return 0;
}
