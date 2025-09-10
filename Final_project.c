#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#define MAXVALUE 100

typedef struct
{
    char name[MAXVALUE];
    char fName[MAXVALUE];
    int plyrNumber;
    char position[MAXVALUE];
    // {"goalkeeper","defender", "midfielder", "Attacker"}
    int age;
    int goalsNum;
    int Id;

} player;
void addPlayer(int *counter, player player[MAXVALUE],bool *PlyrNumChecker);

void idgenerator(int *playerId);

int main()
{

    int mainChoice, addChoice, counter = 0, playerIndex[MAXVALUE];

    bool appStatus = true, addStatus = true, PlyrNumChecker = true;
    player player[MAXVALUE];

    while (appStatus)

    {

        printf("\033[1;33m");
        printf("\n---Football Players Manager---\n");
        printf("\033[0m");

        printf("1.Add Player\n");
        Sleep(600);
        printf("2.Modify Player\n");
        Sleep(600);
        printf("3.Delete Player from the list\n");
        Sleep(600);
        printf("4.Show avaible Players\n");
        Sleep(600);
        printf("5.Search for Player\n");
        Sleep(600);
        printf("0.To exit the program\n");
        Sleep(600);
        printf("\033[1;33m");
        printf("Your Choice is: ");
        printf("\033[0m");
        scanf("%d", &mainChoice);
        getchar();
        switch (mainChoice)
        {
        case 1:
            while (addStatus)
            {
                printf("1.Add New player");
                printf("\n2.Add multiple players");
                printf("\n0.back\n");
                printf("\033[1;33m");
                printf("Your Choice is: ");
                printf("\033[0m");
                scanf("%d", &addChoice);
                getchar();
                if (addChoice == 1)
                {
                    addPlayer(&counter,player,&PlyrNumChecker);
                    break;
                }
                else if (addChoice == 2)
                {
                    int Quantity0a;

                    printf("Enter how much numbers do you want to add: ");
                    scanf("%d", &Quantity0a);
                    getchar();
                    for (int i = 0; i < Quantity0a; i++)
                    {
                        addPlayer(&counter,player,&PlyrNumChecker);
                    }
                }
                else if (addChoice == 0)
                {
                    printf("wait...");
                    addStatus = false;
                    Sleep(500);
                }
                else
                {
                    printf("\033[0;31m");
                    printf("invalide option");
                    printf("\033[0m\n");
                }
            }

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            printf("exiting the program...");
            appStatus = false;
            Sleep(1200);
            break;
        default:
            printf("\033[0;31m");
            printf("invalide option");
            printf("\033[0m\n");

            break;
        }
    }
}
int search(int playerIndex)
{
}
void idgenerator(int *playerId)
{

    static int nextId = 1; // keeps its value between calls
    *playerId = nextId++ * 512;
}
void addPlayer(int *counter, player player[MAXVALUE],bool *PlyrNumChecker)
{
    if (*counter < MAXVALUE)
    {
        printf("Enter your player first name: ");
        fgets(player[*counter].fName, sizeof(player[*counter].fName), stdin);
        player[*counter].fName[strlen(player[*counter].fName) - 1] = '\0';

        printf("Enter your player name: ");
        fgets(player[*counter].name, sizeof(player[*counter].name), stdin);
        player[*counter].name[strlen(player[*counter].name) - 1] = '\0';

        printf("Enter number of this player: ");
        scanf("%d", &player[*counter].plyrNumber);
        getchar();
        while (*PlyrNumChecker)
        {
            if (player[*counter].plyrNumber > 100 || player[*counter].plyrNumber < 0)
            {
                printf("\033[0;31m");
                printf("Error the number must be between (1-100)!! : ");
                printf("\033[0m");
                scanf("%d", &player[*counter].plyrNumber);
                getchar();
            }
            else
            {
                *PlyrNumChecker = false;
            }
        }

        
        idgenerator(&player[*counter].Id);

        printf("player id: %d\n", player[*counter].Id);
        (*counter)++;
    }
    else
    {
        printf("Contact list is full!\n");
    }
}