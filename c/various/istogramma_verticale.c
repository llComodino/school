// Dieg Gila        3Ein
#include <stdio.h>
#include <stdbool.h>

int sort_max(int vett[], int dim);

int main()
{
    int v[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Inserire il valore %d: ", i + 1);
        scanf("%d", &v[i]);
    }
    int a[5] = {v[0], v[1], v[2], v[3], v[4]};

    int d = sizeof(v) / 4;
    int max = sort_max(v, d);
    int temp = max;
    
    printf("%d", max);
    printf("\n\n");

    for (int i = 0; i < max; i++)
    {
        for (int x = 0; x < 5; x++)
        {
            if (a[x] < temp)
                printf("  ");
            else
                printf("+ ");
        }
        temp--;
        printf("\n");
    }
}

int sort_max(int vett[], int dim)
{
    bool scambi;
	do {
		scambi = false;
		for(int x = 0; x < dim - 1; x++)
			if (vett[x+1] < vett[x])
			{
				int temp = vett[x];
				vett[x] = vett[x+1];
				vett[x+1] = temp;
				scambi = true;
			}
	} while (scambi == true);
    return vett[dim - 1];
}