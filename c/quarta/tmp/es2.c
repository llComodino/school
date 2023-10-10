#include <stdio.h>
#include <stdlib.h>

#define RECORD 7
#define BUFFER 32

int main (void) {
	
	int id, days;
	char *name = (char *) malloc(sizeof(char) * BUFFER);
	double balance;
	
	FILE *file;
	
	if ((file = fopen("record.txt", "r")) == NULL) {
		puts("Error, could not open file");
	} else {
	
		printf("%-10s%-10s%-10s%-10s\n", "ID:", "Name:", "Days:", "Balance:");
		for (int i = 0; i < RECORD && fscanf(file, "%d%s%d%lf", &id, name, &days, &balance) != EOF; i++) {
			printf("%-10d%-10s%-10d%-10.2f0\n", id, name, days, balance);
		}
	}
	
	fclose(file);
	free(name);
	return 0;
}
