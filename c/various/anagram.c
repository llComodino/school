#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHAR 64

int main(void)
{
	char w1[MAX_CHAR];
	printf("Inserire la prima parola: ");
	scanf("%s", &w1);
	
	char w2[MAX_CHAR];
	printf("Inserire la prima parola: ");
	scanf("%s", &w2);
	
	if (strlen(w1) == strlen(w2))
	{
		char w1cp[MAX_CHAR];
		strcpy(w1cp, w1);
	
		char w2cp[MAX_CHAR];
		strcpy(w2cp, w2);
		
		int i;
		int k;
		
		for(i = 0; i < strlen(w1); i++)
			for(k = i; k < strlen(w1); k++)
			{
				if (w1[i] = w2[k])
				{
					char temp = w2[i];
					w2[i] = w2[k];
					w2[k] = temp;
				}
			}
			
		bool anagram = true;
		for (i = 0; i < strlen(w1); i++)
			if (w1[i] != w2[i])
				anagram = false;
			
		if (anagram == true)
			printf("%s\t=\t%s", w1cp, w2cp);
		
		else
			printf("No biches :(");
	}
	return 0;
}
