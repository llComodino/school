#include "../lib/data.h"
#include "../lib/info.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define PATH_BUF 64
#define BUF 128
#define CLASSES 4
#define WEAPONS 10

const char *weapons[WEAPONS] = {
    
    // Melee
    "Kyrsblade",    // Sword
    "Tanto",        // Knife | + poison
    "Fists",        // Fists | + physical dmg

    // Ranged 
    "Flintlock",         // Flintlock
    "Obsidian Bow",      // Bow + corruption
    "Shuriken",          // Shuriken | low dmg [multiple throws]

    // Magic [melee]
    "Grimoire"  ,               // Enchanted book + [strong]fire
    "Orb",                      // Magical Orb + [strong]fire
    
    // Magic [ranged]
    "Cesy Staff",               // Magical Staff + [strong]physical boost
    "The Sinister Steel",       // Magical Daggers + [strong]corruption
};

const char *classes[CLASSES] = {
    "Warrior",
    "Archer",
    "Assassin",
    "Mage"
};

void world_info (void) {

    char buffer[BUF];
    
    FILE *file = fopen("assets/world_info/thato_kehinde.txt", "r");
    while (file != NULL) {
        fscanf(file, "%s", buffer);
        printf("%s", buffer);
    }

    fclose(file);
    
    file = fopen("assets/world_info/chanda_sung.txt", "r");
    while (file != NULL) {
        fscanf(file, "%s", buffer);
        printf("%s", buffer);
    }

    fclose(file);
    
    return;
}

void save_data (Player *const character, const char *const filename) {

    // Save the character data to a file
    char name[PATH_BUF] = "assets/characters/";
    strcat(name, filename);
    strcat(name, ".txt");

    FILE *file = fopen(name, "w");

    // Error handling
    if (file == NULL) {
        printf("Error: could not open file\n");
        return;
    }

    fprintf(file, "%d\n", character->weapon_id);
    fprintf(file, "%s\n", character->name);
    fprintf(file, "%d\n", character->level);
    fprintf(file, "%d\n", character->character_class);
    fprintf(file, "%d\n", character->hp);
    fprintf(file, "%d\n", character->type);
    
    fclose(file);

    return;
}

void load_data (Player *const character, const char *const filename) {
    
    void load_weapon(Player *const, const char *const);
    // Load the character data from the file into a struct
    char path[PATH_BUF] = "assets/characters/";
    strcat(path, filename);
    strcat(path, ".txt");

    int value;
    FILE *file = fopen(path, "r");
 
    // Error handling
    if (file == NULL) {
        printf("Error: could not open file\n");
        return;
    }

    fgets(character->name, sizeof(character->name), file);
    character->name[strlen(character->name) - 1] = '\0';

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

    player->weapon.name = weapons[player->weapon_id];

    path = "assets/weapons/";
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

    FILE *file = fopen(path, "r");

    player->weapon.id = tmp;
    strcat(player->weapon.name, weapons[tmp]);

    load_weapon(player, const char *const char_path)

    return;
}

void create_character (Player *const character) {

    char name[PATH_BUF] = "assets/characters/";

    // Ask the user informations about his character
    printf("Enter your name, warrior: ");
    fgets(character->name, sizeof(character->name), stdin); // Use fgets to store string with spaces
    character->name[strcspn(character->name, "\n")] = '\0'; // Remove the newline character at the end
    
    strcat(name, character->name);
    strcat(name, ".txt");

    if (fopen(name, "r") == NULL) {

        character->level = 1;

        assign_weapon(character);

        printf("Choose your character's class:\n\n");
        printf("0. %s\n1. %s\n2. %s\n3. %s\n\n> ", classes[0], classes[1], classes[2], classes[3]);

        scanf("%d", &character->character_class);

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

        save_data(character, character->name);

        print_character_info(character);
    } else {
        printf("%s already exists, resuming...", character->name);
        load_data(character, character->name);
    }

    printf("\n\nYou've been assigned %s\n\n", weapons[character->weapon_id]);

    return;
}

void print_character_info(const Player *const character) {

    // Print the loaded character data
    printf("%s:\n", character->name);
    printf("Level: %d\n", character->level);
    printf("Class: %s\n", classes[character->character_class]);
    return;
}

void load_foe(Player *currentFoe, const char *const filename) {

    // Load the foe data from the file into a struct
    char name[PATH_BUF] = "assets/foes/";
    strcat(name, filename);
    strcat(name, ".txt");

    FILE *file = fopen(name, "r");
    int value;

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
 
    assign_weapon(currentFoe);

    fclose(file);

    return;
}

void foe_description(Player *currentFoe) {
    
    printf("\n\nName: %s\nLevel: %d\nClass: %s\n", currentFoe->name, currentFoe->level, classes[currentFoe->character_class]) ;
}

bool battle (Player *character, const char *const foename) {

    Player currentFoe;
    load_foe(&currentFoe, foename);
    
    int calculate_damage(const Player *const, Player *const, int *const, int *const, const int *const);
    int damage;

    int char_poison_start;
    int foe_poison_start;

    int char_burn_start;
    int foe_burn_start;

    for (int i = 0; i < 50; i++) {

        if (character->hp <= 0) {
            puts("Matteo Messina Denaro ti ha sciolto nell'acido");
            character->hp = 100;
            return false;
        } else if (currentFoe.hp <= 0) {
            puts("La polizia ha fermato Denaro prima dell'inevitabile.");
            character->level += currentFoe.level;
            return true;
        } else {

            printf("%s: %d hp\n%s: %d hp\n\n", character->name, character->hp, currentFoe.name, currentFoe.hp);

            if (i % 2) {
                damage = calculate_damage(&currentFoe, character, &char_poison_start, &char_burn_start, &i);

                printf("\nYou've been dealt %i damage!\n", damage);
                character->hp -= damage;
                
            } else {

                damage = calculate_damage(&currentFoe, character, &foe_poison_start, &foe_burn_start, &i);
                printf("\nYou dealt %i damage!\n", damage);
                currentFoe.hp -= damage;
            }      
            char z;
            while ((z = getchar()) != '\n');
        }
    }

    puts("How did you even get this far in a battle?!\nMan, listen, you gotta go, seriously");
    character->hp = 100;
    
    return false;
}

int calculate_damage(const Player *const attacker, Player *const character, int *const char_poisoned_at, int *const char_burned_at, const int *const i) {

    srand(time(NULL));
    int damage = attacker->weapon.dmg + rand() % 10;
    int number;

    if (attacker->type == attacker->weapon.type) {
        damage += attacker->weapon.dmg * 2;
    } else if ((attacker->type == ranged && attacker->weapon.type == magic_ranged) || (attacker->type == melee && attacker->weapon.type == magic_melee)) {
        damage += attacker->weapon.dmg;
    }

    switch (attacker->weapon.mod) {

        case none:
            break;

        case poisonus:
            if (character->status != poisoned && (rand() % 4)) {
                    
                character->status = poisoned;
                *char_burned_at = *i;
            }
                
            if (character->status == poisoned) {
                if (*i < *(char_poisoned_at) + 6) {
                    int poison = 2 + rand() % 4;
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
        
        case firing:
            
            if (character->status != burning && (rand() % 4)) {
                    
                character->status = burning;
                *char_burned_at = *i;
            }
                
            if (character->status == burning) {
                if (*i < *(char_burned_at) + 6) {
                    int fire = 2 + rand() % 4;
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
            number = 1 + rand() % 4;
            printf("He launches %d %s!", number, attacker->weapon.name);
            damage = attacker->weapon.dmg * number;
            break;
    }
    return damage;
}
