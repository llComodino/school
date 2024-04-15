#include <stdio.h>
#include <string.h>
#define NAME_BUF 16
#define SURNAME_BUF 16
#define PHONE_BUF 16
#define MAIL_BUF 32
#define CONTACTS 10
typedef struct {
  char name[NAME_BUF];
  char surname[SURNAME_BUF];
  char phone[PHONE_BUF];
  char mail[MAIL_BUF];
} Contacts;

void print_contacts(const Contacts *);
void get_data(Contacts *);

int main(void) {
  Contacts contacts[CONTACTS];
  get_data(contacts);
  print_contacts(contacts);
  return 0;
}
void get_data(Contacts *contact) {
  for (size_t i = 0; i < CONTACTS; i++) {
    printf("Enter name: ");
    do {
      fgets(contact[i].name, NAME_BUF, stdin);
    } while (strlen(contact[i].name) < 2);
    contact[i].name[strlen(contact[i].name) - 1] = '\0';
    getchar();
    printf("Enter surname: ");
    do {
      fgets(contact[i].surname, SURNAME_BUF, stdin);
    } while (strlen(contact[i].surname) < 2);
    contact[i].surname[strlen(contact[i].surname) - 1] = '\0';
    getchar();
    printf("Enter phone: ");
    fgets(contact[i].phone, PHONE_BUF, stdin);
    contact[i].phone[strlen(contact[i].phone) - 1] = '\0';
    getchar();
    printf("Enter mail: ");
    do {
      fgets(contact[i].mail, MAIL_BUF, stdin);
    } while (strlen(contact[i].mail) < 6);
    contact[i].mail[strlen(contact[i].mail) - 1] = '\0';
    getchar();
  }
  return;
}

void print_contacts(const Contacts *contact) {
  printf("%-4s%-16s%-16s%-16s%-32s\n", "N", "Name", "Surname", "Phone", "Mail");
  for (size_t i = 0; i < CONTACTS; i++) {
    printf("%-4zu%-16s%-16s%-16s%-32s\n", i + 1, contact[i].name,
           contact[i].surname, contact[i].phone, contact[i].mail);
  }
  return;
}

