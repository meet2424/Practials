#include <stdio.h>

void main()
{
    int n = 5, p, start;
    // int cost[9][9] = {{0, 4, 50, 50, 50, 50, 50, 8, 50}, {4, 0, 8, 50, 50, 50, 50, 11, 50}, {50, 8, 0, 7, 50, 4, 50, 8, 2}, {50, 50, 7, 0, 9, 14, 50, 50, 50}, {50, 50, 50, 9, 0, 10, 50, 50, 50}, {50, 50, 4, 14, 10, 0, 2, 50, 50}, {50, 50, 50, 50, 50, 2, 0, 1, 6}, {8, 11, 50, 50, 50, 50, 1, 0, 7}, {50, 50, 2, 50, 50, 50, 6, 7, 0}};
    // int D[9] = {50, 50, 50, 50, 50, 50, 50, 50, 50};
    // int V[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    int cost[5][5] = {
        {50, 50, 7, 50, 10},
        {50, 50, 50, 50, 50},
        {50, 50, 50, 3, 8},
        {50, 8, 50, 50, 2},
        {50, 5, 50, 50, 50}};
    int D[5] = {50, 50, 50, 50, 50};
    int V[5] = {0, 0, 0, 0, 0};
    int check;
    printf("Enter start node: ");
    scanf("%d", &start);
    p = start - 1;
    D[p] = 0;

    for (int i = 0; i < n - 1; i++)
    {

        for (int i = 0; i < n; i++)
        {
            // printf("\n%d", cost[p][i]);
            for (int p = 0; p < n; p++)
            {
                check = D[p] + cost[p][i];
                if (D[i] > check)
                {
                    D[i] = check;
                    V[i] = p;
                }
            }
            // printf("/%d ", D[i]);
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d ", D[i]);
        }
        printf("\n");
        // printf("\n");
    }

    printf("The SSSP using Bellman Ford algo is : \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", D[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", V[i]);
    }
}