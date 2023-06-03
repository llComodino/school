#ifndef DATA_H
#define DATA_H

#include <stdbool.h>
#define BUFFER 32

enum Status {ongoing, won, lost};
enum World {thato, chanda};
enum playerStatus {base, poisoned, burning};
enum Item {health_potion, firebomb, void_crystal};
enum Weapon {kyrsblade, tanto, fists, flintlock, bow, shuriken, grimoire, orb, staff, sinister_steel};
enum Modifier {none, poisonus, burn, rapid};
enum Type {melee, ranged, magic, magic_melee, magic_ranged};
enum Foe {ironjaw, shadowthorn, blackfire};

typedef struct {
    enum Weapon id;
    enum Type type;
    enum Modifier mod;
    char name[BUFFER];
    int dmg;
} Weapons;

typedef struct {
    int poison_start;
    int burn_start;
    int strength_start;
    int armor_start;
    int boost_start;
} Player_Modifiers;

typedef struct {
    enum playerStatus status;
    enum Type type;
    enum Weapon weapon_id;
    char name[BUFFER];
    int level;
    int character_class;
    int hp;
    Weapons weapon;
    Player_Modifiers modifiers;
} Player;

typedef struct {
    enum Item type;
    char name[BUFFER];
} Items;

void load_data (Player *const, const char *const);

void create_character (Player *const);

#endif // !DATA_H
