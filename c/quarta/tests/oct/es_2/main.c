#include <stdio.h>

#define MONTHS 12
#define CUR_YEAR 2023
#define MIN_YEAR 1900

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

const char *months[MONTHS] = {
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

void print_months (void);
unsigned int get_day (Month month, const int *bisestile);
unsigned int max_bpm (const unsigned int *const age);
unsigned int min_bpm (const unsigned int max_bpm);
unsigned int max_nor_bpm (const unsigned int max_bpm);

int main(void) {

    int bisestile;
    unsigned int month, day, year;
    puts("Hello, user!\nInsert your month of birth:");
    print_months();
    puts("> ");
    do {
        scanf("%d", &month);
    } while (month < 1 || month > MONTHS);

    Month month_enum = month - 1;

    puts("Insert your year of birth:");
    puts("> ");
    do {
        scanf("%d", &year);
    } while (year < MIN_YEAR || month > CUR_YEAR);

    year % 4 == 0 ? (bisestile = 1) : (bisestile = 0);

    day = get_day (month_enum, &bisestile);

    unsigned int age = CUR_YEAR - year;

    printf("%8s%6u\n%8s%6u\n", "Age:", age, "Max BPM:", max_bpm(&age));
    printf("\nNormal BPM range\n%8s%u\n%8s%u\n\n", "Start:", min_bpm(max_bpm(&age)), "End:", max_nor_bpm(max_bpm(&age)));
    return 0;
}

void print_months (void) {
    for (size_t i = 0; i < MONTHS; i++) {
        printf("%llu. %10s\n", i + 1, months[i]);
    }
}

unsigned int get_day (Month month, const int *const bisestile) {

    unsigned int day;
    switch (month) {
        case NOV:
        case APR:
        case JUN:
        case SEP:
            for (size_t i = 0; i < 30; i++) {
                printf("%4llu", i + 1);

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
                printf("%4llu", i + 1);

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
            if (bisestile) {
                for (size_t i = 0; i < 29; i++) {
                    printf("%4llu", i + 1);

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
                    printf("%4llu", i + 1);

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

unsigned int max_bpm (const unsigned int *const age) {

    printf("Test: %u", *age);
    return 220 - (*age);
}

unsigned int min_bpm (const unsigned int max_bpm) {
    return max_bpm / 100 * 50;
}

unsigned int max_nor_bpm (const unsigned int max_bpm) {
    return max_bpm / 100 * 80;
}