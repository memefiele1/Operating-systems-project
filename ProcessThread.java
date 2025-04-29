package project2_OS;

public class ProcessThread extends Thread {
    int pid, arrival, burst;

    public ProcessThread(int pid, int arrival, int burst) {
        this.pid = pid;
        this.arrival = arrival;
        this.burst = burst;
    }

    public void run() {
        try {
            System.out.println("Process " + pid + " started. (Arrival: " + arrival + ", Burst: " + burst + ")");
            Thread.sleep(burst * 1000);
            System.out.println("Process " + pid + " finished.");
        } catch (InterruptedException e) {
            System.out.println("Process " + pid + " interrupted.");
        }
    }
}


