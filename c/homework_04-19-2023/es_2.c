#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

bool verify (const double * const, const double * const, bool (*pfn)(const double * const n1, const double * const n2));
bool is_multiple (const double * const, const double * const);
bool sum_is_square (const double * const, const double * const);
bool average (const double * const, const double * const);

int main(void) {
    srand(time(NULL));
    puts("The two randomly generated doubles are:");

    double n1 = 1 + rand() % 104;
    double n2 = 1 + rand() % 104;

    printf("%.2lf\t%.2lf\n\n", n1, n2);

    if (verify(&n1, &n2, is_multiple)) {
        puts("No multiples\n");
    }

    if (verify(&n1, &n2, sum_is_square)) {
        puts("Sum isn't square of neither number\n");
    }

    if (verify(&n1, &n2, average)) {
        puts("\t-> Odd");
    } else {
        puts("\t-> Even");
    }

    return 0;
}

bool verify (const double * const pn1, const double * const pn2, bool (*pfn)(const double * const, const double * const)) {
    return (*pfn)(pn1, pn2);
}

bool is_multiple (const double * const pn1, const double * const pn2) {
    bool not_found = 1;

    bool is_double (const double * const, const double * const);
    
    if (*pn1 > *pn2 && fmod(*pn1, *pn2) == 0) {
        not_found = 0;
        printf("\n%.2lf is multiple of %.2lf\n", *pn1, *pn2);

        if (is_double(pn1, pn2)) {
            puts("It's also his double!\n");
        } else {
            puts("But it isn't it's double\n");
        }
    }
    
    if (*pn2 > *pn1 && fmod(*pn2, *pn1) == 0) {
        not_found = 0;
        printf("\n%.2lf is multiple of %.2lf\n", *pn2, *pn1);

        if (is_double(pn2, pn1)) {
            puts("It's also his double!\n");
        } else {
            puts("But it isn't it's double\n");
        }
    }

    return not_found;
}

bool is_double (const double * const pn1, const double * const pn2) {
    return *pn1 * 2 == *pn2;
}

bool sum_is_square (const double * const pn1, const double * const pn2) {
    bool not_found = 1;

    if (sqrt(*pn1 + *pn2) == *pn1) {
        not_found = 0;
        printf("Sum is square root of %.2lf\n\n", *pn1);
    }

    if (sqrt(*pn1 + *pn2) == *pn2) {
        not_found = 0;
        printf("Sum is square root of %.2lf\n\n", *pn2);
    }

    return not_found;
}

bool average (const double * const pn1, const double * const pn2) {
    double avg = (*pn1 + *pn2) / 2;
    printf("Average is: %.2lf", avg);
    return fmod(avg, 2);
}
