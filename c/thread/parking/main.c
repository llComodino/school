#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define MAX_COUNTERS 5
#define TIMES 15

typedef struct {
  int time;
  int id;
} car_timer_t;

sem_t timer_semaphore;
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;

void* run_timer(void* arg);
void init_times(int* times, size_t len);

int
main(void)
{
  int* times = (int*)malloc(sizeof(int) * TIMES);
  init_times(times, TIMES);

  sem_init(&timer_semaphore, 0, MAX_COUNTERS);

  pthread_t* threads = malloc(TIMES * sizeof(pthread_t));

  for (int i = 0; i < TIMES; i++) {
    car_timer_t* timer = malloc(sizeof(car_timer_t));
    timer->time = times[i];
    timer->id = i + 1;

    pthread_create(&threads[i], NULL, run_timer, timer);
  }

  for (int i = 0; i < TIMES; i++) {
    pthread_join(threads[i], NULL);
  }

  free(threads);
  sem_destroy(&timer_semaphore);
  pthread_mutex_destroy(&print_mutex);

  return 0;
}

void*
run_timer(void* arg)
{
  car_timer_t* timer = (car_timer_t*)(arg);

  if ( timer == NULL ) {
    fprintf(stderr, "%s\n", "Error: could not allocate memory");
    exit(2);
  }

  sem_wait(&timer_semaphore);

  pthread_mutex_lock(&print_mutex);
  printf("timer %d started. Counting down %d seconds\n", timer->id, timer->time);
  pthread_mutex_unlock(&print_mutex);

  sleep(timer->time);

  pthread_mutex_lock(&print_mutex);
  printf("timer %d completed after %d seconds\n", timer->id, timer->time);
  pthread_mutex_unlock(&print_mutex);

  sem_post(&timer_semaphore);

  free(timer);

  return NULL;
}

void
init_times(int* times, size_t len)
{
  for (size_t i = 0; i < len; i++) *(times + i) = 1 + rand() % 16;
}
