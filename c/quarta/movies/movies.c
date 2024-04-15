/*
 * dovete organizzare una serata tra amici
 * tutti i partecipanti (in totale 10) potranno proporre tre film diversi in una
 * lista da 10 Ogni film sara immagazzinato in una struct con i seguenti dati:
 * - Titolo del film
 * - Genere
 * - Anno di uscita
 *
 * Create una funzione che permetta ad ogni amico di fare le proprie tre scelte
 * Create una funzione di tipo void che calcoli la media dei film scelti \
 * e mostri a schermo quelli che hanno ricevuto piu voti
 *
 * non dimenticare popcorn e patatine
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOVIES 10
#define FRIENDS 10
#define CHOICES 3
#define BUFFER 32
#define GENRES 9

typedef enum {
  ACTION,
  ADVENTURE,
  COMEDY,
  DRAMA,
  HORROR,
  MUSICAL,
  SCIFI,
  THRILLER,
  WESTERN
} Genres;

char *genres[GENRES] = {"Action",  "Adventure", "Comedy",   "Drama",  "Horror",
                        "Musical", "Sci-Fi",    "Thriller", "Western"};

typedef struct {
  int id;
  char title[BUFFER];
  Genres GENRE;
  int year;
  int votes;
} Movie;

typedef struct {
  char name[BUFFER];
  Movie movies[CHOICES];
} Friend;

void insertMovie(Movie *movie, FILE *movies_file);
void printMovies(Movie *movies);
void chooseMovie(Friend *friend, Movie *movies);
void mostVoted(Movie *movies);

int main(void) {

  Movie movies[MOVIES] = {{0, "", 0, 0, 0}};
  Friend friends[FRIENDS] = {{"", movies[0]}};

  FILE *movies_file = NULL;

  if ((movies_file = fopen("movies.dat", "rb")) == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  for (size_t i = 0; i < MOVIES; i++) {
    insertMovie(&movies[i], movies_file);
  }

  fclose(movies_file);

  printf("Movies list:\n");
  printMovies(&movies[0]);

  for (size_t i = 0; i < FRIENDS; i++) {

    printf("Insert friend %lu name: ", i + 1);
    scanf("%s", friends[i].name);

    for (size_t j = 0; j < CHOICES; j++) {
      printMovies(&movies[0]);
      printf("Choose movie n. %lu: ", j + 1);
      chooseMovie(&friends[i], &movies[0]);
    }
  }

  mostVoted(movies);

  return 0;
}

void insertMovie(Movie *movie, FILE *movies_file) {

  Movie movie_tmp = {0, "", 0, 0, 0};
  fread(&movie_tmp, sizeof(Movie), 1, movies_file);

  movie->id = movie_tmp.id;
  movie->GENRE = movie_tmp.GENRE;
  movie->year = movie_tmp.year;
  movie->votes = movie_tmp.votes;
  strcpy(movie->title, movie_tmp.title);

  return;
}

void printMovies(Movie *movie) {

  for (size_t i = 0; i < MOVIES; i++) {
    printf("%10s %d\n%10s %s\n%10s %s\n%10s %d\n\n", "ID:", movie[i].id,
           "Title:", movie[i].title, "Genre:", genres[movie[i].GENRE],
           "Year:", movie[i].year);
  }
  return;
}

void chooseMovie(Friend *friend, Movie *movies) {

  int choice = 0;

  do {
    scanf("%d", &choice);
  } while (choice < 1 || choice > MOVIES);

  friend->movies[choice - 1] = movies[choice - 1];
  movies[choice - 1].votes++;

  return;
}

void mostVoted(Movie *movies) {

  int most_voted = 0;
  for (size_t i = 0; i < MOVIES; i++) {
    if (movies[i].votes > most_voted) {
      most_voted = i;
    }
  }

  printf("\n\nMost voted movie: %s\n\n", movies[most_voted].title);

  return;
}

