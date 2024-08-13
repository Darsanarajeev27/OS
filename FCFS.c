#include <stdio.h>
#include <stdlib.h>

struct fcfs {
    int pid;
    int atime;  // Arrival time
    int btime;  // Burst time
    int ctime;  // Completion time
    int wtime;  // Waiting time
    int ttime;  // Turnaround time
} p[10];

int main() {
    int i, n;
    int totwtime = 0, totttime = 0;
    printf("\n_____FCFS Scheduling____\n");
    printf("Enter the no. of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter arrival time of the process %d: ", i + 1);
        scanf("%d", &p[i].atime);
        printf("Enter burst time of the process %d: ", i + 1);
        scanf("%d", &p[i].btime);
    }

    // Sort processes by arrival time
    for (i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].atime > p[j].atime) {
                struct fcfs temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculations for waiting time, turnaround time, and completion time
    p[0].ctime = p[0].atime + p[0].btime;
    p[0].ttime = p[0].ctime - p[0].atime;
    p[0].wtime = p[0].ttime - p[0].btime;
    totwtime += p[0].wtime;
    totttime += p[0].ttime;

    for (i = 1; i < n; i++) {
        if (p[i].atime > p[i-1].ctime) {
            p[i].ctime = p[i].atime + p[i].btime;
        } else {
            p[i].ctime = p[i-1].ctime + p[i].btime;
        }
        p[i].ttime = p[i].ctime - p[i].atime;
        p[i].wtime = p[i].ttime - p[i].btime;
        totwtime += p[i].wtime;
        totttime += p[i].ttime;
    }

    // Display the table
    printf("\n\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].atime, p[i].btime, p[i].ctime, p[i].ttime, p[i].wtime);
    }

    printf("\nTotal waiting time : %d", totwtime);
    printf("\nTotal turn around time: %d", totttime);
    printf("\nAverage waiting time : %.2f", (float)totwtime / n);
    printf("\nAverage turn around time: %.2f", (float)totttime / n);
    return 0;
}
