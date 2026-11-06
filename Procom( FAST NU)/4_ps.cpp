#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n];    // BT = Burst Time
    int pri[n];   // PRI = Priority (smaller value = higher priority)
    int p[n];     // Process ID
    int wt[n];    // WT = Waiting Time
    int tat[n];   // TAT = Turnaround Time

    float avgWT = 0, avgTAT = 0;

    // Input Burst Time and Priority
    for(int i = 0; i < n; i++)
    {
        p[i] = i; // Assign process number

        cout << "Enter Burst Time and Priority for Process P" << i << ": ";
        cin >> bt[i] >> pri[i];
    }

    // Sorting based on Priority (Ascending order)
    // Smaller priority number = higher priority
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(pri[i] > pri[j])
            {
                // Swap priority
                swap(pri[i], pri[j]);

                // Swap burst time
                swap(bt[i], bt[j]);

                // Swap process ID
                swap(p[i], p[j]);
            }
        }
    }

    // First process has no waiting time
    wt[0] = 0;

    // First process TAT = BT
    tat[0] = bt[0];

    // Calculate WT and TAT
    for(int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];

        tat[i] = wt[i] + bt[i];
    }

    // Calculate averages
    for(int i = 0; i < n; i++)
    {
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    // Display table
    cout << "\nProcess\tPriority\tBT\tWT\tTAT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t"
             << pri[i] << "\t\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << avgWT / n;
    cout << "\nAverage Turnaround Time = " << avgTAT / n;

    return 0;
}