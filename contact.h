#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS]; //array structure struct contact sarr[100]; 
    int contactCount;
} AddressBook; 

void createContact(AddressBook *addressBook); //structure Pointer
void searchContact(AddressBook *addressBook);   //structure Pointer
void editContact(AddressBook *addressBook);    //structure Pointer
void deleteContact(AddressBook *addressBook);    //structure Pointer
void listContacts(AddressBook *addressBook);   //structure Pointer
void initialize(AddressBook *addressBook);    //structure Pointer
void saveContactsToFile(AddressBook *AddressBook);

#endif
