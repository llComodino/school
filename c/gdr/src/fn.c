#include "../lib/data.h"
#include "../lib/info.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const char *classes[16] = {
    "Warrior",
    "Archer",
    "Assassin",
    "Mage"
};

const char *weapons[16] = {
    "Dagger", 
    "Crossbow", 
    "Magic Book", 
    "War Axe"
};

void world_info (void) {
    
    FILE *fp;
    fp = fopen("../assets/world_info/thato_kehinde.txt", "r");
    
    char buf[BUF];
    while (fgets(buf, BUF, fp) != NULL) {
        printf("%s", buf);
    }

    fclose(fp);

    return;
}

void save_data (Character * character, const char *const filename) {

    // Save the character data to a file
    char name[64] = "assets/characters/";
    strcat(name, filename);
    strcat(name, ".txt");

    FILE *file = fopen(name, "w");
    fwrite(character, sizeof(Character), 1, file);
    fclose(file);

    return;
}

void load_data (Character * character, const char *const filename) {
    
    // Load the character data from the file into a struct
    char name[64] = "assets/characters/";
    strcat(name, filename);
    strcat(name, ".txt");

    FILE *file = fopen(name, "r");
    
    if (file == NULL) {
        printf("Error: could not open file\n");
        return;
    }

    fread(character, sizeof(Character), 1, file);
    fclose(file);

    return;
}

void create_character (Character *myCharacter, Character *loadedCharacter) {

    char name[64] = "../assets/characters/";

    // Ask the user informations about his character
    printf("Enter your name, warrior: ");
    fgets(myCharacter->name, sizeof(myCharacter->name), stdin); // Use fgets to store string with spaces
    myCharacter->name[strcspn(myCharacter->name, "\n")] = '\0'; // Remove the newline character at the end
    
    strcat(name, myCharacter->name);
    strcat(name, ".txt");

    if (fopen(name, "r") == NULL) {

        myCharacter->level = 1;
        int weapon = rand() % 4;
        Weapons characterWeapon = {
            weapon, 
            5, 
            false, 
            false
        }; 

        myCharacter->weapon = characterWeapon;

        printf("Choose your character's class:\n\n");
        printf("0. %s\n1. %s\n2. %s\n3. %s\n\n> ", classes[0], classes[1], classes[2], classes[3]);

        scanf("%d", &myCharacter->character_class);

        switch (myCharacter->character_class) {

            case 0:
                myCharacter->ranged = false;
                myCharacter->magic = false;
            break;

            case 1:
                myCharacter->ranged = true;
                myCharacter->magic = false;
            break;

            case 2:
                myCharacter->ranged = false;
                myCharacter->magic = true;
            break;

            case 3:
                myCharacter->ranged = true;
                myCharacter->magic = true;
            break;
        }

        myCharacter->hp = 100;

        save_data(myCharacter, myCharacter->name);

        load_data(loadedCharacter, myCharacter->name);

        print_character_info(loadedCharacter);
    }
 
    printf("%s already exists, resuming...", myCharacter->name);

    return;
}

void print_character_info(Character *loadedCharacter) {

    // Print the loaded character data
    printf("%s:\n", loadedCharacter->name);
    printf("Level: %d\n", loadedCharacter->level);
    printf("Class: %s\n", classes[loadedCharacter->character_class]);
    return;
}

void load_foe(Foes *currentFoe, const char *const filename) {

    // Load the character data from the file into a struct
    char name[64] = "assets/foes/";
    strcat(name, filename);
    strcat(name, ".txt");

    FILE *file = fopen(name, "r");
    
    if (file == NULL) {
        printf("Error: could not open file\n");
        return;
    }

    fgets(currentFoe->name, 32, file);
    
    currentFoe->name[21] = '\0';
    currentFoe->level = 1;
    currentFoe->character_class = 2;
    currentFoe->hp = 100;
    currentFoe->alive = 1;

    int weapon = rand() % 4;
    
    Weapons foeWeapon = {
        weapon, 
        5, 
        true, 
        false
    };

    currentFoe->weapon = foeWeapon;
    fclose(file);

    return;
}

void foe_description(Foes *currentFoe) {
    
    // Print the current foe informations
    load_foe(currentFoe, "matteo_messina_denaro");

    printf("\n\nName: %s\nLevel: %d\nClass: %s\n", currentFoe->name, currentFoe->level, classes[currentFoe->character_class]) ;
}

bool battle (Character *myCharacter, Foes *currentFoe) {

    srand(time(NULL));

    for (int i = 0; i < 50; i++) {

        if (myCharacter->hp <= 0) {
            puts("Matteo Messina Denaro ti ha sciolto nell'acido");
            return false;
        } else if (currentFoe->hp <= 0) {
            puts("La polizia ha fermato Denaro prima dell'inevitabile.");
            return true;
        } else {

            printf("%s: %d hp\n%s: %d hp\n\n", myCharacter->name, myCharacter->hp, currentFoe->name, currentFoe->hp);

            int damage = 1 + rand() % 20;

            if (damage == 20) {
                puts("Falcon Punch!!");
                damage *= 2;
            }
            
            if (i % 2) {
                myCharacter->hp -= damage + currentFoe->weapon.dmg;
            } else {
                currentFoe->hp -= damage + myCharacter->weapon.dmg;
            }
            
            char z;
            while ((z = getchar()) != '\n');
        }
    }

    puts("This battle has been raging for a while now, how about we kill you?");
    return false;
}
