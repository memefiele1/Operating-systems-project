#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

// This defines a structure to hold process details
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
} Process;

int main() {
    FILE *file = fopen("processes.txt", "r");
    if (file == NULL) {
        printf("Error opening file! Make sure processes.txt is in the same directory.\n");
        return 1;
    }

    Process processes[MAX_PROCESSES];  // This is an array to store processes
    int count = 0;  // Process counter

    char buffer[100];
    fgets(buffer, sizeof(buffer), file);

    // This reads process data from the file
    while (fscanf(file, "%d %d %d %d", 
                  &processes[count].pid, 
                  &processes[count].arrival_time,
                  &processes[count].burst_time, 
                  &processes[count].priority) != EOF) {
        count++;
    }

    fclose(file);

    // Display the processes read from the file
    printf("Processes Read from File:\n");
    printf("PID  Arrival_Time  Burst_Time  Priority\n");
    for (int i = 0; i < count; i++) {
        printf("%d    %d            %d           %d\n", 
               processes[i].pid, 
               processes[i].arrival_time,
               processes[i].burst_time, 
               processes[i].priority);
    }

    return 0;
}
