#ifndef DATA_H
#define DATA_H

#include <stdbool.h>

typedef struct {
    int id;
    int dmg;
    bool ranged;
    bool magic;
} Weapons;

typedef struct {
    char name[32];
    int level;
    int character_class;
    int hp;
    Weapons weapon;
    bool ranged;
    bool magic;
} Character;

typedef struct {
    char name[32];
    int level;
    int character_class;
    int hp;
    Weapons weapon;
    bool alive;
} Foes;

void load_data (Character *character, const char *const filename);

void create_character (Character *myCharacter, Character *loadedCharacter);

bool battle (Character *myCharacter, Foes *currentFoe);

#endif // !DATA_H
