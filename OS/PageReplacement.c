#include<stdio.h>

void fifo(int fSize, int n , int pageStream[]) {

    int frame[fSize],counter=0,pageFaults=0,i=0;
    for(int j=0;j<fSize;j++){ 
        frame[j]=-1;
    }

    printf("Incoming Stream\t\tFrame1\tFrame2\tFrame3\n");
    while(i<n){

        int found=0;
        
        for(int j=0;j<fSize;j++){ 
            if(frame[j]==pageStream[i]){
                found=1;
                break;
            }
        }
        if(found==0){
            frame[counter%3]=pageStream[i];
            pageFaults++;
            counter++;
        } 

        printf("%d\t\t\t",pageStream[i]);
        for(int j=0;j<fSize;j++){
            if(frame[j]==-1){
            printf(" \t");
            }
            else{
            printf("%d\t",frame[j]);
            }
        }
        printf("\n");
        i++;
    }

    printf("\nNumber of faults : %d",pageFaults);
    printf("\nNumber of hits : %d",n-pageFaults);

}   



int main(){

    int fSize,n;

    printf("Enter the frame size : ");
    scanf("%d",&fSize);

    printf("\nEnter the number of entries : ");
    scanf("%d",&n);

    int pageStream[n];
    printf("\nEnter the data of stream : ");
    for (int i =0;i<n;i++){ 
        scanf("%d",&pageStream[i]);
    }

    int choice;     
    printf("1.Fifo\n2.LRU\n");
    printf("Select Type of Page Replacement Policy : ");
    scanf("%d",&choice);
    
    switch (choice)
    {
        case 1:
            fifo(fSize,n,pageStream);
            break;
        case 2:
            lru(fSize,n,pageStream);
            break;
        default:
            break;
    }

    return 0;
}