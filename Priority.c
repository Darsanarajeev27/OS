#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, temp1, temp2, n, bt[10], wt[10], tat[10], p[10], at[10], compt[10];
    float sumwt = 0.0, sumtat = 0.0;
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter arrival time of P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter priority of P%d: ", i + 1);
        scanf("%d", &p[i]);
    }

    // Sort by priority, and if priority is the same, sort by arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i] > p[j] || (p[i] == p[j] && at[i] > at[j])) {
                temp1 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp1;
                
                temp1 = at[i];
                at[i] = at[j];
                at[j] = temp1;
                
                temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
            }
        }
    }

    compt[0] = at[0] + bt[0];
    wt[0] = 0;  // Waiting time for first process is zero since it starts immediately
    tat[0] = compt[0] - at[0];
    sumtat += tat[0];
    sumwt += wt[0];
    for (i = 1; i < n; i++) {
        if (compt[i - 1] < at[i]) {
            compt[i] = at[i] + bt[i];  // If the CPU is idle until the process arrives
        } else {
            compt[i] = compt[i - 1] + bt[i];
        }
        wt[i] = compt[i] - at[i] - bt[i];
        tat[i] = compt[i] - at[i];
        sumwt += wt[i];
        sumtat += tat[i];
    }

    // Display the table
    printf("\n\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], p[i], compt[i], tat[i], wt[i]);
    }

    printf("\nTotal waiting time: %.2f", sumwt);
    printf("\nTotal turnaround time: %.2f", sumtat);
    printf("\nAverage waiting time: %.2f", sumwt / n);
    printf("\nAverage turnaround time: %.2f", sumtat / n);

    return 0;
}
