#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10

void printMatrix(const int[SIZE][SIZE]);
int checkRows(const int[SIZE][SIZE]);
int checkColumns(const int[SIZE][SIZE]);

int main(void)
{
    srand(time(NULL));

    int matrix[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
        for (int k = 0; k < SIZE; k++)
            matrix[i][k] = 3 - rand() % 10;

    printMatrix(matrix);
    
    int rows = checkRows(matrix);
    int columns = checkColumns(matrix);

    if (rows == 0 && columns == 0)
        printf("Nessuna riga o colonna composta solo da numeri negativi!\n");

    return 0;
}

void printMatrix(const int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d > ", i);
        for (int j = 0; j < SIZE; j++)
            printf("%4d", matrix[i][j]);
        printf("\n");
    }
    printf("\n%44s\n", "^   ^   ^   ^   ^   ^   ^   ^   ^   ^");
    printf("%44s\n", "0   1   2   3   4   5   6   7   8   9");
    printf("\n\n");
}

int checkRows(const int matrix[SIZE][SIZE])
{
    int c = 0;
    bool negative;
    for (int i = 0; i < SIZE; i++)
    {
        negative = true;
        for (int k = 0; k < SIZE; k++)
            if (matrix[i][k] >= 0)
            {
                negative = false;
                break;
            }
        if (negative)
        {
            printf("La riga %d e' composta solo da numeri negativi!\n", i);
            c++;
        }
    }

    if (c > 0)
        return 1;

    return 0;
}

int checkColumns(const int matrix[SIZE][SIZE])
{
    int c = 0;
    bool negative;
    for (int i = 0; i < SIZE; i++)
    {
        for (int k = 0; k < SIZE; k++)
            if (matrix[k][i] >= 0)
            {
                negative = false;
                break;
            }

        if (negative)
        {
            printf("La colonna %d e' composta solo da numeri negativi!\n", i);
            c++;
        }
    }

    if (c > 0)
        return 1;

    return 0;
}