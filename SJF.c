#include <stdio.h>
#include <stdlib.h>

struct sjf {
    int pid;
    int btime;  // Burst time
    int atime;  // Arrival time
    int cptime; // Completion time
    int ttime;  // Turnaround time
    int wtime;  // Waiting time
} p[10];

int main() {
    int i, j, n;
    int totwtime = 0, totttime = 0;
    struct sjf temp;

    printf("\n____SJF Scheduling____\n");
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter process id: P");
        scanf("%d", &p[i].pid);
        printf("Enter arrival time of P%d: ", p[i].pid);
        scanf("%d", &p[i].atime);
        printf("Enter burst time of P%d: ", p[i].pid);
        scanf("%d", &p[i].btime);
    }

    // Sort by arrival time first, then by burst time for processes that have arrived
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].atime > p[j].atime || (p[i].atime == p[j].atime && p[i].btime > p[j].btime)) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Initialize the first process
    p[0].cptime = p[0].atime + p[0].btime;
    p[0].ttime = p[0].cptime - p[0].atime;
    p[0].wtime = p[0].ttime - p[0].btime;
    totwtime += p[0].wtime;
    totttime += p[0].ttime;

    // Calculate completion, turnaround, and waiting times for all processes
    for (i = 1; i < n; i++) {
        int min = i;
        for (j = i + 1; j < n && p[j].atime <= p[min].cptime; j++) {
            if (p[j].btime < p[min].btime) {
                min = j;
            }
        }
        if (min != i) {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
        if (p[i].atime > p[i - 1].cptime) {
            p[i].cptime = p[i].atime + p[i].btime;
        } else {
            p[i].cptime = p[i - 1].cptime + p[i].btime;
        }
        p[i].ttime = p[i].cptime - p[i].atime;
        p[i].wtime = p[i].ttime - p[i].btime;
        totwtime += p[i].wtime;
        totttime += p[i].ttime;
    }

    // Display the table
    printf("\n\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].atime, p[i].btime, p[i].cptime, p[i].ttime, p[i].wtime);
    }

    printf("\nTotal waiting time : %d", totwtime);
    printf("\nTotal turn around time: %d", totttime);
    printf("\nAverage waiting time : %.2f", (float)totwtime / n);
    printf("\nAverage turn around time: %.2f", (float)totttime / n);

    return 0;
}
