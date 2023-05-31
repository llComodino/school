#ifndef DATA_H
#define DATA_H

#include <stdbool.h>
#define BUFFER 32

enum Status {ongoing, won, lost};
enum playerStatus {base, poisoned, burning};
enum Item {health_potion, poison, strength_potion, firebomb};
enum Weapon {kyrsblade, tanto, fists, flintlock, bow, shuriken, grimoire, orb, staff, sinister_steel};
enum Type {melee, ranged, magic, magic_melee, magic_ranged};

typedef struct {
    enum Weapon id;
    char name[BUFFER];
    int dmg;
    enum Type type;
} Weapons;

typedef struct {
    char name[BUFFER];
    int level;
    int character_class;
    int hp;
    Weapons weapon;
    enum Type type;
} Character;

typedef struct {
    char name[BUFFER];
    int level;
    int character_class;
    int hp;
    Weapons weapon;
    enum Type type;
} Foes;

typedef struct {
    enum Item type;
    char namep[BUFFER];
    int modifier;
    int available;
} Items;

void load_data (Character *const, const char *const);

void create_character (Character *const);

#endif // !DATA_H
