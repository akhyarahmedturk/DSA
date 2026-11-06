#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& alloc,
            vector<vector<int>>& maxm,
            vector<int>& avail,
            int p, int r)
{
    vector<vector<int>> need(p, vector<int>(r));
    vector<bool> finish(p, false);
    vector<int> safeSeq;

    // Calculate Need Matrix
    for(int i = 0; i < p; i++)
        for(int j = 0; j < r; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    int count = 0;

    while(count < p)
    {
        bool found = false;

        for(int i = 0; i < p; i++)
        {
            if(!finish[i])
            {
                int j;
                for(j = 0; j < r; j++)
                {
                    if(need[i][j] > avail[j])
                        break;
                }

                if(j == r)
                {
                    for(int k = 0; k < r; k++)
                        avail[k] += alloc[i][k];

                    safeSeq.push_back(i);
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if(!found)
        {
            cout << "\nSystem is in UNSAFE state / Deadlock possible.\n";
            return false;
        }
    }

    cout << "\nSystem is in SAFE state.\nSafe Sequence: ";
    for(int i : safeSeq)
        cout << "P" << i << " ";

    cout << endl;
    return true;
}

int main()
{
    int choice, p, r;

    cout << "1. Deadlock Detection\n";
    cout << "2. Banker's Algorithm\n";
    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter number of processes: ";
    cin >> p;

    cout << "Enter number of resources: ";
    cin >> r;

    vector<vector<int>> alloc(p, vector<int>(r));
    vector<vector<int>> maxm(p, vector<int>(r));
    vector<int> avail(r);

    cout << "\nEnter Allocation Matrix:\n";
    for(int i = 0; i < p; i++)
        for(int j = 0; j < r; j++)
            cin >> alloc[i][j];

    cout << "\nEnter Maximum Matrix:\n";
    for(int i = 0; i < p; i++)
        for(int j = 0; j < r; j++)
            cin >> maxm[i][j];

    if(choice == 1)
    {
        // Deadlock Detection
        cout << "\nEnter Available Resources:\n";
        for(int i = 0; i < r; i++)
            cin >> avail[i];
    }
    else if(choice == 2)
    {
        // Banker's Algorithm
        vector<int> total(r), allocatedSum(r, 0);

        cout << "\nEnter Total System Resources:\n";
        for(int i = 0; i < r; i++)
            cin >> total[i];

        for(int i = 0; i < p; i++)
            for(int j = 0; j < r; j++)
                allocatedSum[j] += alloc[i][j];

        for(int i = 0; i < r; i++)
            avail[i] = total[i] - allocatedSum[i];
    }
    else
    {
        cout << "Invalid choice.\n";
        return 0;
    }

    isSafe(alloc, maxm, avail, p, r);

    return 0;
}