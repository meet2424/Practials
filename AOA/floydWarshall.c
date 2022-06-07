#include<stdio.h>
#include<conio.h>
#define m 4
#define inf 999

void floydWarshall(int previous[m][m]){
    int i,j,k; 

    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < m; j++) 
        {
            for ( k = 0; k < m; k++)
            {
                if(previous[i][j] > previous[i][k] + previous[k][j]){
                    previous[i][j] = previous[i][k] + previous[k][j];
                } 
            } 
        }
            
    }
    
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (previous[i][j] == inf)
                printf("%3s", "inf");
            else
                printf("%4d", previous[i][j]);
        }
        printf("\n");
    }
    
}


void main(){
        int previous[m][m] = {{0, 4, 8, 50},
             {50, 0, 5, 12},
             {50, 50, 0, 4}, 
             {5, 50, 50, 0}};
  floydWarshall(previous);
}