#ifndef BATTLE_H
#define BATTLE_H

#include "data.h"

void foe_description(Foes *);

void load_foe(Foes *, const char *const);

bool battle (Character *, const char *const);

#endif // !BATTLE_H
