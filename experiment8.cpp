#include <iostream>
#include <vector>

// Structure to represent a process
struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

// Function to calculate FCFS scheduling metrics
void calculateFCFS(std::vector<Process> &processes)
{
    int currentTime = 0;

    // Sort processes by arrival time (if not already sorted)
    // For simplicity, this example assumes processes are already in arrival order
    // If arrival times can be different, sorting would be required here.

    for (int i = 0; i < processes.size(); ++i)
    {
        // If the current time is less than the process's arrival time,
        // the CPU is idle until the process arrives.
        if (currentTime < processes[i].arrivalTime)
        {
            currentTime = processes[i].arrivalTime;
        }

        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        currentTime = processes[i].completionTime;
    }
}

// Function to display process details and averages
void displayResults(const std::vector<Process> &processes)
{
    std::cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n "; 
        std::cout << "--------------------------------------------------------------------------------------\n";

    double totalWaitingTime = 0;
    double totalTurnaroundTime = 0;

    for (const auto &p : processes)
    {
        std::cout << "P" << p.id << "\t\t" << p.arrivalTime << "\t\t" << p.burstTime << "\t\t"
                  << p.completionTime << "\t\t" << p.turnaroundTime << "\t\t\t" << p.waitingTime << "\n";
        totalWaitingTime += p.waitingTime;
        totalTurnaroundTime += p.turnaroundTime;
    }

    std::cout << "\nAverage Waiting Time: " << totalWaitingTime / processes.size() << std::endl;
    std::cout << "Average Turnaround Time: " << totalTurnaroundTime / processes.size() << std::endl;
}

int main()
{
    // Example processes
    std::vector<Process> processes = {
        {1, 0, 10}, // P1 arrives at 0, burst time 10
        {2, 2, 5},  // P2 arrives at 2, burst time 5
        {3, 4, 8}   // P3 arrives at 4, burst time 8
    };
    calculateFCFS(processes);
    displayResults(processes);
    return 0;
}