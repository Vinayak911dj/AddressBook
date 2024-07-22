#include "contact.h"
// Dummy contact data
static Contact dummyContacts[] = { //static array cannot use outside of the file, Size is fixed, cannot delete
    {"John Doe", "1234567890", "john@example.com"}, //array of structure
    {"Alice Smith", "0987654321", "alice@example.com"},
    {"Bob Johnson", "1112223333", "bob@company.com"},
    {"Carol White", "4445556666", "carol@company.com"},
    {"David Brown", "7778889999", "david@example.com"},
    {"Eve Davis", "6665554444", "eve@example.com"},
    {"Frank Miller", "3334445555", "frank@example.com"},
    {"Grace Wilson", "2223334444", "grace@example.com"},
    {"Hannah Clark", "5556667777", "hannah@example.com"},
    {"Ian Lewis", "8889990000", "ian@example.com"}
    // {"Lewis Ham", "8645798620", "LweisHam@example.com"}
};
 
void populateAddressBook(AddressBook* addressBook)
{
    addressBook->contactCount=0;
    int size=sizeof(dummyContacts)/sizeof(dummyContacts[0]);
    for (int i=0;i<size;i++)
    {
       addressBook->contacts[i]=dummyContacts[i];  
       addressBook->contactCount++;
    }
     

    //store the data into addressbook
    //find the number of users present in the dummy contact
    //int size=sizeof(dummyContacts)/sizeof(dummyContacts[0]);
    //run the loops for size times
    //copy the user one by one from dummy contacts to addressbook contact
    // addressBook->contacts[i]=dummyContacts[i];
    //increment the contactCount by 1 
}
