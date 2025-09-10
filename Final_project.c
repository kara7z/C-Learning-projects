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
void addPlayer(int *counter, player player[MAXVALUE], bool *PlyrNumChecker);

void idgenerator(int *playerId);

int main()
{

    int mainChoice, addChoice, counter = 0, playerIndex[MAXVALUE];

    bool appStatus = true, addStatus = true, PlyrNumChecker = true;
    player player[MAXVALUE];

    while (appStatus)

    {

        printf("\033[1;33m");
        printf("\n---Football Players App Manager---\n");
        printf("\033[0m");

        printf("1.Add Player\n");
        Sleep(600);
        printf("2.Show avaible Players\n");
        Sleep(600);
        printf("3.Modify Player info\n");
        Sleep(600);
        printf("4.Delete Player from the list\n");
        Sleep(600);
        printf("5.Search for Player\n");
        Sleep(600);
        printf("6.Players Stats\n");
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
                    addPlayer(&counter, player, &PlyrNumChecker);
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
                        addPlayer(&counter, player, &PlyrNumChecker);
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
        case 6:
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
int search(int *counter, player player[MAXVALUE])
{
    int sizePlayers = sizeof(player[*counter])/sizeof(player[0]);

    for(int i =0;i<sizePlayers ;i++){
        if(sizePlayers==0){
            printf("You need to add players, no player founded");
        }

    }
}
void idgenerator(int *playerId)
{
    // Id will never change value
    static int nextId = 1;
    *playerId = nextId++ * 512;
}
void addPlayer(int *counter, player player[MAXVALUE], bool *PlyrNumChecker)
{
    char position1[] = "goalkeeper";
    char position2[] = "defender";
    char position3[] = "midfielder";
    char position4[] = "Attacker";
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
        char respond0p;
        printf("\nFor choosing the player position press:\n");
        printf("\"g\" for the goalkeeper\n ");
        printf("\"d\" for the defender\n");
        printf("\"m\" for the midfielder\n");
        printf("\"a\" for the Attacker\n");
        printf("\033[1;33m");
        printf("Your Choice is: ");
        printf("\033[0m");

        scanf("%c", &respond0p);
        getchar();

        //{"goalkeeper","defender", "midfielder", "Attacker"}
        bool checker0p = true;
        if (respond0p == 'g' || respond0p == 'G' ||
            respond0p == 'd' || respond0p == 'D' ||
            respond0p == 'm' || respond0p == 'M' ||
            respond0p == 'a' || respond0p == 'A')
        {
            checker0p = false;
        }
        else
        {
            checker0p = true;
        }

        while (checker0p)
        {
            if (respond0p == 'g' || respond0p == 'G' ||
                respond0p == 'd' || respond0p == 'D' ||
                respond0p == 'm' || respond0p == 'M' ||
                respond0p == 'a' || respond0p == 'A')
            {
                checker0p = false;
                break;
            }

            printf("\nFor choosing the player position press:\n");
            printf("\"g\" for the goalkeeper\n ");
            printf("\"d\" for the defender\n");
            printf("\"m\" for the midfielder\n");
            printf("\"a\" for the Attacker\n");
            printf("\033[1;33m");
            printf("Your Choice is: ");
            printf("\033[0m");

            scanf("%c", &respond0p);
            getchar();
        }
        switch (respond0p)
        {
        case 'g':
            strcasecmp(player[*counter].position, position1);
            break;

        case 'd':
            strcasecmp(player[*counter].position, position2);
            break;

        case 'm':
            strcasecmp(player[*counter].position, position3);

            break;
        case 'a':
            strcasecmp(player[*counter].position, position4);

            break;

        default:
            printf("invalide choice");
            break;
        }
        int checker0age = true;

        printf("Enter the age of this player: ");
        scanf("%d", &player[*counter].age);
        getchar();

        while (checker0age)
        {
            if (player[*counter].age > 120 || player[*counter].age < 0)
            {
                printf("\033[0;31m");
                printf("Error the number must be between (1-120)!! : ");
                printf("\033[0m");
                scanf("%d", &player[*counter].age);
                getchar();
            }
            else
            {
                checker0age = false;
            }
        }
        int checker0goals = true;

        printf("Enter how many goals %s score: ",player[*counter].name);
        scanf("%d", &player[*counter].goalsNum);
        getchar();

        while (checker0goals)
        {
            if (player[*counter].goalsNum > 1000 || player[*counter].goalsNum <= 0)
            {
                printf("\033[0;31m");
                printf("Error the number must be between (0-1000)!! : ");
                printf("\033[0m");
                scanf("%d", &player[*counter].goalsNum);
                getchar();
            }
            else
            {
                checker0goals = false;
            }
        }
        idgenerator(&player[*counter].Id);

        printf("\x1b[32m");
        printf("player ID: %d\n", player[*counter].Id);
        printf("\033[0m");

        (*counter)++;
    }
    else
    {
        printf("Contact list is full!\n");
    }
}