#include<stdio.h>
void findWaitingTime(int processes[], int n,
                          int bt[], int wt[])
{
    wt[0] = 0;
    bt[0] = 0;
    for (int  i = 1; i <= n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}

void findTurnAroundTime( int processes[], int n,
                  int bt[], int wt[], int tat[])
{
    wt[0]=0;
    bt[0]=0;
    for (int  i = 1; i <= n ; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime( char processes[], int n, int bt[])
{
    int wt[n], tat[n], avgWt, avgTat;
    float total_wt =0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
    printf("Processes   Burst time   Waiting time   Turn around time\n");
    for (int  i=1; i<=n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d ",(i+1));
        printf("       %d ", bt[i] );
        printf("       \t\t%d",wt[i] );
        printf("       \t\t%d\n",tat[i] );
    }
    avgWt = total_wt / n;
    avgTat = total_tat / n;
    printf("Average waiting time = %d",avgWt);
    printf("\n");
    printf("Average turn around time = %d ",avgTat);
}
int main()
{
    char processes[100];
    int n, bt[100], wt[100], tat[100];
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    for (int  i=1; i<=n; i++)
    {
        printf("Enter the process %d : ", i);
        scanf("%s", &processes[i]);
        printf("Enter the burst time of %d ", i);
        scanf("%d", &bt[i]);
    }

    findavgTime(processes, n,  bt);
    return 0;
}
