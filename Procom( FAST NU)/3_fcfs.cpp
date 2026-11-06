#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n; // Number of processes

    cout << "Enter number of processes: ";
    cin >> n;

    // Arrays to store:
    vector<int>bt(n);   // BT = Burst Time
    vector<int>wt(n);   // WT = Waiting Time
    vector<int>tat(n);  // TAT = Turnaround Time

    float avgWT = 0, avgTAT = 0; // Average values

    // Input burst time for each process
    for(int i = 0; i < n; i++) 
    {
        cout << "Enter Burst Time for Process P" << i << ": ";
        cin >> bt[i];
    }

    // First process does not wait
    wt[0] = 0;

    // Turnaround time of first process = its burst time
    tat[0] = bt[0];

    // Calculate WT and TAT for remaining processes
    for(int i = 1; i < n; i++) 
    {
        wt[i] = wt[i-1] + bt[i-1];

        tat[i] = wt[i] + bt[i];
    }

    // Calculate average waiting and turnaround time
    for(int i = 0; i < n; i++) 
    {
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    // Display output table
    cout << "\nProcess\tBT\tWT\tTAT\n";

    for(int i = 0; i < n; i++) 
    {
        cout << "P" << i << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    // Print averages
    cout << "\nAverage Waiting Time = " << avgWT / n;
    cout << "\nAverage Turnaround Time = " << avgTAT / n;

    return 0;
}