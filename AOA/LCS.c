#include <stdio.h>
#include <string.h>

int main()
{
    char st1[50], st2[50];
   
    printf("Enter the first string : ");
    scanf("%s",st1);
   
    printf("Enter the second string : ");
    scanf("%s",st2);
   
    int n=strlen(st1),m=strlen(st2);
    int min=n;

    if(n>=m){
        min=m;
    } 
    
    char lcs[min];
   
    int val[n+1][m+1], arr[n][m];
   
    for(int i=0;i<n+1;i++){
        for (int j = 0; j < m+1; j++) {
            if(i==0 || j==0){
                val[i][j]=0;
            }
            else if(st1[i-1]==st2[j-1]){
                val[i][j]=1+val[i-1][j-1];
                arr[i-1][j-1]=1;
            }
            else{
                if(val[i-1][j]>val[i][j-1]){
                val[i][j]=val[i-1][j];
                arr[i-1][j-1]=2;
                }
                else{
                val[i][j]=val[i][j-1];
                arr[i-1][j-1]=3;
                }
            }
            printf("%d ",val[i][j]);
        }
        printf("\n");
    }
   
        printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ",arr[i][j]); 
        }
        printf("\n");
    }
   
    int z=0,x=n-1,y=m-1; 
   
   
    while(x>=0 && y>=0){
        if(arr[x][y]==1){
            printf("\n z%d x%d y%d\n",z,x,y);
           lcs[z]=st1[x]; 
            z++;
            x=x-1;
            y=y-1; 
        }
        else if(arr[x][y]==2){
            x=x-1; 
        }
        else{
            y=y-1;
        }
    }
    printf("\n");
    printf("\nThe longest common subsequence is : ");
    for (int i = z-1; i >=0 ; i--) {
        printf("%c ",lcs[i]);
    }

    return 0;
}