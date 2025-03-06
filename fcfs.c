#include <stdio.h>
#include "processes.h"  // Use the header file

void fcfs(Process processes[], int n) {
    int waiting_time[n], turnaround_time[n], completion_time[n];

    // Sort processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Compute Completion Time, Turnaround Time, Waiting Time
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < processes[i].arrival_time) {
            time = processes[i].arrival_time;
        }
        completion_time[i] = time + processes[i].burst_time;
        turnaround_time[i] = completion_time[i] - processes[i].arrival_time;
        waiting_time[i] = turnaround_time[i] - processes[i].burst_time;
        time = completion_time[i];
    }

    // Print results with aligned columns
    printf("\nFirst-Come, First-Served (FCFS) Scheduling:\n");
    printf("%-5s %-8s %-6s %-11s %-10s %-7s\n", "PID", "Arrival", "Burst", "Completion", "Turnaround", "Waiting");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-8d %-6d %-11d %-10d %-7d\n", 
               processes[i].pid, 
               processes[i].arrival_time,
               processes[i].burst_time,
               completion_time[i],
               turnaround_time[i],
               waiting_time[i]);
    }
}
