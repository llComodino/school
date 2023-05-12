#include "../lib/data.h"
#include "../lib/info.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

const char *classes[16] = {
    "Warrior",
    "Archer",
    "Assassin",
    "Mage"
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

    // Ask the user informations about his character
    printf("Enter your name, warrior: ");
    fgets(myCharacter->name, sizeof(myCharacter->name), stdin); // Use fgets to store string with spaces
    myCharacter->name[strcspn(myCharacter->name, "\n")] = '\0'; // Remove the newline character at the end
    
    myCharacter->level = 1;
 
    
    printf("Choose your character's class:\n\n");
    printf("0. %s\n1. %s\n2. %s\n3. %s\n\n> ", classes[0], classes[1], classes[2], classes[3]);

    scanf("%d", &myCharacter->character_class);

    save_data(myCharacter, myCharacter->name);

    load_data(loadedCharacter, myCharacter->name);

    print_character_info(loadedCharacter);

    return;
}

void print_character_info(Character *loadedCharacter) {

    // Print the loaded character data
    printf("%s:\n", loadedCharacter->name);
    printf("Level: %d\n", loadedCharacter->level);
    printf("Class: %s\n", classes[loadedCharacter->character_class]);
    return;
}
