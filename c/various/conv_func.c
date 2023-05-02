#include <stdio.h>
#include <math.h>

int binconv(int x);
int ottconv(int y);

int main(void)
{
    int i;
    
    printf("%9s%12s%12s%16s\n", "Decimale:","Binario:","Ottale:","Esadecimale:");
    for (i = 1; i <= 256; i++)
    {
        int binary = binconv(i);
        printf("%9d%12d%12d%16X\n", i, binconv(i), ottconv(binary), i);
    }
}

int binconv(int x)
{
    int bin = 0;
    for(int i = 0; x != 0; x /= 2)
    {
        int temp = x % 2;
        
        if (temp != 0)
            bin += pow(10, i);
            
        i++;
    }
    return bin;    
}

int ottconv(int y)
{
    int oct = 0;
    for(int i = 0; i < 3; i++)
    {
        int temp = y % 1000;
        for (int x = 0; x < 3; temp /= 10)
        {
            if ((temp % 10) == 1)
                oct += (pow(2, x) * pow(10, i));
            x++;
        }
        y /= 1000;
    }
    return oct;
}
