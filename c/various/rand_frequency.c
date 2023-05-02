#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int f[6] = {0, 0, 0, 0, 0, 0};

    srand(time(NULL));

    for (int i = 1; i <= 6000; i++)
    {
        int face = 1 + (rand() % 6);
        
        switch(face)
        {
            case 1:
                ++f[0];
                break;

            case 2:
                ++f[1];
                break;

            case 3:
                ++f[2];
                break;

            case 4:
                ++f[3];
                break;

            case 5:
                ++f[4];
                break;

            case 6:
                ++f[5];
                break;

            default:
                printf("ERROR!");
                break;
        }    
    }
    printf("%s%13s\n   1%13d\n   2%13d\n   3%13d\n   4%13d\n   5%13d\n   6%13d", "Face", "Frequency", f[0], f[1], f[2], f[3], f[4], f[5]);
}