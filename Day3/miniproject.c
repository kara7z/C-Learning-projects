#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>
#define MAX_CONTACTS 100

typedef struct
{
    char name[MAX_CONTACTS];
    char phoneNumber[MAX_CONTACTS];
    char email[MAX_CONTACTS];
    char searchvalue[MAX_CONTACTS];
    
} contact;

int search(char searchvalue[MAX_CONTACTS], contact contact[MAX_CONTACTS], int counter);


int main()
{
    int choice;
    int counter = 0;
    char searchvalue[MAX_CONTACTS];
    

    contact contact[MAX_CONTACTS];

    bool valide = true;
    while (valide)

    {

        printf("\033[1;33m");
        printf("---Contact Manager---\n");
        printf("\033[0m");

        printf("1.Add contact\n");
        Sleep(600);
        printf("2.Modify contact\n");
        Sleep(600);
        printf("3.Delete contact\n");
        Sleep(600);
        printf("4.Show avaible contacts\n");
        Sleep(600);
        printf("5.Search for contact\n");
        Sleep(600);
        printf("0.To exit the program\n");
        Sleep(600);
        printf("\033[1;33m");
        printf("Your Choice is: ");
        printf("\033[0m");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            int index;
        case 1:
            if (counter < MAX_CONTACTS)
            {
                printf("Enter your contact name: ");
                fgets(contact[counter].name, sizeof(contact[counter].name), stdin);
                contact[counter].name[strlen(contact[counter].name) - 1] = '\0';

                printf("Enter number of this contact: ");
                fgets(contact[counter].phoneNumber, sizeof(contact[counter].phoneNumber), stdin);
                 contact[counter].phoneNumber[strlen(contact[counter].phoneNumber) - 1] = '\0';

                printf("Enter the email fo this contact: ");
                fgets(contact[counter].email, sizeof(contact[counter].email), stdin);
                contact[counter].email[strlen(contact[counter].email) - 1] = '\0';

                counter++;
            }
            else
            {
                printf("Contact list is full!\n");
            }
            break;
        case 2:
            printf("Enter the name of the contact: ");
            fgets(searchvalue, sizeof(searchvalue), stdin);
            searchvalue[strlen(searchvalue) - 1] = '\0';
        
            index = search(searchvalue, contact,counter);
            if(index!=-1){
                
                printf("Enter Nnumber of this contact: ");
                fgets(contact[index].phoneNumber, sizeof(contact[index].phoneNumber), stdin);
                 contact[index].phoneNumber[strlen(contact[index].phoneNumber) - 1] = '\0';

                printf("Enter the email fo this contact: ");
                fgets(contact[index].email, sizeof(contact[index].email), stdin);
                contact[index].email[strlen(contact[index].email) - 1] = '\0';
                
            }
            else{
                printf("\033[0;31m");
                printf("Contact inavaible");
                printf("\033[0m\n");

            }

            break;
        case 3:


            break;
        case 4:
            for (int i = 0; i < counter; i++)
            {
                printf("\033[1;33m");
                printf("\n---Contact %d---\n", i + 1);
                printf("\033[0m");
                printf("Name is: %s", contact[i].name);
                printf("Phone number: %s", contact[i].phoneNumber);
                printf("Contact email:%s", contact[i].email);
            }

            break;
        case 5:
        
            printf("Enter the name of the contact: ");
            fgets(searchvalue, sizeof(searchvalue), stdin);
            searchvalue[strlen(searchvalue) - 1] = '\0';
            
            
            index = search(searchvalue, contact,counter);
            if(index!=-1){
                printf("contact %d name is: %s",index+1,contact[index].name);
                printf("Phone number: %s\n", contact[index].phoneNumber);
                printf("Contact email:%s\n", contact[index].email);
            }
            else{
                printf("\033[0;31m");
                printf("Contact inavaible");
                printf("\033[0m\n");

            }
            

            break;
        case 0:
            printf("exiting the program...");
            valide = false;
            Sleep(1200);
            break;
        default:
            printf("invalide option");
            break;
        }
    }
}
int search(char searchvalue[MAX_CONTACTS], contact contact[MAX_CONTACTS], int counter)
{
    for (int i = 0;i<counter;i++){

        if (strcasecmp(searchvalue, contact[i].name)==0)
        {
            return i;
        }
    }
    return -1;
}