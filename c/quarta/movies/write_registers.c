#include <stdio.h>
#include <stdlib.h>

typedef enum {
  ACTION,
  COMEDY,
  DRAMA,
  HORROR,
  MYSTERY,
  ROMANCE,
  SCIFI,
  THRILLER,
  WESTERN
} Genre;

typedef struct {
  int id;
  char name[32];
  Genre genre;
  int year;
  int votes;
} Movie;

int main(void) {

  FILE *fp = fopen("movies.dat", "wb+");
  Movie movie = {0, "", 0, 0, 0};
  for (size_t i = 0; i < 10; i++) {
    movie.id = i + 1;
    movie.votes = 0;

    // Ask for name (with spaces), genre and year
    printf("Name: ");
    scanf(" %[^\n]s", movie.name);
    printf("Genre: ");
    scanf("%d", &movie.genre);
    printf("Year: ");
    scanf("%d", &movie.year);

    // Write to FILE
    fwrite(&movie, sizeof(Movie), 1, fp);
  }
}
