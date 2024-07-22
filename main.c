#include <stdio.h>
#include "contact.h"
#include "populate.h"
#include "populate.c"
#include "contact.c"

int main()
{
    AddressBook book;
    book.contactCount=0;
    int choice;
    do{
    printf("Read the choice from the user:\n");
    printf("1. Create Contact\n");
    printf("2. Search Contact\n");
    printf("3. Edit Contact\n");
    printf("4. Delete contact\n");
    printf("5. Display Contact\n");
    printf("6. Exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("You have selcted Create Contact\n");
        createContact(&book);
        break;
    case 2:
        printf("You have selcted Search Contact\n");
        searchContact(&book);  //address of variable
        break;
    case 3:
        printf("You have selected Edit the Contact\n");
        editContact(&book);
        break;
    case 4: 
        printf("You have selcted the Delete Contact\n");
        deleteContact(&book);
        break;
    case 5:
        printf("You have selcted the Display Contact\n");
        if(book.contactCount==0)
            initialize(&book);  //address of variable
        else
            listContacts(&book);
        break;
    case 6:
        printf("You have selcted Exit\n");
        break;
    default:
        printf("Invalid Option: Try again :)");
        break;
    }
    }while(choice!=6);
    return 0;
}