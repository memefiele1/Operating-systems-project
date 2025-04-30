# Operating Systems Project - Spring 2025

## 👥 Team Members
Miracle Emefiele and Laura Zapata

---

# 📄 Project 1: Process Scheduling Simulation

### Overview
This project simulates how an Operating System schedules processes using different CPU scheduling algorithms.  
We implemented two algorithms:
- **First-Come, First-Served (FCFS)**
- **Round Robin (RR)**

Each process was described by:
- Process ID (PID)
- Arrival Time
- Burst Time
- Priority

The simulation:
- Displays the Gantt Chart showing execution order.
- Calculates **Waiting Time (WT)** and **Turnaround Time (TAT)** for each process.
- Computes **average WT** and **average TAT**.

---

### 🗂️ Files for Project 1
- `main.c`: Reads `processes.txt`, schedules processes using FCFS and RR.
- `fcfs.c`: Implementation of First-Come, First-Served scheduling.
- `rr.c`: Implementation of Round Robin scheduling.
- `processes.txt`: Input file listing all processes.
- `processes.h`: Shared structure and function declarations.
- `report_project1.pdf`: Detailed project report.

---

### How to Compile and Run Project 1
```bash
gcc main.c fcfs.c rr.c processes.c -o scheduler
./scheduler
```

---

# Project 2: Thread-Based Process Simulation and Synchronization

### 📋 Overview
This project simulates real-time process execution using threads and solves the classic **Producer-Consumer** synchronization problem using semaphores and mutex locks.

Each process becomes a **thread**, and we simulate CPU burst times using `sleep()`.

Synchronization ensures:
- Producers add processes into a bounded buffer.
- Consumers remove and execute processes while preventing race conditions.

---

### 🗂️ Files for Project 2
- `main.c`: Starts producer and consumer threads.
- `producer_consumer.c`: Handles producer and consumer logic, synchronization.
- `producer_consumer.h`: Shared data structures and function declarations.
- `processes.txt`: Input file (can reuse from Project 1).
- `Makefile`: (Optional) to compile using `make`.
- `report_project2.docx`: Final report for Project 2.

---

### How to Compile and Run Project 2
```bash
make
./project2
```
(Or manually compile with)
```bash
gcc main.c producer_consumer.c -lpthread -o project2
./project2
```

---

# Sample Outputs

### Project 1: Gantt Chart Example
```
| P1 | P2 | P3 | P4 |
0    2    5    7    12
```

### Project 2: Producer-Consumer Example
```
[Producer] Process 1 added to buffer at slot 0
[Consumer] Process 1 removed from buffer at slot 0
[Consumer] Executing process 1 for 4 seconds...
[Consumer] Process 1 completed
```

---

# Folder Structure

```
Operating-systems-project/
├── Project1/
│   ├── fcfs.c
│   ├── rr.c
│   ├── main.c
│   ├── processes.c
│   ├── processes.h
│   ├── processes.txt
│   └── report_project1.pdf
│
├── Project2/
│   ├── main.c
│   ├── producer_consumer.c
│   ├── producer_consumer.h
│   ├── processes.txt
│   ├── Makefile
│   └── report_project2.docx
│
└── README.md
```

---

# Notes
- Projects written in **C**.
- Uses **pthreads**, **mutex**, and **semaphores** for Project 2.
- Organized in modular `.c` and `.h` files.
- Tested on Linux/macOS terminals and MinGW on Windows.
- Built with basic GCC compilation.
 
