import java.util.LinkedList;
import java.util.concurrent.Semaphore;

public class Simulator {

    static LinkedList<ProcessThread> buffer = new LinkedList<>();
    static final int BUFFER_SIZE = 3;

    static Semaphore mutex = new Semaphore(1);      
    static Semaphore empty = new Semaphore(BUFFER_SIZE); 
    static Semaphore full = new Semaphore(0);       

    public static void main(String[] args) {

        Thread producer = new Thread(() -> {
            try {
                int[][] processList = {
                    {1, 4},
                    {2, 3},
                    {3, 2},
                    {4, 1}
                };

                for (int[] p : processList) {
                    ProcessThread pt = new ProcessThread(p[0], p[1]);

                    System.out.println("[Producer] Waiting for buffer space...");
                    empty.acquire(); 

                    System.out.println("[Producer] Waiting for mutex to add Process " + p[0]);
                    mutex.acquire(); 

                    buffer.add(pt);
                    System.out.println("[Producer] Added Process " + p[0]);

                    mutex.release(); 
                    full.release();  

                    Thread.sleep(500); 
                }

            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread consumer = new Thread(() -> {
            try {
                while (true) {
                    System.out.println("[Consumer] Waiting for available item...");
                    full.acquire();  

                    System.out.println("[Consumer] Waiting for mutex to retrieve process");
                    mutex.acquire(); 

                    ProcessThread pt = buffer.removeFirst();
                    System.out.println("[Consumer] Retrieved Process " + pt.getPid());

                    mutex.release(); 
                    empty.release(); 

                    pt.start();      
                    pt.join();       
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        producer.start();
        consumer.start();
    }
}

