 
#include <stdio.h>
 
void swap(int *a, int *b) 
{ 
  int temp = *a;
  *a = *b;
  *b = temp;
}


void sortAccordingToBurstTime(int n,int process_num[], int arrival_time[],int burst_time[]){
    
   for (int i = 2; i <= n ; i++)
    { 
      for (int j = 2; j <= n ; j++)
	{ 
	  if (burst_time[j] > burst_time[j + 1])
	    {  
	      swap(&burst_time[j],&burst_time[j+1]); 
	      swap(&arrival_time[j],&arrival_time[j+1]);
	      swap(&process_num[j],&process_num[j+1]);
	    }
	}
    }
 
} 

void processSJF(int n,int process_num[], int arrival_time[],int burst_time[]){
    sortAccordingToBurstTime(n,process_num,arrival_time,burst_time);
 
    float avtat,avwt,ct=burst_time[1];
    int tat[n],wt[n];
    wt[1]=0;
    tat[1]=burst_time[1];
 avtat=tat[1];
 avwt=wt[1];
     for(int i=2;i<=n;i++){
        ct+=burst_time[i];
        tat[i]=ct-arrival_time[i];
        avtat+=tat[i];
        wt[i]=tat[i]-burst_time[i];
        avwt+=wt[i];
    }
    printf("\n\nOutput Table SJF\n\n");
        printf("Process\tArrival Time\tBurst Time\tTAT\tWT\n");  
    for(int i=1;i<=n;i++){
        printf("%d\t%d\t\t%d\t\t%d\t%d\n",process_num[i],arrival_time[i],burst_time[i],tat[i],wt[i]);
    } 
    printf("\nAverage TAT : %.2f Average WT : %.2f",(double)(avtat/n),(double)(avwt/n));
}

int main()
{
    int n;
    printf("Enter the number of process : ");
    scanf("%d",&n);
 int process_num[n], arrival_time[n] , burst_time[n];
    
    for(int i=1;i<=n;i++){
        printf("\nEnter the arrival time for P[%d]:",i);
        scanf("%d",&arrival_time[i]);
        printf("\nEnter the burst time for P[%d]:",i);
        scanf("%d",&burst_time[i]);
        process_num[i]=i;
    }
    
    printf("\nInput Table\n");
        printf("Process\tArrival Time\tBurst Time\n");  
    for(int i=1;i<=n;i++){
        printf("%d\t%d\t\t%d\n",process_num[i],arrival_time[i],burst_time[i]);
    }
     
    processSJF(n,process_num,arrival_time,burst_time);
  return 0;
}

