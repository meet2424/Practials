#include <stdio.h>

void main()
{
    int n=9 , p, min, check;

    // printf("Enter the number of nodes : ");
    //  scanf("%d",&n);
     
    //  int cost[n][n], D[n], V[n]; 
     
    //  printf("\nEnter the Distances\n");
    //  for (int i = 0; i < n; i++) {
    //       for (int j = 0; j <n ; j++) {
    //            if(i==j){
    //                 cost[i][j]==0;
    //            }
    //            else{
    //                 printf("\nDistance of node %d to %d : ",i+1,j+1);
    //                 scanf("%d",&cost[i][j]);
    //            }
    //       }
    //       D[i]=50;
    //       V[i]=0;
    //  }

    int cost[9][9] = {{0, 4, 50, 50, 50, 50, 50, 8, 50}, {4, 0, 8, 50, 50, 50, 50, 11, 50}, {50, 8, 0, 7, 50, 4, 50, 8, 2}, {50, 50, 7, 0, 9, 14, 50, 50, 50}, {50, 50, 50, 9, 0, 10, 50, 50, 50}, {50, 50, 4, 14, 10, 0, 2, 50, 50}, {50, 50, 50, 50, 50, 2, 0, 1, 6}, {8, 11, 50, 50, 50, 50, 1, 0, 7}, {50, 50, 2, 50, 50, 50, 6, 7, 0}};
    
    int D[9] = {50, 50, 50, 50, 50, 50, 50, 50, 50};
    int V[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
     
    printf("\nEnter source node: ");
    scanf("%d", &p);
    p = p - 1;
    D[p] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int i = 0; i < n; i++)
        { 
            check = D[p] + cost[p][i];
            if (D[i] > check)
            {
                D[i] = check;
            }
            printf(" %d", D[i]);
        }
        printf("\n");
        V[p] = 1;
        min = 50;
        for (int i = 0; i < n; i++)
        { 
            if (min > D[i] && V[i] == 0)
            {
                min = D[i];
                p = i;
            }
        }
 
    }

    printf("\nThe shortest distance from source vertex\n");
	printf("Vertex\t\tDistance\n");
	for(int i=0;i<n;i++){  
		printf("%d\t\t%d\n",i,D[i]);
	}
}