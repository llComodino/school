#include <stdio.h>
#define BUFFER 20

void string_reverse (char *, size_t, size_t);
size_t strlength (const char * const);

int main (void) {

    char str[BUFFER];
    puts("Insert string");
    scanf("%s", str);

    printf("Original string: %s\n", str);

    printf("Reversed string: ");
    string_reverse(str, 0, strlength(str) - 1);
    puts("");

    return 0;
}

void string_reverse (char * const pstr, size_t index, size_t size) {
    
    if (*(pstr + index) == '\0') {
        return;
    }
    
    printf("%c", *(pstr + (size - index)));
    
    string_reverse(pstr, index + 1, size);
    
    return;
}

size_t strlength (const char * const pstr) {

    size_t i;
    for (i = 0; *(pstr + i) != '\0'; i++);
    
    return i;
}
