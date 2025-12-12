#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent a process
struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
};

// Function to sort processes by arrival time
bool compareArrivalTime(const Process &a, const Process &b)
{
    return a.arrivalTime < b.arrivalTime;
}

int main()
{
    std::vector<Process> processes = {
        {1, 0, 6},
        {2, 1, 8},
        {3, 2, 7},
        {4, 3, 3}};

    int n = processes.size();

    // Sort processes by arrival time initially
    std::sort(processes.begin(), processes.end(), compareArrivalTime);

    int currentTime = 0;
    float totalWaitingTime = 0;
    float totalTurnAroundTime = 0;

    std::cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n ";

    for (int i = 0; i < n; ++i)
    {
        // Find the process with the shortest burst time among arrived processes
        int shortestJobIndex = -1;
        int minBurst = -1;

        for (int j = 0; j < n; ++j)
        {
            if (processes[j].arrivalTime <= currentTime && processes[j].burstTime > 0)
            {
                if (shortestJobIndex == -1 || processes[j].burstTime < minBurst)
                {
                    minBurst = processes[j].burstTime;
                    shortestJobIndex = j;
                }
            }
        }

        if (shortestJobIndex == -1)
        { // No process arrived yet, increment time
            currentTime++;
            i--; // Re-evaluate the current time for the same iteration
            continue;
        }

        // Execute the shortest job
        processes[shortestJobIndex].completionTime = currentTime +
                                                     processes[shortestJobIndex].burstTime;

        processes[shortestJobIndex].turnAroundTime =
            processes[shortestJobIndex].completionTime - processes[shortestJobIndex].arrivalTime;

        processes[shortestJobIndex].waitingTime = processes[shortestJobIndex].turnAroundTime -
                                                  processes[shortestJobIndex].burstTime;

        totalWaitingTime += processes[shortestJobIndex].waitingTime;
        totalTurnAroundTime += processes[shortestJobIndex].turnAroundTime;

        currentTime = processes[shortestJobIndex].completionTime;
        processes[shortestJobIndex].burstTime = 0; // Mark as completed

        // Print details of the completed process
        std::cout << processes[shortestJobIndex].id << "\t\t"
                  << processes[shortestJobIndex].arrivalTime << "\t\t"
                  << processes[shortestJobIndex].burstTime << " (completed)\t\t" // Display burst time as 0 after completion
                  << processes[shortestJobIndex].completionTime << "\t\t"
                  << processes[shortestJobIndex].turnAroundTime << "\t\t"
                  << processes[shortestJobIndex].waitingTime << "\n";
    }
    std::cout << "\nAverage Waiting Time: " << totalWaitingTime / n << std::endl;
    std::cout << "Average Turnaround Time: " << totalTurnAroundTime / n << std::endl;
    return 0;
}