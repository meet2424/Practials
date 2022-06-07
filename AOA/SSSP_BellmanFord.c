#include <stdio.h>

void main()
{
    int n = 9, p, start;
    int cost[9][9] = {{0, 4, 50, 50, 50, 50, 50, 8, 50}, {4, 0, 8, 50, 50, 50, 50, 11, 50}, {50, 8, 0, 7, 50, 4, 50, 8, 2}, {50, 50, 7, 0, 9, 14, 50, 50, 50}, {50, 50, 50, 9, 0, 10, 50, 50, 50}, {50, 50, 4, 14, 10, 0, 2, 50, 50}, {50, 50, 50, 50, 50, 2, 0, 1, 6}, {8, 11, 50, 50, 50, 50, 1, 0, 7}, {50, 50, 2, 50, 50, 50, 6, 7, 0}};
    int D[9] = {50, 50, 50, 50, 50, 50, 50, 50, 50};
    int V[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // int cost[5][5] = {
    //     {50, 50, 7, 50, 10},
    //     {50, 50, 50, 50, 50},
    //     {50, 50, 50, 3, 8},
    //     {50, 8, 50, 50, 2},
    //     {50, 5, 50, 50, 50}};
    // int D[5] = {50, 50, 50, 50, 50};
    // int V[5] = {0, 0, 0, 0, 0};
    int check;
    printf("Enter start node: ");
    scanf("%d", &start);
    p = start - 1;
    D[p] = 0;

    for (int i = 0; i < n - 1; i++)
    {

        // for (int i = 0; i < n; i++)
        // {
        //     // printf("\n%d", cost[p][i]);
        //     for (int p = 0; p < n; p++)
        //     {
        //         check = D[i] + cost[i][p];
        //         if (D[p] > check)
        //         {
        //             D[p] = check;
        //             V[p] = i+1;
        //         }
        //     }
        //     // printf("/%d ", D[i]);
        // }
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                check = D[j] + cost[j][k];
                if(D[k] > check)
                {
                    D[k] = check;
                    V[k] = j+1;
                }
            } 
        }
        printf("\nIteration %d:\n",i+1);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", D[i]);
        }
        printf("\n");
        printf("\n");
        // for(int m=0;m<n;m++)
        // {
        // printf("\nd%d = %d",m+1,D[m]);
        // printf("\tp%d = %d",m+1,V[m]);
        // }
        // printf("\n\n"); 
}

    printf("The SSSP using Bellman Ford algo is : \n");
    printf("\nVertex : \t");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", i+1);
    }
    printf("\n");
    printf("\nDistance : \t");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", D[i]);
    }
    printf("\n");
    printf("\nVisited : \t");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", V[i]);
    }
}