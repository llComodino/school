// Attraverso una costantesimbolica size definite una dimensione di 10
// Dichiarate due vettori double a[] e b[], di dimensione SIZE
// Scrivere una funzione stampa vettore
// Gli array saranno compilati dall'utente
// Attraverso una funzione merge dovrete creare un vettore risultante c[]
// Frutto dell'unione di tutti i valori dispari di a[] e b[]
// Prima di utilizzare la funzione merge utilizzare all'interno di essa
// una funzione chiamata bubbleSort
// Dopo la funzione merge ordinare attraverso bubble sort anche c[]
#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

void printArray(const double v[], const int dim);
void bubbleSort(double v[], int dim);
int odd(const double v[]);
void merge(double a[], double b[], int odds);

int main(void)
{
	double a[SIZE], b[SIZE];
 	for(int i = 0; i < SIZE; i++)
    	{
      		printf("%d > ", i);
      		scanf("%lf%lf", &a[i], &b[i]);
    	}
  
 	int odds = odd(a) + odd(b);
  
  	printArray(a, SIZE);
  	printArray(b, SIZE);

  	merge(a, b, odds);
}

int odd(const double v[])
{
  	int oddCount = 0;
  	for(int i = 0; i < SIZE; i++)
    		if ((int)v[i] % 2 == 1)
      			oddCount++;
  
  	return oddCount;
}

void printArray(const double v[], const int dim)
{
  	for (int i = 0; i < dim; i++)
    		printf("%10.2lf", v[i]);

  	printf("\n\n");
}

void merge(double a[], double b[], int odds)
{
  	bubbleSort(a, SIZE);
  	bubbleSort(b, SIZE);

  	double c[odds];
  	int counter = 0;
  
	for(int i = 0; i < SIZE; i++)
    	{
      		if ((int)a[i] % 2 == 1)
      		{
        		c[counter] = a[i];
        		counter++;
      		}
      		if ((int)b[i] % 2 == 1)
      		{
        		c[counter] = b[i];
        		counter++;
      		}
    	}
  	bubbleSort(c, odds);
  	printArray(c, odds);
}

void bubbleSort(double v[], int dim)
{
  	bool swap;
  	do {
    		swap = false;
    		for (int i = 0; i < dim - 1; i++)
      		{
        		if (v[i] > v[i+1])
        		{
          			double temp = v[i];
          			v[i] = v[i+1];
          			v[i+1] = temp;
          			swap = true;
        		}
      		}
    	} while (swap == true);
}
