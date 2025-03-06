/* File: process_scheduling.c */
#include <stdio.h>
#include <stdlib.h>
#include "processes.h"

#define TIME_QUANTUM 2 // Define time quantum for Round Robin

// Function prototypes
void fcfs(Process processes[], int n);
void round_robin(Process processes[], int n);
void priority_scheduling(Process processes[], int n);
void display_gantt_chart(Process processes[], int n);

// Function to implement Round Robin scheduling
void round_robin(Process processes[], int n) {
    int remaining_time[MAX_PROCESSES], waiting_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES], completion_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
        waiting_time[i] = 0;
    }

    int time = 0, completed = 0;
    while (completed < n) {
        int process_executed = 0;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && processes[i].arrival_time <= time) {
                process_executed = 1;
                if (remaining_time[i] > TIME_QUANTUM) {
                    time += TIME_QUANTUM;
                    remaining_time[i] -= TIME_QUANTUM;
                } else {
                    time += remaining_time[i];
                    waiting_time[i] = time - processes[i].arrival_time - processes[i].burst_time;
                    remaining_time[i] = 0;
                    completion_time[i] = time;
                    completed++;
                }
            }
        }
        if (!process_executed) {
            time++;
        }
    }

    // Compute turnaround time
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = processes[i].burst_time + waiting_time[i];
    }

    // Print results
    printf("\nRound Robin Scheduling:\n");
    printf("%-5s %-8s %-6s %-11s %-10s %-7s\n", "PID", "Arrival", "Burst", "Completion", "Turnaround", "Waiting");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-8d %-6d %-11d %-10d %-7d\n", 
               processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               completion_time[i], turnaround_time[i], waiting_time[i]);
    }
}

// Function to implement Priority Scheduling
void priority_scheduling(Process processes[], int n) {
    int waiting_time[MAX_PROCESSES], turnaround_time[MAX_PROCESSES], completion_time[MAX_PROCESSES];
    
    // Sort processes based on priority (lower number = higher priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].priority > processes[j].priority) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    
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
    
    // Print results
    printf("\nPriority Scheduling:\n");
    printf("%-5s %-8s %-6s %-8s %-11s %-10s %-7s\n", "PID", "Arrival", "Burst", "Priority", "Completion", "Turnaround", "Waiting");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-8d %-6d %-8d %-11d %-10d %-7d\n", 
               processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               processes[i].priority, completion_time[i], turnaround_time[i], waiting_time[i]);
    }
}

// Function to display Gantt Chart
void display_gantt_chart(Process processes[], int n) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%-2d ", processes[i].pid);
    }
    printf("|\n");

    int time = 0;
    printf("%-5d", time);
    for (int i = 0; i < n; i++) {
        time += processes[i].burst_time;
        printf("%-6d", time);
    }
    printf("\n");
}

int main() {
    Process processes[MAX_PROCESSES];
    int count = 0;

    read_processes(processes, &count);  // Read from file
    fcfs(processes, count);  // Run FCFS scheduling
    round_robin(processes, count);  // Run Round Robin scheduling
    priority_scheduling(processes, count);  // Run Priority scheduling
    display_gantt_chart(processes, count);  // Display Gantt Chart
    return 0;
}
