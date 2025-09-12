void maxMinAge(int *counter, player players[MAXVALUE])
{

    int maxAge = players[0].age;
    int minAge = players[0].age;

    for (int i = 1; i < *counter; i++)
    {

        if (players[i].age < minAge)
        {
            minAge = players[i].age;
        }
        if (players[i].age > maxAge)
        {
            maxAge = players[i].age;
        }
    }
    printf("---Youngest Player---\n");
    for (int i = 0; i < *counter; i++)
    {
        if (players[i].age == minAge)
        {
            printf("%s %s, %d years\n", players[i].fName, players[i].name, players[i].age);
        }
    }
    printf("---Oldest Player---\n");
    for (int i = 0; i < *counter; i++)
    {
        if (players[i].age == maxAge)
        {
            printf("%s %s, %d years\n", players[i].fName, players[i].name, players[i].age);
        }
    }
    
}