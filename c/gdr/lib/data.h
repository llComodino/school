#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char name[100];
    int age;
    char gender;
} Character;

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
    
    printf("Enter your character's age: ");
    scanf("%d", &myCharacter->age);
    
    printf("Enter your character's gender (M/F): ");
    scanf(" %c", &myCharacter->gender);

    save_data(myCharacter, myCharacter->name);

    load_data(loadedCharacter, myCharacter->name);

    // Print the loaded character data
    printf("Loaded character:\n");
    printf("Name: %s\n", loadedCharacter->name);
    printf("Age: %d\n", loadedCharacter->age);
    printf("Gender: %c\n", loadedCharacter->gender);
}
