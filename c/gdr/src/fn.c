#include "../lib/battle.h"
#include "../lib/data.h"
#include "../lib/info.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *weapons[WEAPONS] = {

  // Melee
  "Kyrsblade", // Sword
  "Tanto",     // Knife | + poison
  "Fists",     // Fists | + physical dmg

  // Ranged
  "Flintlock",    // Flintlock
  "Obsidian Bow", // Bow + corruption
  "Shuriken",     // Shuriken | low dmg [multiple throws]

  // Magic [melee]
  "Grimoire", // Enchanted book + [strong]fire
  "Orb",      // Magical Orb + [strong]fire

  // Magic [ranged]
  "Cesy Staff",         // Magical Staff + [strong]physical boost
  "The Sinister Steel", // Magical Daggers + [strong]corruption
};

const char *classes[CLASSES] = {"Warrior", "Archer", "Assassin", "Mage"};

const char *items[ITEMS] = {"Health Potion", "Firebomb", "Void Crystal"};

void world_info(void) {

  char buffer[BUF];
  char z;

  FILE *file = fopen("assets/world_info/thato_kehinde.txt", "r");
  while (fgets(buffer, BUF, file) != NULL) {
  printf("%s", buffer);
  }
  fclose(file);

  // Clean the output stream
  // Last char was '\n', if not removed the next cycle won't work
  getchar();

  // wait for user to press enter so he has time to read
  while ((z = getchar()) != '\n');

  puts("======================================================================="
       "==========================================================\n");

  file = fopen("assets/world_info/chanda_sung.txt", "r");
  while (fgets(buffer, BUF, file) != NULL) {
  printf("%s", buffer);
  }

  fclose(file);

  // wait for user to press enter so he has time to read
  while ((z = getchar()) != '\n');

  return;
}

void save_data(Player *const character, const char *const filename) {

  // Save the character data to a file
  char name[PATH_BUF] = "assets/characters/";
  strcat(name, filename);
  strcat(name, ".txt");

  FILE *file = fopen(name, "w");

  // Error handling
  if (file == NULL) {
  printf("Error: could not create/open file\n");
  return;
  }

  fprintf(file, "%d\n", character->world);
  fprintf(file, "%d\n", character->foe);
  fprintf(file, "%d\n", character->weapon_id);
  fprintf(file, "%s\n", character->name);
  fprintf(file, "%d\n", character->level);
  fprintf(file, "%d\n", character->character_class);
  fprintf(file, "%d\n", character->hp);
  fprintf(file, "%d\n", character->type);

  fclose(file);

  return;
}

void load_data(Player *const character, const char *const filename) {

  void load_weapon(Player *const, const char *const);
  // Load the character data from the file into a struct
  char path[PATH_BUF] = "assets/characters/";
  strcat(path, filename);
  strcat(path, ".txt");

  FILE *file = fopen(path, "r");

  // Error handling
  if (file == NULL) {
  printf("Error: could not open file\n");
  return;
  }

  fscanf(file, "%d", &character->world);
  fscanf(file, "%d", &character->foe);
  fscanf(file, "%d", &character->weapon_id);
  fscanf(file, "%d", &character->level);
  fscanf(file, "%d", &character->character_class);
  fscanf(file, "%d", &character->hp);
  fscanf(file, "%d", &character->type);

  load_weapon(character, path);

  fclose(file);

  return;
}

void load_weapon(Player *const player, const char *const char_path) {

  char path[PATH_BUF] = "assets/weapons/";

  FILE *file;
  fscanf((file = fopen(char_path, "r")), "%d", &player->weapon.id);
  fclose(file);

  strcpy(player->weapon.name, weapons[player->weapon_id]);

  strcpy(path, "assets/weapons/");
  strcat(path, weapons[player->weapon.id]);
  strcat(path, ".txt");

  file = fopen(path, "r");

  fscanf(file, "%d", &player->weapon.id);
  fscanf(file, "%d", &player->weapon.dmg);
  fscanf(file, "%d", &player->weapon.type);
  fscanf(file, "%d", &player->weapon.mod);

  return;
}

void assign_weapon(Player *const player) {
  srand(time(NULL));
  short tmp = rand() % 10;
  player->weapon_id = tmp;

  char path[PATH_BUF] = "assets/weapons/";
  strcat(path, weapons[tmp]);
  strcat(path, ".txt");

  player->weapon.id = tmp;

  load_weapon(player, path);

  return;
}

void create_character(Player *const character) {

  char name[PATH_BUF] = "assets/characters/";

  // Ask the user informations about his character
  printf("Enter your name, warrior: ");
  fgets(character->name, sizeof(character->name),
      stdin); // Use fgets to store string with spaces
  character->name[strcspn(character->name, "\n")] =
    '\0'; // Remove the newline character at the end

  strcat(name, character->name);
  strcat(name, ".txt");

  if (fopen(name, "r") == NULL) {

  character->level = 1;

  assign_weapon(character);

  printf("Choose your character's class:\n\n");
  printf("0. %s\n1. %s\n2. %s\n3. %s\n\n> ", classes[0], classes[1],
         classes[2], classes[3]);

  do {
    scanf("%d", &character->character_class);
  } while (character->character_class < 0 || character->character_class > 3);

  switch (character->character_class) {

  case 0:
    character->type = melee;
    break;

  case 1:
    character->type = ranged;
    break;

  case 2:
    character->type = magic_melee;
    break;

  case 3:
    character->type = magic_ranged;
    break;
  }

  character->hp = 100;

  character->world = select_world();

  character->foe = (character->world == thato ? ironjaw : virgy);

  save_data(character, character->name);

  print_player_info(character);

  } else {

  printf("%s already exists, resuming...", character->name);
  load_data(character, character->name);
  }

  printf("\n\nYou've been assigned %s\n\n", weapons[character->weapon_id]);

  return;
}

enum World select_world(void) {
  world_info();

  puts("Which world do you dare to explore?\n[0(thato) / 1(chanda)]");
  int sel;
  do {
  scanf("%d", &sel);
  } while (sel < 0 || sel > 1);

  if (sel == 0) {
  system("clear");
  return thato;
  }

  system("clear");
  return chanda;
}

void print_player_info(const Player *const character) {

  // Print the loaded character data
  printf("%s:\n", character->name);
  printf("Level: %d\n", character->level);
  printf("Weapon: %s\n", character->weapon.name);
  printf("Class: %s\n\n\n", classes[character->character_class]);
  return;
}

void load_foe(Player *const currentFoe, const char *const filename) {

  // Load the foe data from the file into a struct
  char name[PATH_BUF] = "assets/foes/";
  if (currentFoe->world) {
  strcat(name, "chanda/");
  } else {
  strcat(name, "thato/");
  }

  strcat(name, filename);
  strcat(name, ".txt");

  FILE *file = fopen(name, "r");

  // Error Handling
  if (file == NULL) {
  printf("Error: could not open file\n");
  return;
  }

  fgets(currentFoe->name, sizeof(currentFoe->name), file);
  currentFoe->name[strlen(currentFoe->name) - 1] = '\0';

  fscanf(file, "%d", &currentFoe->level);
  fscanf(file, "%d", &currentFoe->character_class);
  fscanf(file, "%d", &currentFoe->hp);
  fscanf(file, "%d", &currentFoe->weapon_id);
  fscanf(file, "%d", &currentFoe->type);

  assign_weapon(currentFoe);

  fclose(file);

  return;
}

bool battle(Player *const character, const char *const foename) {

  Player currentFoe;
  currentFoe.world = character->world;

  load_foe(&currentFoe, foename);
  print_player_info(&currentFoe);

  int calculate_damage(const Player *const, Player *const, const int *const);
  void drop_item(Player *const, Player *const, const int *const);
  int damage;

  character->hp = 100;

  for (int i = 0; i < 100; i++) {

  if (character->hp <= 0) {
    puts("You died, meeeerda");
    return false;
  } else if (currentFoe.hp <= 0) {
    printf("You smashed %s!", currentFoe.name);
    character->level += currentFoe.level;
    return true;
  } else {

    printf("%s: %d hp\n%s: %d hp\n\n", character->name, character->hp,
           currentFoe.name, currentFoe.hp);

    if (i % 2) {

      drop_item(&currentFoe, character, &i);
      damage = calculate_damage(&currentFoe, character, &i);

      printf("\n%s dealt you %i damage\n", currentFoe.name, damage);
      character->hp -= damage;
    } else {

      drop_item(character, &currentFoe, &i);
      damage = calculate_damage(character, &currentFoe, &i);

      printf("\nYou dealt %i damage!\n", damage);
      currentFoe.hp -= damage;
    }
    char z;
    while ((z = getchar()) != '\n')
      ;
  }
  }

  puts("How did you even get this far in a battle?\nI think it would be better "
     "to settle it as a draw ...\n\n");
  character->hp = 100;

  return false;
}

int calculate_damage(const Player *const attacker, Player *const character,
                   const int *const i) {

  srand(time(NULL));
  int damage = attacker->weapon.dmg + rand() % 10;
  int number;

  if (attacker->type == attacker->weapon.type) {
  damage += attacker->weapon.dmg * 2;
  } else if ((attacker->type == ranged &&
            attacker->weapon.type == magic_ranged) ||
           (attacker->type == melee &&
            attacker->weapon.type == magic_melee)) {
  damage += attacker->weapon.dmg;
  }

  switch (attacker->weapon.mod) {

  case none:
  break;

  case poisonus:
  if (character->status != poisoned && (rand() % 4)) {

    character->status = poisoned;
    character->modifiers.poison_start = *i;
  }

  if (character->status == poisoned) {
    if (*i < character->modifiers.poison_start + 6) {
      int poison = MIN_POISON + rand() % MAX_POISON;
      if (*i % 2) {
        printf("The poison affects your body for %d damage!", poison);
      } else {
        printf("The enemy suffers poisoning for %d damage!", poison);
      }
      character->hp -= poison;
    } else {
      character->status = base;
    }
  }
  break;

  case burn:

  if (character->status != burning && (rand() % 4)) {

    character->status = burning;
    character->modifiers.burn_start = *i;
  }

  if (character->status == burning) {
    if (*i < character->modifiers.burn_start + 6) {
      int fire = MIN_BURN + rand() % MAX_BURN;
      if (*i % 2) {
        printf("\nThe flames burn you for %d damage!\n", fire);
      } else {
        printf("\nYour flames burned his flesh for %d damage!\n", fire);
      }
      character->hp -= fire;
    } else {
      character->status = base;
    }
  }
  break;

  case rapid:
  number = MIN_SHURIKEN + rand() % MAX_SHURIKEN;
  printf("Launched %d %s!", number, attacker->weapon.name);
  damage = attacker->weapon.dmg * number;
  break;
  }
  return damage;
}

void drop_item(Player *const user, Player *const used_on,
             const int *const turn) {

  Items item;

  if (rand() % 3) {
  item.type = rand() % 3;
  strcat(item.name, items[item.type]);

  int mod;

  switch (item.type) {
  case health_potion:
    mod = MIN_HEAL + rand() % MAX_HEAL;
    printf("%s used a %s\n%i hp restored\n", user->name, item.name, mod);
    user->hp += mod;
    break;

  case firebomb:
    mod = MIN_BOMB_DMG + rand() % MAX_BOMB_DMG;
    printf("%s threw a bomb at %s for %i damage!\n", user->name,
           used_on->name, mod);
    used_on->hp -= mod;

    if (used_on->status != burning && (rand() % 4)) {

      used_on->status = burning;
      used_on->modifiers.burn_start = *turn;
    }
    break;

  case void_crystal:
    printf("%s life points were swapped with %s!!\n", user->name,
           used_on->name);
    mod = used_on->hp;
    used_on->hp = user->hp;
    user->hp = used_on->hp;
    break;

  default:
    break;
  }
  }
  return;
}

