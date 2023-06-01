#ifndef BATTLE_H
#define BATTLE_H

#include "data.h"

void assign_weapon(Weapons *const);

void foe_description(Player *);

void load_foe(Player *, const char *const);

bool battle (Player *, const char *const);

#endif // !BATTLE_H
