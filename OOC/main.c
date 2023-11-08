#include "string_manipulation.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER 100

int main (void) {
    
    struct String *string = new_string();
   
    printf("Enter a string: ");
    string->get_string(string, BUFFER);
  
    printf("String: %s\n", string->str);
    printf("Length: %d\n", string->length(string));
    string->to_upper(string);
    printf("To Upper: %s\n", string->str);
    string->to_lower(string);
    printf("To Lower: %s\n", string->str);

    string->clear_string(string);

    string->from_int(string, 4523);
    printf("From Int: %s\n", string->str);

    string->clear_string(string);

    string->from_double(string, 63.28);
    printf("From Double: %s\n", string->str);

    string->delete_string(string);
    
    free(string);
    return 0;
}
