

public class ProcessThread extends Thread {
    int pid;           // Process ID
    int burstTime;     // CPU burst time in seconds

    // Constructor to initialize the PID and burst time
    public ProcessThread(int pid, int burstTime) {
        this.pid = pid;
        this.burstTime = burstTime;
    }

    // Override the run method to simulate process execution
    public void run() {
        System.out.println("Process " + pid + " started.");
        try {
            Thread.sleep(burstTime * 1000);  // Sleep for burst time in seconds
        } catch (InterruptedException e) {
            System.out.println("Process " + pid + " interrupted.");
        }
        System.out.println("Process " + pid + " finished.");
    }
}
