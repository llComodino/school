#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "pacman.h"

int msleep(unsigned int);
void __init_game(short **, Entity **, Entity **);
void init_map(short *);
void print_map(short *);
void update_map(short *, Entity *, Entity *);

Game game = {
  0,
  0,
  NORMAL,
};

int main(void) {

  short *map = NULL;
  Entity *ghosts = NULL;
  Entity *player = NULL;

  __init_game(&map, &ghosts, &player);
  print_map(map);

  while (game.status != WON && game.status != LOST) {
    update_map(map, ghosts, player);
  }

}

void __init_game(short **map, Entity **ghosts, Entity **player) {

  void count_coins(short *);

  // Allocate map mem
  if ( (
        (*map) = (short *) malloc(sizeof(short) * WIDTH * HEIGHT)
        ) == NULL ) {
    fprintf(stderr, "Not enough mem");
    exit(1);
  }

  for (size_t i = 0; i < HEIGHT * WIDTH; i++) {
    *((*map) + i) = 4;
  }

  // init map tiles
  init_map((*map));
  count_coins((*map));

  if ( (
        (*ghosts) = (Entity *) malloc(sizeof(Entity) * GHOSTS)
        ) == NULL ) {
    fprintf(stderr, "Not enough mem");
    exit(1);
  }

  if ( (
        (*player) = (Entity *) malloc(sizeof(Entity))
        ) == NULL ) {
    fprintf(stderr, "Not enough mem");
    exit(1);
  }

  (*player)->coordinate.x_pos = 0;
  (*player)->coordinate.y_pos = 0;
  (*player)->direction = RIGHT;

  return;
}

void count_coins(short *map) {
  for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
    if ( *(map + i) == 2 ) {
      game.coins++;
    }
  }

  return;
}

int msleep(unsigned int milliseconds) {
  return usleep(milliseconds);
}

void init_map(short *map) {

  FILE *file = fopen("map_1", "r");
  short tmp = 0;

  for (size_t i = 0; i < HEIGHT; i++) {
    for (size_t j = 0; j < WIDTH; j++) {
      fscanf(file, "%hi", &tmp);
      *(map + i * WIDTH + j) = tmp;
    }
  }

  return;
}

void print_map(short *map) {

  for (size_t i = 0; i < HEIGHT; i++) {
    for (size_t j = 0; j < WIDTH; j++) {

      switch (*(map + (i * WIDTH) + j)) {

        case 0:
          printf("%2s", j % 2 ? "C" : "c");
          break;
        case 1:
          printf("%2s", "8");
          break;
        case 2:
          printf("%2s", "*");
          break;
        case 3:
          printf("%2s", "|");
          break;
        default:
          printf("%2s", " ");
          break;
      }

    }

    puts("");
  }

  fflush(stdout);
  return;
}

void update_map(short *map, Entity *ghosts, Entity *player) {

  void clear_screen(void);
  void update_player(Entity *player);
  void update_ghosts(Entity *ghosts);

  for (size_t i = 0; i < WIDTH; i++) {

    msleep(30000);

    *(map + player->coordinate.x_pos + player->coordinate.y_pos * WIDTH) = 4;
    update_player(player);
    *(map + player->coordinate.x_pos + player->coordinate.y_pos * WIDTH) = 0;

    update_ghosts(ghosts);

    clear_screen();
    print_map(map);

  }

  return;
}

void update_ghosts(Entity *ghosts) {

  return;
}

void update_player(Entity *player) {
  
  char c = getchar();
  printf("Prssed: %c\n", c);

  switch (c) {

    case 65:
      player->coordinate.y_pos > 0
        ? player->coordinate.y_pos--
        : (player->coordinate.y_pos = HEIGHT - 1);
      break;

    case 66:
      player->coordinate.y_pos < HEIGHT - 1
        ? player->coordinate.y_pos++
        : (player->coordinate.y_pos = 0);
      break;

    case 68:
      player->coordinate.x_pos > 0
        ? player->coordinate.x_pos--
        : (player->coordinate.x_pos = WIDTH - 1);
      break;

    case 67:
      player->coordinate.x_pos < WIDTH - 1
        ? player->coordinate.x_pos++
        : (player->coordinate.x_pos = 0);
      break;
  }


  return;
}


void clear_screen(void) {

  system("clear");
  return;

}
