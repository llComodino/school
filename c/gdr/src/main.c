#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <malloc.h>
#include "../lib/info.h"
#include "../lib/data.h"

Character myCharacter;
Character loadedCharacter;

int main() {

    create_character(&myCharacter, &loadedCharacter);

    return 0;
}
