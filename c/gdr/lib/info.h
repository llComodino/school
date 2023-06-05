#ifndef INFO_H
#define INFO_H

#include "data.h"
#include <stdio.h>

void save_data (Player * character, const char *const filename);

void world_info (void);

enum World select_world (void);

void print_character_info (const Player *const);

#endif // !INFO_H
