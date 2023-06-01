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
    "The Sinister Steel",       // Magical Daggers + [strong]corruption
    "Orb",                      // Magical Orb + [strong]fire
    
    // Magic [ranged]
    "Cesy Staff",               // Magical Staff + [strong]physical boost
    "Grimoire"  ,               // Enchanted book + [strong]fire
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
    
    // FILE *file = fopen("thato_kehinde.txt", "r");
    // while (file != NULL) {
        // fgets(buffer, sizeof(buffer), file);
        // printf("%s", buffer);
    // }
    
    return;
}

void save_data (Character *const character, const char *const filename) {

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

    fprintf(file, "%s\n", character->name);
    fprintf(file, "%d\n", character->level);
    fprintf(file, "%d\n", character->character_class);
    fprintf(file, "%d\n", character->hp);
    fprintf(file, "%d\n", character->type);
    
    fclose(file);

    return;
}

void load_data (Character *const character, const char *const filename) {
    
    // Load the character data from the file into a struct
    char name[PATH_BUF] = "assets/characters/";
    strcat(name, filename);
    strcat(name, ".txt");

    int value;
    FILE *file = fopen(name, "r");
 
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

    load_weapon(character->weapon);

    fclose(file);

    return;
}

void assign_weapon(Weapons *const weapon) {
    srand(time(NULL));
    short tmp = rand() % 10;

    char path[PATH_BUF] = "assets/weapons/";
    strcat(path, weapons[tmp]);
    strcat(path, ".txt");

    FILE *file = fopen(path, "r");

    weapon->id = tmp;
    fscanf(file, "%s", weapon->name);
    fscanf(file, "%d", weapon->dmg);

}

void create_character (Character *const character) {

    char name[PATH_BUF] = "assets/characters/";

    // Ask the user informations about his character
    printf("Enter your name, warrior: ");
    fgets(character->name, sizeof(character->name), stdin); // Use fgets to store string with spaces
    character->name[strcspn(character->name, "\n")] = '\0'; // Remove the newline character at the end
    
    strcat(name, character->name);
    strcat(name, ".txt");

    if (fopen(name, "r") == NULL) {

        character->level = 1;

        assign_weapon(&character->weapon);

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

    return;
}

void print_character_info(const Character *const character) {

    // Print the loaded character data
    printf("%s:\n", character->name);
    printf("Level: %d\n", character->level);
    printf("Class: %s\n", classes[character->character_class]);
    return;
}

void load_foe(Foes *currentFoe, const char *const filename) {

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
 
    assign_weapon(&currentFoe->weapon);

    fclose(file);

    return;
}

void foe_description(Foes *currentFoe) {
    
    printf("\n\nName: %s\nLevel: %d\nClass: %s\n", currentFoe->name, currentFoe->level, classes[currentFoe->character_class]) ;
}

bool battle (Character *character, const char *const foename) {

    Foes currentFoe;
    load_foe(&currentFoe, foename);
    
    int calculate_character_damage(const Character *const);
    int calculate_foe_damage(const Foes *const);
    int damage;

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
                damage = calculate_foe_damage(&currentFoe);
                printf("\nYou've been dealt %i damage!\n", damage);
                character->hp -= damage;
            } else {
                damage = calculate_character_damage(character);
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

int calculate_character_damage(const Character *const character) {

    srand(time(NULL));
    int damage = character->weapon.dmg + rand() % 10;

    if (character->type == character->weapon.type) {
        damage += character->weapon.dmg * 2;
    } else if ((character->type == ranged && character->weapon.type == magic_ranged) || (character->type == melee && character->weapon.type == magic_melee)) {
        damage += character->weapon.dmg;
    } 
    return damage;
}

int calculate_foe_damage(const Foes *const foe) {

    srand(time(NULL));
    int damage = foe->weapon.dmg + rand() % 10;

    if (foe->type == foe->weapon.type) {
        damage += foe->weapon.dmg * 2;
    } else if ((foe->type == ranged && foe->weapon.type == magic_ranged) || (foe->type == melee && foe->weapon.type == magic_melee)) {
        damage += foe->weapon.dmg;
    }
    return damage;
}
