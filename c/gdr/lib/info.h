#ifndef INFO_H
#define INFO_H

#include "data.h"
#include <stdio.h>

void world_info (void);

enum World select_world (void);

void print_player_info (const Player *const);

#endif // !INFO_H
