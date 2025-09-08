#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#define MAX_CONTACTS 100
typedef struct

{
    char name[MAX_CONTACTS];
    char phoneNumber[MAX_CONTACTS];
    char email[MAX_CONTACTS];

} contact;

int main()
{
    int choice;
    int counter = 0;
    contact contact[MAX_CONTACTS];

    bool valide = true;
    while (valide)
    {
        printf("---Contact Manager---\n");
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
        printf("Your Choice is: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            if (counter < MAX_CONTACTS)
            {
                printf("Enter your contact name: ");
                fgets(contact[counter].name, sizeof(contact[counter].name), stdin);

                printf("Enter number of this contact: ");
                fgets(contact[counter].phoneNumber, sizeof(contact[counter].phoneNumber), stdin);

                printf("Enter the email fo this contact: ");
                fgets(contact[counter].email, sizeof(contact[counter].email), stdin);
                

                counter++;
            }
            else
            {
                printf("Contact list is full!\n");
            }
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            for (int i =0;i < counter;i++){
                printf("%s",contact[counter].name);
                printf("%s",contact[counter].phoneNumber);
                printf("%s",contact[counter].name);
            }

            break;
        case 5:

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