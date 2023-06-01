#include <stdio.h>
#include "../lib/info.h"
#include "../lib/data.h"
#include "../lib/battle.h"

Player loadedCharacter;

int main(void) {

    // world_info();
    create_character(&loadedCharacter);

    while ((loadedCharacter.hp = battle(&loadedCharacter, "matteo_messina_denaro")) == false) {
        printf("Do you wish to continue? [y(0) / n(1)]");
        int z;
        do {
            scanf("%d", &z);
        } while (z != 1 && z != 0);

        if (z) {
            printf("We'll meet again, %s, just wait ...\n\n", loadedCharacter.name);
            return 1;
        }
    }

    print_character_info(&loadedCharacter);

    puts("What now?");

    save_data(&loadedCharacter, loadedCharacter.name);

    return 0;
}
