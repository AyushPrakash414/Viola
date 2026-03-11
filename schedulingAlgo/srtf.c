#include <stdio.h>
#include <limits.h>

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    // Input Arrival Time and Burst Time
    for(int i=0;i<n;i++)
    {
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);

        rt[i] = bt[i]; // remaining time
    }

    int time = 0;
    int completed = 0;

    while(completed < n)
    {
        int shortest = -1;
        int min = INT_MAX;

        // Find process with minimum remaining time
        for(int i=0;i<n;i++)
        {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min)
            {
                min = rt[i];
                shortest = i;
            }
        }

        // If no process available
        if(shortest == -1)
        {
            time++;
            continue;
        }

        // Execute process for 1 unit
        rt[shortest]--;
        time++;

        // If process finished
        if(rt[shortest] == 0)
        {
            ct[shortest] = time;
            completed++;
        }
    }

    // Calculate TAT and WT
    for(int i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}