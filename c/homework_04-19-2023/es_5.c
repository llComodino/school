#include <stdbool.h>
#include <stdio.h>

#define BUFFER 32

bool get_string(const bool (*fnptr)(const char *const, size_t size));
bool is_palindrome(const char *const, size_t size);

int main(void) {

  if (get_string(is_palindrome)) {
    puts("String is palindrome!");
  } else {
    puts("String isn't palindrome!");
  }

  return 0;
}

bool get_string(const bool (*fnptr)(const char *const, size_t size)) {

  puts("Insert a string (max 32)");

  char str[BUFFER];

  size_t clear_string(char *const pstr, size_t size);

  int i = 0;
  while ((str[i++] = getchar()) != '\n')
    ;
  str[i - 1] = '\0';

  size_t size = clear_string(str, i - 1);

  if ((fnptr)(str, size)) {
    return true;
  }

  return false;
}

size_t clear_string(char *const pstr, size_t size) {

  size_t index;

  for (size_t i = 0; i < size; i++) {

    if (*(pstr + i) == ' ') {

      for (index = i; *(pstr + index) != ' '; index++)
        ;

      if (*(pstr + index) == ' ') {
        size = index;
        break;
      }

      *(pstr + i) = *(pstr + index);
      *(pstr + index) = ' ';
      size--;
    }
  }

  return size;
}

bool is_palindrome(const char *const pstr, size_t end) {

  for (size_t start = 0; start < end; start++, end) {
    if (*(pstr + start) != *(pstr + --end)) {
      return false;
    }
  }
  return true;
}

