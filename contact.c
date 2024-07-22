#include <stdio.h>
// #include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
// #include "populate.c"


void listContacts(AddressBook *addressBook) 
{
    int i;
    printf("--------------------------------------------------\n");
    printf("Name              Phone No.        Email ID       \n");
    printf("--------------------------------------------------\n");
    for(i=0;i<addressBook->contactCount;i++)
    {
        printf("%d) %s\t %s\t %s\t \n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
}
    //run the loop for adressbook->contactCount
    //print the user one by one using prntf
    //addressbook->contacts[i].name
}

void initialize(AddressBook *addressBook) 
{
    populateAddressBook(addressBook);
    listContacts(addressBook);
}

void saveAndExit(AddressBook *addressBook) 
{
}

void createContact(AddressBook *addressBook) 
{
    int i,val;
    char out,name[50],phone1[50],emailID[50]; 
    populateAddressBook(addressBook);
    while(getchar() != '\n');
    {
        do
        {
            printf("Enter Contact Name\n");
            scanf("%49[^\n]", name);
            while (getchar() != '\n');
            // strcpy(addressBook->contacts->name,name);
                // addressBook->contactCount++;
            do
                {
                    printf("Enter PhoneNo: ");
                    scanf("%49[^\n]",phone1);
                    while (getchar() != '\n');
                    for(i=0;i<addressBook->contactCount;i++)
                    {
                        if(strcmp(phone1,addressBook->contacts[i].phone)==0)
                            {
                                printf("SORRY! Phone Number is Presnt in the List\n");
                                printf("Do you want to Re-Enter the Phone No ?\n");
                                printf("Press y for yes , Press n for go back to main:1\n");
                                scanf(" %c",&out);       
                            }    
                    } 
                    // strcpy(addressBook->contacts->phone,phone1);
                    // addressBook->contactCount++;
                    break;       
                }while(out!='n');
                // while (getchar() != '\n');
                do
                    {
                        printf("Enter EmilId: ");
                        scanf("%49[^\n]",emailID);
                        while (getchar() != '\n');
                        for(i=0;i<addressBook->contactCount;i++)
                        {
                            if(strcmp(emailID,addressBook->contacts[i].email)==0)
                                {
                                    printf("SORRY! Email ID is Presnt in the List\n");
                                    printf("Do you want to Re-Enter the Mail ?");
                                    printf("Press y for yes , Press n for go back to main:1");
                                    scanf(" %c",&out);
                                }                                                            
                        }
                        val=addressBook->contactCount;
                        {
                            strcpy(addressBook->contacts[val].name,name);
                            strcpy(addressBook->contacts[val].phone,phone1);
                            strcpy(addressBook->contacts[val].email,emailID);
                            addressBook->contactCount++; 
                        }
                         
                        break;            
                    } while (out!='n');
                printf("Do you want to continue again (y or n): ");
                scanf(" %c",&out); 
                while (getchar() != '\n');
        }while (out!='n');   
    }
}

void searchContact(AddressBook *addressBook) 
{
    int choice,i,found=0;
    char out,list[50]; 
    populateAddressBook(addressBook);
    {
        do
        {
            printf("1.Search by Name\n");
            printf("2.Search by PhoneNo\n");
            printf("3.Search by EmilId\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            //  __fpurge(stdin); //to clear the previous input
            while (getchar() != '\n'); // Clear the input buffer
            switch (choice)
            {
                case 1:
                    printf("Enter the Name: "); 
                // __fpurge(stdin); //to clear the previous input 
                    scanf("%49[^\n]",list);//user Selective Scanf because there is a space inbetween the Names
                    for(i=0;i<addressBook->contactCount;i++)
                    {
                        //compare the name
                        if (strcmp(list, addressBook->contacts[i].name) == 0)
                        {
                            printf("Name is Present in the List\n");
                            printf("%d)%s\t %s\t %s\t\n",i+1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                            // break;
                            found=1;
                        }
                    }
                    break;
                case 2:
                    printf("Enter the PhoneNo: "); 
                    //__fpurge(stdin); //to clear the previous input 
                    scanf("%49[^\n]",list);//user Selective Scanf because there is a space inbetween the Numbers
                    for(i=0;i<addressBook->contactCount;i++)
                    {
                        //compare the Phone No
                        if(strcmp(list,addressBook->contacts[i].phone)==0)
                        {
                            printf("Phone Number is Presnt in the List\n");
                            printf("%d)%s\t %s\t %s\t \n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                            // break;
                            found=1;
                        }
                    }
                    break;
                case 3:
                    printf("Search By Email.ID: ");
                    //__fpurge(stdin); //to clear the previous input 
                    scanf("%49[^\n]",list);//user Selective Scanf because there is a space inbetween the Names
                    for(i=0;i<addressBook->contactCount;i++)
                    {
                        //compare the Email ID
                        if(strcmp(list,addressBook->contacts[i].email)==0)
                        {
                            printf("Email ID is Presnt in the List\n");
                            printf("%d) %s\t %s\t %s\t \n", i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                            // break;
                            found=1;
                        }
                    }
                    break;
                default:
                    printf("Invalid Selection: Try again\n");
                    break;
            } 
            if(!found)
                {
                    printf("User Not Found :)\n");
                } 
            printf("Do you want to continue again (y or n): ");
            scanf(" %c",&out); 
        }while (out!='n');   
    }
}

void editContact(AddressBook *addressBook) 
{
    int choice,i,found=0,index;
    char list[50],out,data[50];

    populateAddressBook(addressBook);
    do
    {
        printf("Which Contact details you want to edit\n");
        printf("1.Search by Name\n");
        printf("2.Search by PhoneNo\n");
        printf("3.Search by EmilId\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');
        switch (choice)
        {
        case 1:
            printf("Enter name:");
            scanf("%49[^\n]",list);
            for(i=0;i<addressBook->contactCount;i++)
             {
                 //compare the name
                    if (strcmp(list, addressBook->contacts[i].name) == 0)
                    {
                        index=i;
                        printf("Index is :%d\n",index);
                        printf("Name is Present in the List\n");
                        printf("%d - %s\t %s\t %s\t\n",i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        //add edit option
                        printf("Do you want to-\n");
                        printf("1.Edit  Name\n");
                        printf("2.EditPhoneNo\n");
                        printf("3.Edit EmilId\n");
                        printf("Enter your choice: ");
                        scanf("%d", &choice);
                        while (getchar() != '\n');
                    switch (choice)
                    {
                    case 1:
                        printf("Enter a new name to edit: ");
                        scanf("%49[^\n]",data);
                        getchar();
                        printf("the data which is copying is : %s\n",data);
                        strcpy(addressBook->contacts[index].name,data);
                        printf("Edit is Successful\n");
                        break;
                    case 2:
                        printf("Enter a new PhoneNo to edit: ");
                        scanf("%49[^\n]",list);
                        strcpy(addressBook->contacts[index].phone,data);
                        printf("Edit is Successful\n");
                        break;
                    case 3:
                        printf("Enter a new Email-ID to edit: ");
                        scanf("%49[^\n]",list);
                        strcpy(addressBook->contacts[index].email,data);
                        printf("Edit is Successful\n");
                        break;
                    default:
                        printf("Invalid Selection:\n");
                        break;
                    }
                    found=1;
                }
            }
            break;
        case 2:
            printf("Enter PhoneNo:");
            scanf("%49[^\n]",list);
        for(i=0;i<addressBook->contactCount;i++)
            {
                index=i;
                //compare the name
                if (strcmp(list, addressBook->contacts[i].phone) == 0)
                {
                    printf("PhoneNo is Present in the List\n");
                    printf("%d - %s\t %s\t %s\t\n",i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    //add edit option
                    printf("Do you want to\n");
                    printf("1.Edit  Name\n");
                    printf("2.EditPhoneNo\n");
                    printf("3.Edit EmilId\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    while (getchar() != '\n');
                    switch (choice)
                    {
                    case 1:
                        printf("Enter a new name to edit: ");
                        scanf("%49[^\n]",list);
                        strcpy(addressBook->contacts[i].name,list);
                        printf("Edit is Successful\n");
                        break;
                    case 2:
                        printf("Enter a new PhoneNo to edit: ");
                        scanf("%49[^\n]",list);
                        strcpy(addressBook->contacts[i].phone,list);
                        printf("Edit is Successful\n");
                        break;
                    case 3:
                        printf("Enter a new Email-ID to edit: ");
                        scanf("%49[^\n]",list);
                        strcpy(addressBook->contacts[i].email,list);
                        printf("Edit is Successful\n");
                        break;
                    default:
                        printf("Invalid Selection:\n");
                        break;
                    }
                    found=1;
                }
            }
            break;
        case 3:
            printf("Enter Email-ID:");
            scanf("%49[^\n]",list);
        for(i=0;i<addressBook->contactCount;i++)
            {
                index=i;
                //compare the name
                if (strcmp(list, addressBook->contacts[i].email) == 0)
                {
                    printf("Email-ID is Present in the List\n");
                    printf("%d - %s\t %s\t %s\t\n",i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                    //add edit option
                    printf("Do you want to \n");
                    printf("1.Edit Name\n");
                    printf("2.EditPhoneNo\n");
                    printf("3.Edit EmilId\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    while (getchar() != '\n');
                    switch (choice)
                    {
                    case 1:
                        printf("Enter a new name to edit: ");
                        scanf("%49[^\n]",list);
                        strcpy(addressBook->contacts[i].name,list);
                        printf("Edit is Successful\n");
                        break;
                    case 2:
                        printf("Enter a new PhoneNo to edit: ");
                        scanf("%49[^\n]",list);
                        strcpy(addressBook->contacts[i].phone,list);
                        printf("Edit is Successful\n");
                        break;
                    case 3:
                        printf("Enter a new Email-ID to edit: ");
                        scanf("%49[^\n]",list);
                        strcpy(addressBook->contacts[i].email,list);
                        printf("Edit is Successful\n");
                        break;
                    default:
                        printf("Invalid Selection:\n");
                        break;
                    }
                    found=1;
                }
            }
            break;
                    default:
                        printf("Invalid Input\n");
                        break;
            }
            if(!found)
            {
                printf("User Not Found :)\n");
            } 
            printf("Do you want to continue again (y or n): ");
            scanf(" %c",&out); 
                    
    }while (out!='n');    
    //populate the list
    //1.search by name
    //2.search by phone no
    //3.Email ID
}

void deleteContact(AddressBook *addressBook) 
{
    int choice,index,i,found=0;
    char out,list[50]; 
    populateAddressBook(addressBook);
    {
        do
        {
            printf("How do you want to delete the Contact\n");
            printf("1.Search by Name\n");
            printf("2.Search by PhoneNo\n");
            printf("3.Search by EmilId\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            while (getchar() != '\n'); // Clear the input buffer
            switch (choice)
            {
                case 1:
                    printf("Enter the Name: ");  
                    scanf("%49[^\n]",list);//user Selective Scanf because there is a space inbetween the Names
                    for(i=0;i<addressBook->contactCount;i++)
                    {
                        index=i;
                        if (strcmp(list, addressBook->contacts[i].name) == 0)
                        {
                            printf("Name is Present in the List\n");
                            printf("%d)%s\t %s\t %s\t\n",i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                            found=1;
                            while (getchar() != '\n');
                            printf("Do you want to delete it? (y or n): ");
                            scanf("%c",&out);
                            if(out=='y')
                            {
                                for(i=index;i<addressBook->contactCount;i++)
                                {
                                    addressBook->contacts[i]=addressBook->contacts[i+1];
                                }
                                addressBook->contactCount--;
                                printf("Delete Successfull\n");
                                break;
                            }
                            else if(out=='n')
                            {
                                printf("Contact not deleted\n");
                                break;
                            }
                            else
                            printf("Invalid Input\n");
                                break;
                        }
                    }
                    break;
                case 2:
                    printf("Enter the Phone No: ");  
                    scanf("%49[^\n]",list);//user Selective Scanf because there is a space inbetween the Names
                    for(i=0;i<addressBook->contactCount;i++)
                    {
                        index=i;
                        if (strcmp(list, addressBook->contacts[i].phone) == 0)
                        {
                            printf("Name is Present in the List\n");
                            printf("%d)%s\t %s\t %s\t\n",i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                            found=1;
                            while (getchar() != '\n');
                            printf("Do you want to delete it? (y or n): ");
                            scanf("%c",&out);
                            if(out=='y')
                            {
                                for(i=index;i<addressBook->contactCount;i++)
                                {
                                    addressBook->contacts[i]=addressBook->contacts[i+1];
                                }
                                addressBook->contactCount--;
                                printf("Delete Successfull\n");
                                break;
                            }
                            else if(out=='n')
                            {
                                printf("Contact not deleted\n");
                                break;
                            }
                            else
                            printf("Invalid Input\n");
                                break;
                        }
                    }
                    break;
                case 3:
                    printf("Enter the Name: ");  
                    scanf("%49[^\n]",list);//user Selective Scanf because there is a space inbetween the Names
                    for(i=0;i<addressBook->contactCount;i++)
                    {
                        index=i;
                        if (strcmp(list, addressBook->contacts[i].name) == 0)
                        {
                            printf("Name is Present in the List\n");
                            printf("%d)%s\t %s\t %s\t\n",i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                            found=1;
                            while (getchar() != '\n');
                            printf("Do you want to delete it? (y or n): ");
                            scanf("%c",&out);
                            if(out=='y')
                            {
                                for(i=index;i<addressBook->contactCount;i++)
                                {
                                    addressBook->contacts[i]=addressBook->contacts[i+1];
                                }
                                addressBook->contactCount--;
                                printf("Delete Successfull\n");
                                break;
                            }
                            else if(out=='n')
                            {
                                printf("Contact not deleted\n");
                                break;
                            }
                            else
                            printf("Invalid Input\n");
                                break;
                        }
                    }
                    break;
            } 
                if(!found)
                    {
                        printf("User Not Found :)\n");
                    } 
            printf("Do you want to continue again (y or n): ");
            scanf(" %c",&out); 
        }while (out!='n');   
    }
    

}
