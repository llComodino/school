// Making an hashtable to store the months' names
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 12
#define BUFFER 16

// hash function
size_t hash (const char *const p);

int main (void) {
    
    char *months[SIZE] = {
        "January", 
        "February", 
        "March", 
        "April", 
        "May", 
        "June", 
        "July", 
        "August",
        "September", 
        "October", 
        "November", 
        "December"
    };

    char *months_abbreviated[SIZE] = {
        "Jan", 
        "Feb", 
        "Mar", 
        "Apr", 
        "May", 
        "Jun", 
        "Jul", 
        "Aug",
        "Sep", 
        "Oct", 
        "Nov", 
        "Dec"
    };
    
    // Iterate SIZE times to hash all the months 
    for (int i = 0; i < SIZE; ++i) {
        size_t index = hash(months[i]);
        printf("%s\t%zu\n", months[i], index);
    }

    // Iterate SIZE times to hash all the months_abbreviated 
    for (int i = 0; i < SIZE; ++i) {
        size_t index = hash(months_abbreviated[i]);
        printf("%s\t%zu\n", months_abbreviated[i], index);
    }
    
    return EXIT_SUCCESS;
}

size_t hash (const char *const p) {
    // Hashing the string 
    size_t hash_value = 0;
    for (const char *q = p; *q != '\0'; ++q) {
        hash_value = hash_value * 31 + *q;
    }
    return hash_value % SIZE;
}
