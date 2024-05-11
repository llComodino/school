#ifndef PACMAN_H

#include <stdio.h>

#define HEIGHT  20
#define WIDTH   50
#define GHOSTS  4

typedef enum {
  NORMAL,
  KILL_GHOSTS,
  WON,
  LOST
} GAME_STATUS;

typedef enum {
  UP,
  DOWN,
  LEFT,
  RIGHT
} DIRECTION;

typedef enum {
  PLAYER,
  GHOST,
  COIN,
  WALL,
  EMPTY
} TILES;

typedef struct {
  unsigned int score;
  unsigned int coins;
  GAME_STATUS status;
} Game;

typedef struct {
  size_t x_pos;
  size_t y_pos;
} Position;

typedef struct {
  Position coordinate;
  DIRECTION direction;
} Entity;

#endif // PACMAN_H
