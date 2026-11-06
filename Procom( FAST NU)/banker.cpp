#include <iostream>
#include <vector>

using namespace std;

int main(){
    // -------------------------------------------------------------------------
    // BANKER'S ALGORITHM FOR DEADLOCK AVOIDANCE
    // This algorithm checks if the system is in a "safe state" by simulating
    // the allocation of maximum possible required resources to each process.
    // -------------------------------------------------------------------------

    int processes, resources;

    // Step 1: Input the dimensions of our problem (number of processes and resource types)
    cout << "Enter number of processes: ";
    cin >> processes;
    cout << "Enter number of resources: ";
    cin >> resources;

    // -------------------------------------------------------------------------
    // DATA STRUCTURES INITIALIZATION
    // -------------------------------------------------------------------------
    // current (Allocation Matrix): Defines the resources currently allocated to each process.
    vector<vector<int>> current(processes, vector<int>(resources));

    // maximum_claim (Max Matrix): Defines the maximum demand of each process.
    vector<vector<int>> maximum_claim(processes, vector<int>(resources));

    // need (Need Matrix): Defines the remaining resources needed by each process (Max - Allocation).
    vector<vector<int>> need(processes, vector<int>(resources));

    // maxres (Claim Vector): Stores the total number of instances of each resource type in the entire system.
    vector<int> maxres(resources);

    // available: Stores the currently unallocated (free) instances of each resource type.
    vector<int> available(resources);

    // allocation_sum: Helper array to keep track of total allocated resources of each type.
    vector<int> allocation_sum(resources, 0);

    // running: Boolean array to track whether a process has finished executing (true = still needs to run).
    vector<bool> running(processes, true);

    // counter: Keeps track of how many processes are left to finish.
    int counter = processes;

    // Step 2: Input the total instances of all resources in the system
    cout << "\nEnter Claim Vector (Total System Resources): ";
    for (int i = 0; i < resources; i++){
        cin >> maxres[i];
    }

    // Step 3: Input the Allocation Matrix (which process holds how many resources currently)
    cout << "\nEnter Allocated Resource Table:\n";
    for (int i = 0; i < processes; i++){
        for (int j = 0; j < resources; j++){
            cin >> current[i][j];
            // Accumulate the allocated resources so we can find 'Available' resources later.
            allocation_sum[j] += current[i][j];
        }
    }

    // Step 4: Input the Maximum Claim Matrix (maximum needs of each process) and Calculate NEED
    cout << "\nEnter Maximum Claim Table:\n";
    for (int i = 0; i < processes; i++){
        for (int j = 0; j < resources; j++){
            cin >> maximum_claim[i][j];
            // Mathematical relation: Need[i][j] = Max[i][j] - Allocation[i][j]
            need[i][j] = maximum_claim[i][j] - current[i][j];
        }
    }

    // Step 5: Calculate Initial Available Resources
    // Available = Total System Resources - Total Allocated Resources
    for (int i = 0; i < resources; i++){
        available[i] = maxres[i] - allocation_sum[i];
    }

    cout << "\nInitial Available resources: ";
    for (int i = 0; i < resources; i++) cout << available[i] << " ";
    cout << endl;

    // -------------------------------------------------------------------------
    // Step 6: SAFETY ALGORITHM
    // Find a Safe Sequence iteratively.
    // -------------------------------------------------------------------------
    while (counter != 0){ // While there are still processes that haven't finished...
        bool safe_step = false; // Flag to check if we found a process that can execute in this iteration

        // Iterate through all processes to find one that can satisfy its 'Need' with 'Available' resources
        for (int i = 0; i < processes; i++){
            // Check only if the process hasn't finished yet
            if (running[i]){
                bool can_exec = true;

                // Compare Need with Available for ALL resource types
                for (int j = 0; j < resources; j++){
                    if (need[i][j] > available[j]){
                        can_exec = false; // If even one resource typed needed is more than available, it can't execute
                        break;
                    }
                }

                // If all resource needs can be fulfilled
                if (can_exec){
                    cout << "\nProcess " << i << " is executing";

                    // Mark process as finished
                    running[i] = false;
                    counter--; // Decrease the count of remaining processes
                    safe_step = true; // We progressed, so we aren't deadlocked yet

                    // When process finishes, it returns ALL its currently allocated resources back to the Available pool
                    // New Available = Available + Allocation
                    for (int j = 0; j < resources; j++){
                        available[j] += current[i][j];
                    }

                    // Print the updated available resources
                    cout << "\nAvailable vector now: ";
                    for (int res : available) cout << res << " ";
                    cout << endl;

                    // Break out of the inner loop to restart checking from process 0 with the new Available vector
                    break;
                }
            }
        }

        // If we looped through all processes and none could execute, we're stuck in an unsafe state
        if (!safe_step){
            cout << "\nTHE SYSTEM IS IN AN UNSAFE STATE (Deadlock potential)!" << endl;
            return 0;
        }
    }

    // If counter reached 0, every process finished successfully.
    cout << "\nTHE SYSTEM IS IN A SAFE STATE." << endl;
    return 0;
}

// // #include<iostream>
// // #include<vector>
// using namespace std;
// int main()
// {
//   int p,r;
//   cout<<"Enter the no of processess:";
//   cin>>p;
//   cout<<"Enter the no of resources:";
//   cin>>r;

//   vector<vector<int>> current(p, vector<int>(r));// allocation matrix
//   vector<vector<int>> max(p,vector<int>(r)); 
//   vector<vector<int>> need(p,vector<int>(r));
//   return 0;
// }