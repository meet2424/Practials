
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

    int ct[n], tat[n], wt[n], time, count = 0, pri, pre = 0, p, end;
    float avtat, avwt;

    printf("\nOutput Table Priority\n\n");
    printf("\nOrder : ");
    for (time = 0; count != n; time++)
    {
        pri = 99;
        for (int i = 0; i < n; i++)
        {
            if (arrival_time[i] <= time && priority[i] < pri && pre < priority[i])
            {
                pri = priority[i];
                p = i;
            }
        }
        procees_time[p]++;
        end = time + 1;
        if (burst_time[p] == procees_time[p])
        {
            printf("P%d ", process_num[p]);
            ct[p] = time;
            tat[p] = end - arrival_time[p];
            avtat += tat[p];

            wt[p] = tat[p] - burst_time[p];
            avwt += wt[p];

            count++;
            pre = pri;
        }
    }
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t%d\t\t%d\t%d\n", process_num[i], arrival_time[i], burst_time[i], priority[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage TAT : %.2f \nAverage WT : %.2f", (double)(avtat / n),
           (double)(avwt / n));
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
