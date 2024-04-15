#include <math.h>
#include <stdio.h>
#include <string.h>

#define BUFFER 16
#define MONTHS 12
#define CUR_YEAR 2023
#define MIN_YEAR 1900
#define SEXS 2

typedef enum {
  JAN,
  FEB,
  MAR,
  APR,
  MAY,
  JUN,
  JUL,
  AUG,
  SEP,
  OCT,
  NOV,
  DEC
} Month;

const char *months[MONTHS] = {"January",   "February", "March",    "April",
                              "May",       "June",     "July",     "August",
                              "September", "October",  "November", "December"};

typedef enum { MALE, FEMALE } Sex;

const char *sexs[SEXS] = {"Male", "Female"};

typedef struct {
  unsigned int day;
  Month month;
  unsigned int year;
} BirthDate;

typedef struct {
  char name[BUFFER];
  char surname[BUFFER];
  Sex sex;
  BirthDate date_of_birth;
  double height;
  double weight;
} HealthProfile;

void print_months(void);
void create_profile(HealthProfile *const profile);
void print_profile(HealthProfile *const profile);
void save_profile(HealthProfile *const profile);
void print_saved_profiles(void);
unsigned int get_day(Month month, const int *bisestile);
unsigned int max_bpm(const unsigned int *const age);
unsigned int min_bpm(const unsigned int max_bpm);
unsigned int max_nor_bpm(const unsigned int max_bpm);
double bmi(const double *const weight, const double *const height);
void bmi_value(const double *const bmi);

int main(void) {

  HealthProfile patient;
  create_profile(&patient);
  print_profile(&patient);

  save_profile(&patient);

  print_saved_profiles();

  getc(stdin);

  unsigned int age = CUR_YEAR - patient.date_of_birth.year;

  printf("%8s%6u\n%8s%6u\n", "Age:", age, "Max BPM:", max_bpm(&age));
  printf("\nNormal BPM range\n%8s%u\n%8s%u\n\n",
         "Start:", min_bpm(max_bpm(&age)), "End:", max_nor_bpm(max_bpm(&age)));

  double bmi_val = bmi(&patient.weight, &patient.height);

  printf("\n\nBMI: %.2f\n", bmi_val);
  bmi_value(&bmi_val);

  return 0;
}

void create_profile(HealthProfile *const patient) {

  char buffer[BUFFER];
  printf("Enter name: ");
  fgets(buffer, BUFFER, stdin);
  buffer[strlen(buffer) - 1] = '\0';
  strcpy(patient->name, buffer);

  printf("Enter surname: ");
  fgets(buffer, BUFFER, stdin);
  buffer[strlen(buffer) - 1] = '\0';
  strcpy(patient->surname, buffer);

  puts("\n");

  int bisestile;
  unsigned int month;
  puts("Insert your month of birth:");
  print_months();
  printf("> ");
  do {
    scanf("%d", &month);
  } while (month < 1 || month > MONTHS);

  patient->date_of_birth.month = month;

  puts("\n");

  puts("Insert your year of birth:");
  printf("> ");
  do {
    scanf("%d", &patient->date_of_birth.year);
  } while (patient->date_of_birth.year < MIN_YEAR ||
           patient->date_of_birth.year > CUR_YEAR);

  patient->date_of_birth.year % 4 == 0 ? (bisestile = 1) : (bisestile = 0);

  printf("%d\n", bisestile);

  patient->date_of_birth.day =
      get_day(patient->date_of_birth.month, &bisestile);

  puts("\n");

  unsigned int sex;
  printf("Insert your sex\n1. Male\n2. Female\n> ");

  do {
    scanf("%d", &sex);
  } while (sex < 1 || sex > 2);
  patient->sex = sex;

  puts("\n");

  printf("Insert your height [m] > ");

  do {
    scanf("%lf", &patient->height);
  } while (patient->height < 0);

  printf("Insert your weight [kg] > ");

  do {
    scanf("%lf", &patient->weight);
  } while (patient->weight < 0);

  return;
}

void print_profile(HealthProfile *const profile) {

  printf("%s %s\n%s\n%u of %s, %u\n%.2f m\n%.2f kg\n\n", profile->surname,
         profile->name, sexs[profile->sex - 1], profile->date_of_birth.day,
         months[profile->date_of_birth.month - 1], profile->date_of_birth.year,
         profile->height, profile->weight);

  return;
}

void print_months(void) {
  for (size_t i = 0; i < MONTHS; i++) {
    printf("%lu. %10s\n", i + 1, months[i]);
  }
}

unsigned int get_day(Month month, const int *const bisestile) {

  unsigned int day;
  switch (month - 1) {
  case NOV:
  case APR:
  case JUN:
  case SEP:
    for (size_t i = 0; i < 30; i++) {
      printf("%4lu", i + 1);

      if (!(i % 10)) {
        puts("");
      }
    }

    printf("> ");
    do {
      scanf("%d", &day);
    } while (day < 1 || day > 30);

    break;

  case JAN:
  case MAR:
  case MAY:
  case JUL:
  case AUG:
  case OCT:
  case DEC:
    for (size_t i = 0; i < 31; i++) {
      printf("%4lu", i + 1);

      if (!(i % 10)) {
        puts("");
      }
    }

    printf("> ");
    do {
      scanf("%d", &day);
    } while (day < 1 || day > 31);

    break;

  case FEB:
    if (*bisestile) {
      for (size_t i = 0; i < 29; i++) {
        printf("%4lu", i + 1);

        if (!(i % 10)) {
          puts("");
        }
      }

      printf("> ");
      do {
        scanf("%d", &day);
      } while (day < 1 || day > 29);

    } else {

      for (size_t i = 0; i < 28; i++) {
        printf("%4lu", i + 1);

        if (!(i % 10)) {
          puts("");
        }
      }

      printf("> ");
      do {
        scanf("%d", &day);
      } while (day < 1 || day > 28);
    }
    break;

  default:
    puts("Error in get_day");
    break;
  }

  return day;
}

unsigned int max_bpm(const unsigned int *const age) {

  printf("Test: %u", *age);
  return 220 - (*age);
}

unsigned int min_bpm(const unsigned int max_bpm) { return max_bpm / 100 * 50; }

unsigned int max_nor_bpm(const unsigned int max_bpm) {
  return max_bpm / 100 * 80;
}

double bmi(const double *const weight, const double *const height) {
  return *weight / pow(*height, 2);
}

void bmi_value(const double *const bmi) {

  if (*bmi < 18.5f) {
    printf("Sottopeso\n");
  } else if (*bmi >= 18.5f && *bmi <= 24.9f) {
    printf("Normale\n");
  } else if (*bmi >= 25.0f && *bmi <= 29.9f) {
    printf("Sottopeso\n");
  } else {
    printf("Obeso\n");
  }

  return;
}

void save_profile(HealthProfile *const profile) {

  FILE *file = NULL;

  if ((file = fopen("profiles.dat", "ab")) == NULL) {
    puts("Error opening file");
  } else {
    fwrite(profile, sizeof(HealthProfile), 1, file);
    fclose(file);
  }

  return;
}

void print_saved_profiles(void) {

  FILE *file = NULL;
  HealthProfile profile;

  if ((file = fopen("profiles.dat", "rb")) == NULL) {
    puts("Error opening file");
  } else {
    while (!feof(file)) {
      fread(&profile, sizeof(HealthProfile), 1, file);
      print_profile(&profile);
    }
    fclose(file);
  }

  return;
}
