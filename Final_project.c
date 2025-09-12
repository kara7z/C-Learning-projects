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
    char position[MAXVALUE]; // {"goalkeeper","defender", "midfielder", "Attacker"}
    int age;
    int goalsNum;
    int Id;

} player;

void addPlayer(int *counter, player players[MAXVALUE], bool *PlyrNumChecker); // fonction of adding players

void idgenerator(int *playerId); // fonction of ID maker

int idSearch(int *counter, player players[MAXVALUE]); // fonction of searching for players

int nameSearch(int *counter, player players[MAXVALUE]);

void SortByName(int *counter, player players[MAXVALUE]);

void SortByAge(int *counter, player players[MAXVALUE]);

void SortByPosition(int *counter, player players[MAXVALUE]);

void addPosition(int index, player players[MAXVALUE]);

int main()
{

    int mainChoice, addChoice, counter = 10, playerIndex[MAXVALUE];

    bool appStatus = true, addStatus = true, PlyrNumChecker = true;

    player players[MAXVALUE] = {
        {"Bellingham", "Jude", 5, "Midfielder", 21, 18, 512},
        {"Vinicius", "Jr", 7, "Attacker", 24, 15, 1024},
        {"Rodrygo", "Goes", 11, "Attacker", 23, 12, 1536},
        {"Valverde", "Federico", 15, "Midfielder", 26, 7, 2048},
        {"Camavinga", "Eduardo", 12, "Midfielder", 21, 3, 2560},
        {"Tchouameni", "Aurelien", 18, "Midfielder", 24, 4, 3072},
        {"Courtois", "Thibaut", 1, "Goalkeeper", 32, 0, 3584},
        {"Alaba", "David", 4, "Defender", 32, 2, 4096},
        {"Carvajal", "Dani", 2, "Defender", 33, 1, 4608},
        {"Rudiger", "Antonio", 22, "Defender", 31, 2, 5120}};

    while (appStatus)

    {

        printf("\033[1;33m");
        printf("\n---Football Players App Manager---\n");
        printf("\033[0m");

        printf("1.Add Player\n");
        Sleep(600);
        printf("2.Show available Players\n");
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
        case 1: // Add Player
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
                    addPlayer(&counter, players, &PlyrNumChecker);
                    break;
                }
                else if (addChoice == 2)
                {
                    int Quantity0a;

                    printf("Enter how much players do you want to add: ");
                    scanf("%d", &Quantity0a);
                    getchar();
                    for (int i = 0; i < Quantity0a; i++)
                    {
                        addPlayer(&counter, players, &PlyrNumChecker);
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
        case 2: // Show avaible Players
            bool showStatus = true;

            while (showStatus)
            {
                int show0Choice;
                if (counter == 0)
                {
                    printf("\033[0;31m");
                    printf("You need to add players, no player founded");
                    printf("\033[0m\n");
                    showStatus = false;
                }
                else
                {
                    printf("\nThere are %d players:\n", counter);
                    printf("1.Sort players alphabetically (name)\n");
                    printf("2.Sort players by age\n");
                    printf("3.Show players by position\n");
                    printf("0.back\n");

                    printf("\033[1;33m");
                    printf("Your Choice is: ");
                    printf("\033[0m");

                    scanf("%d", &show0Choice);
                    getchar();
                    switch (show0Choice)
                    {
                    case 1:
                        SortByName(&counter, players);

                        break;
                    case 2:
                        SortByAge(&counter, players);
                        break;
                    case 3:
                        SortByPosition(&counter, players);

                        break;
                    case 0:
                        printf("wait...");
                        Sleep(500);
                        showStatus = false;
                        break;
                    }
                }
            }

            break;
        case 3: // Modify Player info
            bool modifyStatus = true;
            while (modifyStatus)
            {
                int modify0Choice;
                printf("1.Modify player position\n");
                printf("2.Modify player age\n");
                printf("3.Modify goals numbers\n");
                printf("0.back\n");

                printf("\033[1;33m");
                printf("Your Choice is: ");
                printf("\033[0m");

                scanf("%d", &modify0Choice);
                getchar();
                int index;
                switch (modify0Choice)
                {
                case 1: // Modify player position

                    index = idSearch(&counter, players);

                    if (index != -1)
                    {

                        printf("\033[0;35m");
                        printf("\n%d.%s %s\n", players[index].plyrNumber, players[index].name, players[index].fName);
                        printf("\033[0m");
                        printf("Player-Position is: %s\n", players[index].position);
                        printf("Enter new player position\n");
                        addPosition(index, players);
                    }

                    break;
                case 2: // Modify player age
                    index = idSearch(&counter, players);
                    if (index != -1)
                    {
                        printf("Current age: %d\n", players[index].age);
                        printf("Enter new age: ");
                        scanf("%d", &players[index].age);
                        getchar();
                    }
                    break;
                case 3: // Modify goals numbers
                    index = idSearch(&counter, players);
                    if (index != -1)
                    {
                        printf("Current goals: %d\n", players[index].goalsNum);
                        printf("Enter new goals: ");
                        scanf("%d", &players[index].goalsNum);
                        getchar();
                    }

                    break;
                case 0: // back
                    printf("wait...");
                    Sleep(500);
                    modify0Choice = false;
                    break;
                }
                break;
            }
        case 4: // Delete Player from the list
            bool deleteStatus = true;
            while (deleteStatus)
            {
                int delete0Choice;
                printf("1.Delete Player by ID\n");
                printf("0.back\n");

                printf("\033[1;33m");
                printf("Your Choice is: ");
                printf("\033[0m");

                scanf("%d", &delete0Choice);
                getchar();

                switch (delete0Choice)
                {
                case 1:

                    int index = idSearch(&counter, players);

                    if (index != -1)
                    {
                        char player0Choice;

                        printf("\033[0;35m");
                        printf("\n%d.%s %s\n", players[index].plyrNumber, players[index].name, players[index].fName);
                        printf("\033[0m");
                        printf("Player-Position is: %s\n", players[index].position);
                        printf("\nIf you want to delete this player\n");
                        printf("- Press \"Y\" to delete\n");
                        printf("- Press \"N\" for back\n");
                        printf("\033[1;33m");
                        printf("\nYour Choice is: ");
                        printf("\033[0m");

                        scanf("%c", &player0Choice);
                        getchar();

                        if (player0Choice == 'Y' || player0Choice == 'y')
                        {
                            for (int i = index; i < counter; i++)
                            {
                                players[i] = players[i + 1];
                            }
                            counter--;
                            printf("\033[32m");
                            printf("This player has been deleted successfully");
                            printf("\033[0m");
                        }
                        else if (player0Choice == 'N' || player0Choice == 'n')
                        {
                            printf("wait...");
                            Sleep(500);
                            delete0Choice = false;
                            break;
                        }

                        else
                        {
                            printf("You enter wrong answer");
                            Sleep(500);
                            delete0Choice = false;
                            break;
                        }
                    }

                    break;

                case 0: // back
                    printf("wait...");
                    Sleep(500);
                    delete0Choice = false;
                    break;
                }
                break;
            }

            break;
        case 5: // Search for Player
            int search0Choice;

            printf("1.Search by ID\n");
            printf("2.Search by Name\n");
            printf("0.back\n");

            printf("\033[1;33m");
            printf("Your Choice is: ");
            printf("\033[0m");

            scanf("%d", &search0Choice);
            getchar();

            if (counter == 0)
            {
                printf("\033[0;31m");
                printf("You need to add players, no player founded");
                printf("\033[0m\n");
            }
            else if (search0Choice == 1)
            {

                int index = idSearch(&counter, players);
                if (index != -1)
                {

                    printf("\033[0;35m");
                    printf("\n%d.%s %s\n", players[index].plyrNumber, players[index].name, players[index].fName);
                    printf("\033[0m");
                    printf("Player-Age is: %d\n", players[index].age);
                    printf("Player-Position is: %s\n", players[index].position);
                    printf("Player-Score %d Goals\n", players[index].goalsNum);
                }
            }
            else if (search0Choice == 2)
            {
                int index = nameSearch(&counter, players);
                if (index != -1)
                {
                    printf("\033[0;35m");
                    printf("\n%d.%s %s\n", players[index].plyrNumber, players[index].name, players[index].fName);
                    printf("\033[0m");
                    printf("Player-ID is: %d\n", players[index].Id);
                    printf("Player-Age is: %d\n", players[index].age);
                    printf("Player-Position is: %s\n", players[index].position);
                    printf("Player-Score %d Goals\n", players[index].goalsNum);
                }
            }
            else if (search0Choice == 0)
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

            break;
        case 6: // Players Stats
            

            break;
        case 0: // Exit the program
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
void SortByName(int *counter, player players[MAXVALUE])
{
    player temp;
    for (int i = 0; i < *counter - 1; i++)
    {
        for (int j = i + 1; j < *counter; j++)
        {
            if (strcasecmp(players[i].name, players[j].name) > 0)
            {
                temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    for (int i = 0; i < *counter; i++)
    {
        printf("\nPlayer N%d\n", i + 1);
        printf("\nPlayer-ID is: %d\n", players[i].Id);
        printf("Player-Full Name is: %s %s\n", players[i].fName, players[i].name);
        printf("Player-Number is: %d\n", players[i].plyrNumber);
        printf("Player-Position is: %s\n", players[i].position);
        printf("Player-Age is: %d\n", players[i].age);
        printf("Player-Score %d Goals\n", players[i].goalsNum);
    }
}
void SortByAge(int *counter, player players[MAXVALUE])
{
    player temp;
    for (int i = 0; i < *counter - 1; i++)
    {
        for (int j = i + 1; j < *counter; j++)
        {
            if (players[i].age > players[j].age)
            {
                temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    for (int i = 0; i < *counter; i++)
    {
        printf("\nPlayer N%d\n", i + 1);
        printf("\nPlayer-ID is: %d\n", players[i].Id);
        printf("Player-Full Name is: %s %s\n", players[i].fName, players[i].name);
        printf("Player-Number is: %d\n", players[i].plyrNumber);
        printf("Player-Position is: %s\n", players[i].position);
        printf("Player-Age is: %d\n", players[i].age);
        printf("Player-Score %d Goals\n", players[i].goalsNum);
    }
}
void SortByPosition(int *counter, player players[MAXVALUE])
{
    // {"goalkeeper","defender", "midfielder", "Attacker"}
    player temp;
    char position1[] = "Goalkeeper";
    char position2[] = "Defender";
    char position3[] = "Midfielder";
    char position4[] = "Attacker";

    printf("\033[0;36m---Goalkeepers---\033[0m\n\n");
    for (int i = 0; i < *counter; i++)
    {

        if (strcasecmp(players[i].position, position1) == 0)
        {
            printf("\033[0;35m");
            printf("%d.%s %s\n", players[i].plyrNumber, players[i].name, players[i].fName);
            printf("\033[0m");
            printf("Player-ID is: %d\n", players[i].Id);
            printf("Player-Age is: %d\n", players[i].age);
            printf("Player-Score %d Goals\n\n", players[i].goalsNum);
        }
    }
    printf("\033[0;36m---Defenders---\033[0m\n\n");
    for (int i = 0; i < *counter; i++)
    {

        if (strcasecmp(players[i].position, position2) == 0)
        {

            printf("\033[0;35m");
            printf("%d.%s %s\n", players[i].plyrNumber, players[i].name, players[i].fName);
            printf("\033[0m");
            printf("Player-ID is: %d\n", players[i].Id);
            printf("Player-Age is: %d\n", players[i].age);
            printf("Player-Score %d Goals\n\n", players[i].goalsNum);
        }
    }

    printf("\033[0;36m---Midfielders---\033[0m\n\n");

    for (int i = 0; i < *counter; i++)
    {

        if (strcasecmp(players[i].position, position3) == 0)
        {

            printf("\033[0;35m");
            printf("%d.%s %s\n", players[i].plyrNumber, players[i].name, players[i].fName);
            printf("\033[0m");
            printf("Player-ID is: %d\n", players[i].Id);
            printf("Player-Age is: %d\n", players[i].age);
            printf("Player-Score %d Goals\n\n", players[i].goalsNum);
        }
    }
    printf("\033[0;36m---Attackers---\033[0m\n\n");
    for (int i = 0; i < *counter; i++)
    {

        if (strcasecmp(players[i].position, position4) == 0)
        {

            printf("\033[0;35m");
            printf("%d.%s %s\n", players[i].plyrNumber, players[i].name, players[i].fName);
            printf("\033[0m");
            printf("Player-Age is: %d\n", players[i].age);
            printf("Player-Score %d Goals\n\n", players[i].goalsNum);
        }
    }
}
int idSearch(int *counter, player players[MAXVALUE])
{
    int idSearch0Value;
    bool isSearching = true;

    printf("There are %d players\n", *counter);
    while (isSearching)
    {
        printf("Enter The ID of the player: ");
        scanf("%d", &idSearch0Value);
        getchar();

        bool idNotFounded = false;

        for (int i = 0; i < *counter; i++)
        {
            if (idSearch0Value == players[i].Id)
            {
                idNotFounded = true;
                return i;
            }
        }
        if (!idNotFounded)
        {
            printf("\033[0;31m");
            printf("The player ID was not founded in the list");
            printf("\033[0m\n");
            return -1;
        }
        isSearching = false;
    }
}
int nameSearch(int *counter, player players[MAXVALUE])
{
    char nSearch0Value[MAXVALUE];
    bool isSearching = true;

    printf("There are %d players\n", *counter);
    while (isSearching)
    {
        printf("Enter your player name: ");
        fgets(nSearch0Value, sizeof(nSearch0Value), stdin);
        nSearch0Value[strlen(nSearch0Value) - 1] = '\0';

        bool nNotFounded = false;

        for (int i = 0; i < *counter; i++)
        {
            if (strcasecmp(nSearch0Value, players[i].name) == 0)
            {
                nNotFounded = true;
                return i;
            }
        }
        if (!nNotFounded)
        {
            printf("\033[0;31m");
            printf("The player name was not founded in the list");
            printf("\033[0m\n");
            return -1;
        }
        isSearching = false;
    }
}
void idgenerator(int *playerId)
{
    // Id will never change value
    static int nextId = 11;
    *playerId = nextId++ * 512;
}
void addPosition(int index, player players[MAXVALUE])
{
    char position1[] = "Goalkeeper";
    char position2[] = "Defender";
    char position3[] = "Midfielder";
    char position4[] = "Attacker";
    char respond0p;
    bool checker0p = true;

    while (checker0p)
    {

        printf("\nFor choosing the player position press:\n");
        printf("\"G\" for the goalkeeper\n");
        printf("\"D\" for the defender\n");
        printf("\"M\" for the midfielder\n");
        printf("\"A\" for the Attacker\n");
        printf("\033[1;33m");
        printf("Your Choice is: ");
        printf("\033[0m");

        scanf(" %c", &respond0p);

        respond0p = tolower(respond0p);
        switch (respond0p)
        {
        case 'g':
            strcpy(players[index].position, position1);
            checker0p = false;
            break;

        case 'd':
            strcpy(players[index].position, position2);
            checker0p = false;
            break;

        case 'm':
            strcpy(players[index].position, position3);

            checker0p = false;
            break;
        case 'a':
            strcpy(players[index].position, position4);

            checker0p = false;
            break;

        default:
            checker0p = true;
            printf("\033[0;31m");
            printf("invalide option");
            printf("\033[0m\n");
            break;
        }
    }
}
void addPlayer(int *counter, player players[MAXVALUE], bool *PlyrNumChecker)
{
    char position1[] = "Goalkeeper";
    char position2[] = "Defender";
    char position3[] = "Midfielder";
    char position4[] = "Attacker";
    if (*counter < MAXVALUE)
    {
        printf("Enter your player first name: ");
        fgets(players[*counter].fName, sizeof(players[*counter].fName), stdin);
        players[*counter].fName[strlen(players[*counter].fName) - 1] = '\0';

        printf("Enter your player name: ");
        fgets(players[*counter].name, sizeof(players[*counter].name), stdin);
        players[*counter].name[strlen(players[*counter].name) - 1] = '\0';

        printf("Enter number of this player: ");
        scanf("%d", &players[*counter].plyrNumber);
        getchar();
        bool PlyrNumChecker = true;
        while (PlyrNumChecker)
        {
            if (players[*counter].plyrNumber > 100 || players[*counter].plyrNumber < 0)
            {
                printf("\033[0;31m");
                printf("Error the number must be between (1-100)!! : ");
                printf("\033[0m");
                scanf("%d", &players[*counter].plyrNumber);
                getchar();
            }
            else
            {
                PlyrNumChecker = false;
            }
        }
        addPosition(*counter, players);

        bool checker0age = true;

        printf("Enter the age of this player: ");
        scanf("%d", &players[*counter].age);
        getchar();

        while (checker0age)
        {
            if (players[*counter].age > 120 || players[*counter].age < 0)
            {
                printf("\033[0;31m");
                printf("Error the number must be between (1-120)!! : ");
                printf("\033[0m");
                scanf("%d", &players[*counter].age);
                getchar();
            }
            else
            {
                checker0age = false;
            }
        }
        int checker0goals = true;

        printf("Enter how many goals %s score: ", players[*counter].name);
        scanf("%d", &players[*counter].goalsNum);
        getchar();

        while (checker0goals)
        {
            if (players[*counter].goalsNum > 1000 || players[*counter].goalsNum < 0)
            {
                printf("\033[0;31m");
                printf("Error the number must be between (0-1000)!! : ");
                printf("\033[0m");
                scanf("%d", &players[*counter].goalsNum);
                getchar();
            }
            else
            {
                checker0goals = false;
            }
        }
        idgenerator(&players[*counter].Id);

        printf("\x1b[32m");
        printf("%s %s ID is: %d\n", players[*counter].name, players[*counter].fName, players[*counter].Id);
        printf("\033[0m");

        (*counter)++;
    }
    else
    {
        printf("Contact list is full!\n");
    }
}
