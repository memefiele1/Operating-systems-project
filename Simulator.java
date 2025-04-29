package project2_OS;

import java.io.*;
import java.util.*;

public class Simulator {
    public static void main(String[] args) {
        List<ProcessThread> processThreads = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader("processes.txt"))) {
            String line;
            boolean firstLine = true; // Add a flag to skip the first line

            while ((line = br.readLine()) != null) {
                if (firstLine) {
                    firstLine = false; // Skip the header line
                    continue;
                }
                
                if (line.trim().isEmpty()) continue;
                
                String[] parts = line.trim().split("\\s+");
                
                // Parse the process information from the line
                int pid = Integer.parseInt(parts[0]);
                int arrival = Integer.parseInt(parts[1]);
                int burst = Integer.parseInt(parts[2]);

                // Add the process thread to the list
                processThreads.add(new ProcessThread(pid, arrival, burst));
            }
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }

        // Start all threads
        for (ProcessThread pt : processThreads) {
            pt.start();
        }

        // Wait for all to complete
        for (ProcessThread pt : processThreads) {
            try {
                pt.join();
            } catch (InterruptedException e) {
                System.out.println("Join interrupted.");
            }
        }

        System.out.println("All processes completed.");
    }
}
