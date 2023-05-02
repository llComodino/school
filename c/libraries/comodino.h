#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long binconv(int x)
{
  int rem, temp = 1;
  long binary = 0;
  
  while (x != 0)
  {
    rem = x %2;
    x = x / 2;
    binary = binary + rem * temp;
    temp = temp * 10;
  }
  
  return binary;
}

int decconv(long long n)
{
  int dec = 0, rem;

  for (int i = 0; n!=0; ++i)
  {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
  }

  return dec;
}

long int factorial(int n)
{
  if (n>=1)
    return n*factorial(n-1);

  if (n == 0)
    return 1;

  if (n < 0)
    printf("ERRORE!\nIl fattoriale di un numero negativo non esiste\n\n");
}

float avg(int x, float y)
{
  return y / x;
}

void rhombus()
{
  int x, n;
  printf("Inserire la larghezza del rombo: ");
  scanf("%d", &n);

  for(int i = 1; i < n; i++)
  {
    for(x = 1; x <= n - i; x++)
      printf(" ");
        
    for(int y = x; y <= n; y++)
      printf("* ");
    
    printf("\n");
  }

  for(int i = n; i >= 1; i--)
  {
    for(x = 1; x <= n - i; x++)
      printf(" ");
    
    for(int y = x; y <= n; y++)
      printf("* ");
    
    printf("\n");
  }
}

void is_armstrong(float n)
{
  int c = 0;
  float tot = 0;

  for (int i = n; i != 0; i /= 10)
    c++;
  
  for (int i = n; i != 0; i /= 10)
    tot += pow(i % 10, c);
  
  if (tot == n)
    printf("Il numero inserito e' un numero di Armstrong\n\n");

  else
    printf("Il numero inserito non e' un numero di Armstrong\n\n");
}

void is_power_of(int n, int base)
{
  int pot;
  for (int i = 0; pot != n; i++)
  {
    if (pow(base, i) < n)
      continue;
    if (pow(base, i) == n)
    {
      pot = n;
      printf("Il numero e' una potenza di %d\nCorrisponde a 4^%d", base, i);
    }
    if (pow(base, i) > n)
    {
      printf("Il numero non e' una potenza di %d", base);
      break;
    }
  }
}