#ifndef BATTLE_H
#define BATTLE_H

#define MAX_HEAL 15
#define MIN_HEAL 15
#define MAX_BOMB_DMG 10
#define MIN_BOMB_DMG
#define MIN_POISON 2
#define MAX_POISON 6
#define MIN_BURN 2
#define MAX_BURN 6
#define MIN_SHURIKEN 3
#define MAX_SHURIKEN 9

#include "data.h"

void assign_weapon(Player *const);

void load_foe(Player *const, const char *const);

bool battle (Player *const, const char *const);

#endif // !BATTLE_H
