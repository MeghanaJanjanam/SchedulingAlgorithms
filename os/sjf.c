#include<stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *a = temp;
}
void bubbleSort(int bt[], int n, int p[])
{
    int i, j, temp;
    for (i = 1; i <= n-1; i++)
    {
        for (j = 1; j < n-1; j++)
            {
                if (bt[j] > bt[j+1])
                {
                    swap(&bt[j], &bt[j+1]);
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
    }
}
void avg_wt_tat(int tat[], int wt[], int n, int bt[], int p[])
{
    int twt=0, ta=0;
    float avgwt, avgtat;
    int i, j;
    wt[0] = 0;
    tat[0] = 0;
    bt[0] = 0;
    printf("Process\tBurstTime\tWaitingTime\tTurnaroundTime\n");
    for(i=1; i<=n; i++)
    {
        wt[i] = bt[i-1]+wt[i-1];
        twt = twt+wt[i];

        tat[i] = bt[i]+wt[i];
        ta = ta+tat[i];
        printf(" %d \t\t%d\t\t%d\t\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    avgwt = ta/n;
    avgtat = ta/n;
    printf("Average waiting time : %f\n", avgwt);
    printf("Average Turnaround time : %f\n", avgtat);

}

int main()
{
    int n, p[100], bt[100], wt[100], tat[100];
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    for (int  i=1; i<=n; i++)
    {
        printf("Enter the burst time of p[%d] ", i);
        scanf("%d", &bt[i]);
        p[i] = i;
    }
    bubbleSort(bt, n, p);
    avg_wt_tat(tat, wt, n, bt, p);
    return 0;
}
