 
#include <stdio.h>
 
void swap(int *a, int *b) 
{ 
  int temp = *a;
  *a = *b;
  *b = temp;
}


void sortAccordingToArrivalTime(int n,int process_num[], int arrival_time[],int burst_time[]){
    
   for (int i = 0; i < n ; i++)
    { 
      for (int j = 0; j < n - i; j++)
	{
	  if (arrival_time[j] > arrival_time[j + 1])
	    { 
	      swap(&arrival_time[j],&arrival_time[j+1]);
	      swap(&burst_time[j],&burst_time[j+1]); 
	      swap(&process_num[j],&process_num[j+1]);
	    }
	}
    }

}

void processFCFS(int n,int process_num[], int arrival_time[],int burst_time[]){
    sortAccordingToArrivalTime(n,process_num,arrival_time,burst_time);
    
    float avtat,avwt;
    int tat[n],wt[n],ct[n],temp=0;

    // Logic for case in which arrival_time not starting from zero
    printf("\nGantt Chart\n");     
    if(arrival_time[0]!=0){   
        for(int j=0;j<arrival_time[0];j++){
            printf("-");            
        }
        temp=arrival_time[0];
    }

    for(int i=0;i<n;i++){
        printf("|");
        ct[i]=temp+burst_time[i];
        for(int j=0;j<burst_time[i];j++){
            printf("-");            
        }
        temp=ct[i];
        tat[i]=ct[i]-arrival_time[i];
        avtat+=tat[i];
        wt[i]=tat[i]-burst_time[i];
        avwt+=wt[i];
    }
    printf("|\n");
    
    printf("\nOutput Table FCFS\n\n");
        printf("Process\t\tArrival Time\tBurst Time\tCompeletion Time\tTurnAround Time\t\tWaiting Time\n");  
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",process_num[i],arrival_time[i],burst_time[i],ct[i],tat[i],wt[i]);
    } 
    printf("\nAverage TAT : %.2f Average WT : %.2f",(double)(avtat/n),(double)(avwt/n));
}
 
int main()
{
    int n;
    printf("Enter the number of process : ");
    scanf("%d",&n);
    int process_num[n], arrival_time[n] , burst_time[n];
    
    for(int i=0;i<n;i++){
        printf("\nEnter the arrival time for P[%d]:",i+1);
        scanf("%d",&arrival_time[i]);
        printf("\nEnter the burst time for P[%d]:",i+1);
        scanf("%d",&burst_time[i]);
        process_num[i]=i+1;
    }
    
    printf("\nInput Table\n");
        printf("Process\t\tArrival Time\tBurst Time\n");  
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\n",process_num[i],arrival_time[i],burst_time[i]);
    }
    
    processFCFS(n,process_num,arrival_time,burst_time);
   return 0;
}

