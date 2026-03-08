#include <stdio.h>

int main()
{
    int n, tq;
    
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    // Input arrival time and burst time
    for(int i=0;i<n;i++)
    {
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rt[i] = bt[i];   // Remaining time = Burst time
    }

    int time = 0;
    int remain = n;

    while(remain > 0)
    {
        for(int i=0;i<n;i++)
        {
            if(rt[i] > 0 && at[i] <= time)
            {
                if(rt[i] > tq)
                {
                    time = time + tq;
                    rt[i] = rt[i] - tq;
                }
                else
                {
                    time = time + rt[i];
                    rt[i] = 0;

                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    remain--;
                }
            }
        }
    }

    float avgWT = 0, avgTAT = 0;

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f",avgWT/n);
    printf("\nAverage Turnaround Time = %.2f",avgTAT/n);

    return 0;
}