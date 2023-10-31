#include <stdio.h>
#include <math.h>

double bmi (const double *const weight, const double *const height);
void bmi_value (const double *const bmi);

int main() {

    double weight;
    printf("Insert weight [kg]: ");

    do {
        scanf("%lf", &weight);
    } while (weight < 0);

    double height;
    printf("Insert height [m]: ");

    do {
        scanf("%lf", &height);
    } while (height < 0);

    double bmi_val = bmi(&weight, &height);

    printf("\n\nBMI: %.2f\n", bmi_val);
    bmi_value(&bmi_val);

    return 0;
}

double bmi (const double *const weight, const double *const height) {
    return *weight / pow(*height, 2);
}

void bmi_value (const double *const bmi) {

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