#include <iostream>
using namespace std;

int main()
{
    int n; // Number of processes

    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n];   // BT = Burst Time
    int wt[n];   // WT = Waiting Time
    int tat[n];  // TAT = Turnaround Time
    int p[n];    // Process number

    float avgWT = 0, avgTAT = 0;

    // Input burst time
    for(int i = 0; i < n; i++)
    {
        p[i] = i; // Assign process ID

        cout << "Enter Burst Time for Process P" << i << ": ";
        cin >> bt[i];
    }

    // Sorting burst times in ascending order
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                swap(bt[i], bt[j]);
                swap(p[i], p[j]);
            }
        }
    }

    // First process waiting time is 0
    wt[0] = 0;

    // First process turnaround time = burst time
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

    // Display result
    cout << "\nProcess\tBT\tWT\tTAT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << avgWT / n;
    cout << "\nAverage Turnaround Time = " << avgTAT / n;

    return 0;
}