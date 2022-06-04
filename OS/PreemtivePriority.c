
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortAccordingToArrivalTime(int n, int process_num[], int arrival_time[], int burst_time[], int priority[])
{

    int pos;
    for (int i = 0; i < n; i++)
    {
        pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arrival_time[j] < arrival_time[pos])
                pos = j;
        }

        swap(&arrival_time[i], &arrival_time[pos]);
        swap(&burst_time[i], &burst_time[pos]);
        swap(&priority[i], &priority[pos]);
        swap(&process_num[i], &process_num[pos]);
    }
}

void processPriority(int n, int process_num[], int arrival_time[], int burst_time[], int priority[], int procees_time[])
{

    int ct[n], tat[n], wt[n], time=0, count = 0, pri=0, pre = 99, current, end;
    float avtat=0, avwt=0;
 

     printf("\nGantt Chart\n");
    if(arrival_time[0]!=0){   
        for(int j=0;j<arrival_time[0];j++){
            printf("-");            
        }
        time=arrival_time[0];
    }


    for (time; count != n; time++)
    {
        for (int i = 0; i < n; i++)
        {
            if (arrival_time[i] <= time && priority[i] > pri && pre > priority[i])
            {
                pri = priority[i];
                current = i;
            }
        }
        procees_time[current]++;
        printf("| P%d ", process_num[current]);
        end = time + 1;
        if (burst_time[current] == procees_time[current])
        {
            ct[current] = end;
            tat[current] = end - arrival_time[current];
            avtat += tat[current];

            wt[current] = tat[current] - burst_time[current];
            avwt += wt[current];

            count++;
            pre = pri;
            pri = 0;
        }
    }
    printf("|\n");

    for (int i = 0; i <= time; i++){
        if(i<10){
        printf("%d    ",i);
        }
        else{
        printf("%d   ",i);
        }
    }

    printf("\nOutput Table Priority\n\n");
    printf("\n\nProcess\t\tArrival Time\tBurst Time\tPriority\tCompeletion Time\tTurnAround Time\t\tWaiting Time\n");  
    
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", process_num[i], arrival_time[i], burst_time[i], priority[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage TAT : %.2f \nAverage WT : %.2f", (double)(avtat / n),(double)(avwt / n));
}

int main()
{
    int n;
    printf("Enter the number of process : ");
    scanf("%d", &n);
    int process_num[n], arrival_time[n], priority[n], burst_time[n], procees_time[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the arrival time for P[%d]:", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("\nEnter the burst time for P[%d]:", i + 1);
        scanf("%d", &burst_time[i]);
        printf("\nEnter the priority for P[%d]:", i + 1);
        scanf("%d", &priority[i]);
        process_num[i] = i + 1;
        procees_time[i] = 0;
    }

    printf("\nInput Table\n");
    printf("Process\tArrival Time\tBurst Time\tPriority\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", process_num[i], arrival_time[i],
               burst_time[i], priority[i]);
    }
    sortAccordingToArrivalTime(n, process_num, arrival_time, burst_time, priority);
    processPriority(n, process_num, arrival_time, burst_time, priority, procees_time);

    return 0;
}
