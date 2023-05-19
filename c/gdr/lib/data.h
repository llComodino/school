#ifndef DATA_H
#define DATA_H

#include <stdbool.h>
#define BUFFER 32

typedef struct {
    char name[BUFFER];
    int dmg;
    bool ranged;
    bool magic;
} Weapons;

typedef struct {
    char name[BUFFER];
    int level;
    int character_class;
    int hp;
    Weapons weapon;
    bool ranged;
    bool magic;
} Character;

typedef struct {
    char name[BUFFER];
    int level;
    int character_class;
    int hp;
    Weapons weapon;
    bool ranged;
    bool magic;
} Foes;

void load_data (Character *const, const char *const);

void create_character (Character *const);

#endif // !DATA_H
