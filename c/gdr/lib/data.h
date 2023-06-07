#ifndef DATA_H
#define DATA_H

#include <stdbool.h>

#define BUFFER 32
#define PATH_BUF 64
#define BUF 128
#define WORLDS 2
#define ENEMIES 3
#define CLASSES 4
#define WEAPONS 10
#define ITEMS 5

enum Status {ongoing, won, lost};
enum World {thato, chanda};
enum playerStatus {base, poisoned, burning};
enum Item {health_potion, firebomb, void_crystal};
enum Weapon {kyrsblade, tanto, fists, flintlock, bow, shuriken, grimoire, orb, staff, sinister_steel};
enum Modifier {none, poisonus, burn, rapid};
enum Type {melee, ranged, magic, magic_melee, magic_ranged};
enum Foes {ironjaw, shadowthorn, blackfire, virgy, emily, milly};

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
} Player_Modifiers;

typedef struct {
    enum playerStatus status;
    enum Type type;
    enum Weapon weapon_id;
    enum World world;
    enum Foes foe;
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

void save_data (Player * character, const char *const filename);

void load_data (Player *const, const char *const);

void create_character (Player *const);

#endif // !DATA_H
