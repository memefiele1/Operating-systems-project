

#include <stdio.h>
#include <stdlib.h>
#include "processes.h"  // Include the header file

void read_processes(Process processes[], int *count) {
    FILE *file = fopen("processes.txt", "r");
    if (file == NULL) {
        printf("Error opening file! Make sure processes.txt is in the same directory.\n");
        exit(1);
    }

    char buffer[100];
    fgets(buffer, sizeof(buffer), file);  // Skip header line

    *count = 0;
    while (fscanf(file, "%d %d %d %d", 
                  &processes[*count].pid, 
                  &processes[*count].arrival_time,
                  &processes[*count].burst_time, 
                  &processes[*count].priority) != EOF) {
        (*count)++;
    }

    fclose(file);
}
