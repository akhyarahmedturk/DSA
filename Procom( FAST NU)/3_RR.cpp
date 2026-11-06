#include <iostream>
using namespace std;

int main()
{
    int n, tq; 
    // n = number of processes
    // tq = Time Quantum (fixed time slice)

    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n];     // BT = Burst Time (original)
    int rem[n];    // rem = Remaining Burst Time
    int wt[n];     // WT = Waiting Time
    int tat[n];    // TAT = Turnaround Time

    // Input Burst Time
    for(int i = 0; i < n; i++)
    {
        cout << "Enter Burst Time for Process P" << i << ": ";
        cin >> bt[i];

        rem[i] = bt[i]; // Initially remaining time = burst time
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int time = 0; // current CPU time
    bool done;

    // Round Robin Execution
    do
    {
        done = true;

        for(int i = 0; i < n; i++)
        {
            // If process still has remaining time
            if(rem[i] > 0)
            {
                done = false;

                // If remaining time is greater than time quantum
                if(rem[i] > tq)
                {
                    time += tq;
                    rem[i] -= tq;
                }
                else
                {
                    // Process finishes execution
                    time += rem[i];
                    tat[i] = time; // Completion time = TAT
                    rem[i] = 0;
                }
            }
        }

    } while(!done);

    float avgWT = 0, avgTAT = 0;

    // Calculate Waiting Time
    for(int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i]; // WT = TAT - BT

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    // Display results
    cout << "\nProcess\tBT\tWT\tTAT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << i << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << avgWT / n;
    cout << "\nAverage Turnaround Time = " << avgTAT / n;

    return 0;
}