public class ProcessThread extends Thread {
    private int pid;
    private int burstTime;

    public ProcessThread(int pid, int burstTime) {
        this.pid = pid;
        this.burstTime = burstTime;
    }

    public int getPid() {
        return pid;
    }

    public void run() {
        System.out.println("[Process " + pid + "] started.");
        try {
            Thread.sleep(burstTime * 1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("[Process " + pid + "] finished.");
    }
}
