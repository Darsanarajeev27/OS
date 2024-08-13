#include <stdio.h>

int main() {
    int i, j, n, time, remain, flag = 0, ts;
    int sum_wait = 0, sum_turnaround = 0, at[10], bt[10], rt[10];
    int compt[10], wt[10], tat[10];
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    remain = n;

    for (i = 0; i < n; i++) {
        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time slice: ");
    scanf("%d", &ts);

    for (time = 0, i = 0; remain != 0;) {
        if (rt[i] <= ts && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        } else if (rt[i] > 0) {
            rt[i] -= ts;
            time += ts;
        }

        if (rt[i] == 0 && flag == 1) {
            remain--;
            compt[i] = time;
            wt[i] = time - at[i] - bt[i];
            tat[i] = time - at[i];
            sum_wait += wt[i];
            sum_turnaround += tat[i];
            flag = 0;
        }

        if (i == n - 1)
            i = 0;
        else if (at[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    // Display the table
    printf("\n\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], compt[i], tat[i], wt[i]);
    }

    printf("\nTotal waiting time: %d", sum_wait);
    printf("\nTotal turnaround time: %d", sum_turnaround);
    printf("\nAverage waiting time: %.2f", (float)sum_wait / n);
    printf("\nAverage turnaround time: %.2f", (float)sum_turnaround / n);

    return 0;
}

