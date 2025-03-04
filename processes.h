#ifndef PROCESSES_H
#define PROCESSES_H

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
} Process;

void read_processes(Process processes[], int *count);

#endif

