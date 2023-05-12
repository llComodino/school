#ifndef DATA_H
#define DATA_H

typedef struct {
    char name[100];
    int level;
    int character_class;
} Character;

void load_data (Character * character, const char *const filename);

void create_character (Character *myCharacter, Character *loadedCharacter);

#endif // !DATA_H
