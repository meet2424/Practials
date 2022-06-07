#include<stdio.h>
#include<conio.h>
void insertionSort(int arr[], int n);
int w[10]= {2,4,6,2,1},x[10],max;

int main(){
   
  
    int n = sizeof(w)/sizeof(w[0]);
    int sum;
    for (int i = 0; i < n; i++)
        {
        sum = sum + w[i];    
        }
    if(sum < max || w[1] > max){
        printf("\n No Sol");
    }
    sum_subset(0,1,sum);
    return 0;    
}

void sum_subset(int s, int k, int r){
    int i;
    static int b = 1;
    x[k] = 1;
    if (s + w[k] == max)
    {
        printf("\n Subset %d: ",b++);
        for  (i = 1 ;i <= k; i++)
        {
           if(x[i]==1){
                printf("%d\t",w[i]);
           }
           else if(s + w[k] + w[k+1] <= max){
               sum_subset(s+w[k],k+1,r-w[k]);
           }
           if((s+x-w[k] >= max)&&(s+w[k+1] <=max)){
               sum_subset(s,k+1,r-w[k]);
           }
        }

        
           }
    
}