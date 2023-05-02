#include <stdio.h>

#define SIZE 10

void cp1(char * const s1, char * const s2);
void cp2(char * s1, char * s2);

int main(void)
{
    char str1[SIZE];
    char *str2 = "hello";

    cp1(str1, str2);
    printf("Str1: %s\n", str1);

    char str3[SIZE];
    char str4[] = "good bye";

    cp2(str3, str4);
    printf("Str3: %s\n", str3);
}

void cp1(char * const s1, char * const s2)
{
    for (size_t i = 0; (s1[i] = s2[i]) != '\0'; i++);
}

void cp2(char * s1, char * s2)
{
    for (; (*s1 = *s2) != '\0'; ++s1, ++s2);
}
