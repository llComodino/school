#include <stdio.h>
#include "../lib/info.h"
#include "../lib/data.h"
#include "../lib/battle.h"

Character myCharacter;
Character loadedCharacter;
Foes currentFoe;

int main(void) {

    create_character(&myCharacter, &loadedCharacter);

    foe_description(&currentFoe);

    battle(&myCharacter, &currentFoe);

    return 0;
}
