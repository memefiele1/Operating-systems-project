
import java.io.*;
import java.util.*;

public class Simulator {
    public static void main(String[] args) {
        List<ProcessThread> processThreads = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader("processes.txt"))) {
            String line;
            boolean firstLine = true; // Flag to skip the header

            while ((line = br.readLine()) != null) {
                if (firstLine) {
                    firstLine = false; // Skip header line
                    continue;
                }

                if (line.trim().isEmpty()) continue;  // Skip empty lines

                String[] parts = line.trim().split("\\s+"); // Split line by spaces

                // Parse PID and burst time
                int pid = Integer.parseInt(parts[0]);
                int arrivalTime = Integer.parseInt(parts[1]);
                int burstTime = Integer.parseInt(parts[2]);

                // Create a new thread for the process
                processThreads.add(new ProcessThread(pid, burstTime));
            }
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }

        // Start all threads
        for (ProcessThread pt : processThreads) {
            pt.start();
        }

        // Wait for all threads to complete
        for (ProcessThread pt : processThreads) {
            try {
                pt.join();
            } catch (InterruptedException e) {
                System.out.println("Join interrupted.");
            }
        }

        System.out.println("✅ All processes completed.");
    }
}
