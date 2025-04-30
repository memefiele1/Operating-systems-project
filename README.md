# Operating Systems Projects – Spring 2025

## 👥 Team Members
Miracle Emefiele  
Laura Zapata  

---

## 📄 Project 1: Process Scheduling Simulation

### 📋 Overview
This project simulates how an Operating System schedules processes using different CPU scheduling algorithms.

**Algorithms Implemented:**
- First-Come, First-Served (FCFS)
- Round Robin (RR)

**Process Format Includes:**
- Process ID (PID)
- Arrival Time
- Burst Time
- Priority

**The Simulation:**
- Displays the Gantt Chart showing execution order  
- Calculates Waiting Time (WT) and Turnaround Time (TAT)  
- Computes average WT and TAT

---

### 🗂️ Files for Project 1 (C)
- `main.c`: Reads `processes.txt`, schedules processes using FCFS and RR  
- `fcfs.c`: Implementation of FCFS  
- `rr.c`: Implementation of Round Robin  
- `processes.txt`: Input file listing all processes  
- `processes.h`: Shared structure and function declarations  
- `report_project1.pdf`: Final report  

---

### How to Compile and Run Project 1
```bash
gcc main.c fcfs.c rr.c processes.c -o scheduler
./scheduler
```

---

## 🧵 Project 2: Thread-Based Process Simulation and Synchronization

### 📋 Overview
This project simulates real-time process execution using threads and solves the **Producer-Consumer synchronization problem** using **Java threads, semaphores, and synchronized buffer access**.

Each process becomes a thread, and CPU burst times are simulated using `Thread.sleep()`.

**Producer-Consumer Behavior:**
- Producers add processes to a bounded buffer  
- Consumers remove and execute processes while ensuring thread-safe access  

---

### 🗂️ Files for Project 2 (Java)
- `Simulator.java`: Main driver class that manages producer and consumer threads  
- `ProcessThread.java`: Thread class representing a process with PID and burst time  
- `processes.txt`: Optional input file (can be hardcoded)  
- `report_project2.docx`: Final report for Project 2  

---

### 🛠️ How to Compile and Run Project 2
Inside the `os_project2/` folder:

```bash
javac Simulator.java ProcessThread.java
java Simulator
```

---

### 🔍 Sample Outputs

**Project 1 – Gantt Chart Example**
```
| P1 | P2 | P3 | P4 |
0    2    5    7    12
```

**Project 2 – Producer-Consumer Example**
```
[Producer] Waiting for buffer space...
[Producer] Added Process 2
[Consumer] Retrieved Process 2
[Process 2] started.
[Process 2] finished.
```

---

## 📁 Folder Structure

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
├── os_project2/
│   ├── Simulator.java
│   ├── ProcessThread.java
│   ├── processes.txt
│   └── report_project2.docx
│
└── README.md
```

---

## 📌 Notes
- Project 1 written in **C**
- Project 2 implemented in **Java**
- Project 2 uses **Java Semaphores**, **Threads**, and proper synchronization
- Designed and tested in **VS Code** and standard terminal
- Modular and organized structure for easy grading and extension

---


 
