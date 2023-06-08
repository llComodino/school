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

    create_character(&loadedCharacter);

    while (status == ongoing) {

        while (!(battle(&loadedCharacter, enemies[loadedCharacter.foe]))) {
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

        print_player_info(&loadedCharacter);

        switch (loadedCharacter.world) {
            case thato:
                switch (loadedCharacter.foe++) {
                    case blackfire:
                        puts("You've beaten the final boss BlackFire!!\nThanks adventurer for clearing the land!\n");
                        return 2;
                    break;

                    case ironjaw:
                        puts("You've finally succedeed in killing IronJaw!\nNow let's move on to Shadowthorn\n");
                    break;

                    case shadowthorn:
                        puts("Impressive! You're still alive even after meeting Shadowthorn!\nI believe you are ready to fight the final boss\n");
                    break;

                    default:
                    break;
                }
            break;

            case chanda:
                switch (loadedCharacter.foe++) {
                    case milly:
                        printf("You've beaten the final boss!\nThanks adventurer for clearing the land!\n\n");
                        return 2;
                    break;
                
                    case virgy:
                        puts("You've finally succedeed in killing Virgy the Faithful!\nNow let's move on to Emily the Vampire\n");
                    break;

                    case emily:
                        puts("Impressive! You're still alive even after meeting Emily!\nI believe you are ready to fight the final boss\n");
                    break;
                    
                    default:
                    break;
                }
            break;

            default:
            break;
        }

        save_data(&loadedCharacter, loadedCharacter.name);
        
        int sel;
        puts("Do you wish to explore further in this messed reality? [0/1]");
        
        do {
            scanf("%d", &sel);
        } while (sel < 0 || sel > 1);

        if (sel) {
            puts("Then good luck for when you will come back...");
            return 1;
        }

        loadedCharacter.hp = 100;
    }

    puts("ERROR: You should not be seeing this");
    return 0;
}
