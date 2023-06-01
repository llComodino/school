#ifndef DATA_H
#define DATA_H

#include <stdbool.h>
#define BUFFER 32

enum Status {ongoing, won, lost};
enum playerStatus {base, poisoned, burning};
enum Item {health_potion, poison, strength_potion, firebomb};
enum Weapon {kyrsblade, tanto, fists, flintlock, bow, shuriken, grimoire, orb, staff, sinister_steel};
enum WeaponModifier {none, poisonus, firing, rapid};
enum Type {melee, ranged, magic, magic_melee, magic_ranged};
enum Foe {shadowthorn, ironjaw, blackfire};

typedef struct {
    enum Weapon id;
    enum Type type;
    enum WeaponModifier mod;
    char name[BUFFER];
    int dmg;
} Weapons;

typedef struct {
    enum playerStatus status;
    enum Type type;
    enum Weapon weapon_id;
    char name[BUFFER];
    int level;
    int character_class;
    int hp;
    Weapons weapon;
} Player;

typedef struct {
    enum Item type;
    char namep[BUFFER];
    int modifier;
    int available;
} Items;

void load_data (Player *const, const char *const);

void create_character (Player *const);

#endif // !DATA_H
