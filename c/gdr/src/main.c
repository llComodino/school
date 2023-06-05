#include <stdio.h>
#include "../lib/info.h"
#include "../lib/data.h"
#include "../lib/battle.h"

const char *enemies[ENEMIES * WORLDS] = {
    "IronJaw", 
    "Shadowthorn", 
    "Blackfire", 
    "Virgy", 
    "Emily", 
    "Milly"
};

Player loadedCharacter;
enum Status status = ongoing;

int main(void) {

    // world_info();
    create_character(&loadedCharacter);

    while (status == ongoing) {

        while (!(loadedCharacter.hp = battle(&loadedCharacter, enemies[loadedCharacter.foe]))) {
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

        loadedCharacter.foe++;
        
        print_character_info(&loadedCharacter);
        save_data(&loadedCharacter, loadedCharacter.name);

        switch (loadedCharacter.world) {
            case thato:
                if (loadedCharacter.foe > blackfire) {
                    puts("You've beaten the final boss BlackFire!!\nThanks adventurer for clearing the land!\n");
                    return 2;
                }

                if (loadedCharacter.foe = ironjaw) {
                    puts("You've finally succedeed in killing IronJaw!\nNow let's move on to Shadowthorn\n");
                }

                if (loadedCharacter.foe = ironjaw) {
                    puts("Impressive! You're still alive even after meeting Shadowthorn!\nI believe you are ready to fight the final boss\n");
                }
            break;

            case chanda:
                if (loadedCharacter.foe > milly) {
                    printf("You've beaten the final boss!\nThanks adventurer for clearing the land!\n\n");
                    return 2;
                }
                
                if (loadedCharacter.foe = virgy) {
                    puts("You've finally succedeed in killing Virgy the Faithful!\nNow let's move on to Emily the Vampire\n");
                }

                if (loadedCharacter.foe = emily) {
                    puts("Impressive! You're still alive even after meeting Emily!\nI believe you are ready to fight the final boss\n");
                }
            break;

            default:
            break;
        }

        int sel;
        puts("Do you wish to explore further in this messed reality? [0/1]");
        scanf("%d", &sel);
        
        if (sel) {
            puts("Then good luck for when you will come back...");
            return 1;
        }

        loadedCharacter.hp = 100;
    }

    puts("ERROR: You should not be seeing this");
    return 0;
}
