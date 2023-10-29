/*
 * Vi hanno incaricato di controllare la validita' di alcuni assegni
 * Sviluppate un sistema attraverso un menu:
 * 1) Inserimento assegno
 * 2) Verifica assegno
 *     - In caso non sia valido, stampare il motivo
 * 3) Depositare la somma indicata sull'assegno
 * 4) Esci
 *
 * Ogni assegno dovra avere:
 * - Nome
 * - Cognome
 * - Importo
 * - Numero identificativo di 9 cifre
 *
 * Il controllo verra effetuato controllando che:
 * - Le 9 cifre siano nell'ordine corretto
 * 
 * Per ogni assegno non valido dovete stampare:
 * - Nome
 * - Cognome 
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ID 900000000
#define MIN_ID 100000000
#define MAX_BALANCE 100000000
#define MIN_BALANCE 100
#define NAME_BUF 16

typedef struct {
    char holder_name[NAME_BUF];
    char holder_surname[NAME_BUF];
    char dest_name[NAME_BUF];
    char dest_surname[NAME_BUF];
    double balance;
    unsigned int id;
    bool verified;
} Check;

typedef struct {
    char name[NAME_BUF];
    char surname[NAME_BUF];
    double balance;
    unsigned int id;
    Check check;
} User;

bool insert_check (FILE *const check_file, FILE *const id_file, User *const user);
bool verify_check (FILE *const check_file, FILE *const id_file, User *const user);
bool deposit_check (FILE *const check_file, FILE *const accounts_file, User *const user);

int main (void) {

    FILE *check_file;
    FILE *id_file;
    FILE *accounts_file;

    if ((check_file = fopen("checks.dat", "rb+")) == NULL) {
        puts("Error! Could not open file\n");
        return 1;
    }

    if ((id_file = fopen("id.dat", "rb+")) == NULL) {
        puts("Error! Could not open id file\n");
        return 1;
    }

    if ((accounts_file = fopen("accounts.dat", "rb+")) == NULL) {
        puts("Error! Could not open accounts file\n");
        return 1;
    }

    int choice = 0;

    while (choice != 4) {
    
        printf("1. Insert check\n");
        printf("2. Verify check\n");
        printf("3. Deposit check amount\n");
        printf("4. Exit\n");
        printf("Choice > ");
        
        do {
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);

        switch (choice) {
            case 1:
                
                if (!insert_check(check_file, id_file)) {
                    puts("Error inserting check, aborting ...");
                    return 2;
                }

                puts("Check inserted correctly\n");
                
                break;
            
            case 2:
                verify_check(check_file, id_file);
                break;
            
            case 3:
                deposit_check(check_file);
                break;
            
            case 4:
                printf("Exiting . . .\n");
                break;
            
            default:
                printf("Error\n");
                break;
        }

    }

    // Close files
    fclose(check_file);
    fclose(id_file);

    return 0;
}

bool insert_check (FILE *const check_file, FILE *const id_file, User *const user) {

    void create_id (Check *const check);
    void check_id (FILE *const id_file, unsigned int *const id);
    
    // Debug
    // void print_checks (FILE *check_file);
    // void print_ids (FILE *id_file);

    // Get check holder info 
    Check check;
    Check compare_check;
    
    printf("Name: ");
    scanf("%s", check.name);
    
    printf("Surname: ");
    scanf("%s", check.surname);
    
    // Check if user has a check already
    while (fread(&compare_check, sizeof(Check), 1, check_file) != 0) {
        
        if (strcmp(check.name, compare_check.name) == 0 && strcmp(check.surname, compare_check.surname) == 0) {
            
            puts("User already has a check\n");
            return false;
        }
    }

    rewind(check_file);

    printf("Balance: ");
    scanf("%lf", &check.balance);

    // Get check id 
    create_id(&check);
    check_id(id_file, &check.id);

    // Write check to file 
    if (fwrite(&check, sizeof(Check), 1, check_file) != 1) {
        puts("Error writing check to file\n");
        return false;
    }

    // Write Name and id to FILE
    if (fprintf(id_file, "%s %u\n", check.name, check.id) < 0) {
        puts("Error writing id to file\n");
        return false;
    }

    rewind(id_file);
    rewind(check_file);

    // Print checks and ids 
    // print_checks(check_file);
    // print_ids(id_file);
 
    return true;
}

/*
void print_checks (FILE *check_file) {
    
    Check check;
    
    while (fread(&check, sizeof(Check), 1, check_file) != 0) {
        printf("Name: %s\n", check.name);
        printf("Surname: %s\n", check.surname);
        printf("Balance: %.2f\n", check.balance);
        printf("Id: %d\n", check.id);
    }
    
    rewind(check_file);

    return;
}

void print_ids (FILE *id_file) {
    
    char name[NAME_BUF];
    unsigned int id;
    
    while (fscanf(id_file, "%s %d", name, &id) != EOF) {
        printf("Name: %s\n", name);
        printf("Id: %d\n", id);
    }
    
    rewind(id_file);
    
    return;
}
*/

void create_id (Check *const check) {

    // Hash and id based on name, surname and balance 
    unsigned int hash = 0;
 
    for (int i = 0; check->name[i] != '\0'; i++) {
        hash += check->name[i];
    }

    hash *= hash % 31;
    
    for (int i = 0; check->surname[i] != '\0'; i++) {
        hash += check->surname[i];
    }
    
    hash += check->balance;

    while (hash < MIN_ID || hash > MAX_ID) {
    
        if (hash > MAX_ID) {
            
            hash -= MIN_ID;
        
        } else {
        
            hash *= 10;
        
        }
    }

    check->id = hash;

    return;
}

void check_id (FILE *const id_file, unsigned int *const id) {

    // Check if id is already in use 
    char name[NAME_BUF];
    unsigned int id_check;

    while (fscanf(id_file, "%s %u", name, &id_check) != EOF) {
        
        if (id_check == *id) {
            
            do {
                *id += 1;
            } while (*id == id_check);

            rewind(id_file);
        }
    }

    rewind(id_file);

    return;
}

bool verify_check (FILE *const check_file, FILE *const id_file, User *const user) {

    // Search the id file for a name, extract id and compare 
    char name[NAME_BUF];
    char file_name[NAME_BUF];
    printf("Insert name: ");
    scanf("%s", name);

    unsigned int id;
    
    while (fscanf(id_file, "%s %u", file_name, &id) != EOF) {
        
        if (strcmp(name, file_name) == 0) {
    
            printf("\n\nCheck found, id: %u\n", id);
            break;
        
        }
    }

    rewind(id_file);

    // Search check_file for the same name, extract id and compare
    Check check;
    while (fread(&check, sizeof(Check), 1, check_file) != 0) {
 
        if (check.id == id) {
            
            printf("Check id found, name: %s\n\n", check.name);    
            
            // Check if check is valid 
            if (check.balance < MIN_BALANCE || check.balance > MAX_BALANCE) {
                puts("\n!---------------------!\nCheck is not valid\nBalance too low or too high\n!---------------------!\n\n");
                return false;
            }

            if (strcmp(check.name, name) != 0) {
                puts("\n!---------------------!\nCheck is not valid\nName does not match\n!---------------------!\n\n");
                return false;
            }

            rewind(check_file);

            return true;
        }
    }

    puts("\nCheck id not found\n");
    rewind(check_file);

    return false;
}

bool deposit_check (FILE *const check_file, FILE *const accounts_file, User *const user) {

    rewind(check_file);

    // Search the id file for a name, extract id and compare 
    
}
