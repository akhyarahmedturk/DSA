#include <iostream>
using namespace std;

int maxm[100][100];     // Maximum resources needed
int alloc[100][100];    // Allocated resources
int need[100][100];     // Remaining need
int avail[100];         // Available resources

int n, r; // n = processes, r = resources

// 🔹 Input function
void input() {
    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> r;

    cout << "Enter Max Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            cin >> maxm[i][j];
        }
    }

    cout << "Enter Allocation Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            cin >> alloc[i][j];
        }
    }

    cout << "Enter Available Resources:\n";
    for(int j = 0; j < r; j++) {
        cin >> avail[j];
    }
}


// 🔹 Deadlock Detection Function
void calculate() {
    int finish[100] = {0};   // 0 = not finished, 1 = finished
    int safeSeq[100];        // To store safe sequence
    int dead[100];           // To store deadlocked processes
    int count = 0;

    // 🔹 Step 1: Calculate NEED matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            need[i][j] = maxm[i][j] - alloc[i][j];
        }
    }

    // 🔹 Step 2: Try to find safe sequence
    bool progress = true;

    while(progress) {
        progress = false;

        for(int i = 0; i < n; i++) {

            if(finish[i] == 0) { // if process not finished
                int j;

                // Check if need <= available
                for(j = 0; j < r; j++) {
                    if(need[i][j] > avail[j])
                        break;
                }

                // If all resources satisfied
                if(j == r) {
                    // Process can run
                    for(int k = 0; k < r; k++) {
                        avail[k] += alloc[i][k]; // release resources
                    }

                    finish[i] = 1;
                    safeSeq[count++] = i;
                    progress = true;
                }
            }
        }
    }

    // 🔹 Step 3: Check for deadlock
    bool deadlock = false;
    int dcount = 0;

    for(int i = 0; i < n; i++) {
        if(finish[i] == 0) {
            deadlock = true;
            dead[dcount++] = i;
        }
    }

    // 🔹 Output result
    if(deadlock) {
        cout << "\nSystem is in DEADLOCK!\n";
        cout << "Deadlocked processes: ";
        for(int i = 0; i < dcount; i++) {
            cout << "P" << dead[i] << " ";
        }
    } else {
        cout << "\nSystem is in SAFE state.\n";
        cout << "Safe sequence: ";
        for(int i = 0; i < count; i++) {
            cout << "P" << safeSeq[i] << " ";
        }
    }
}

// 🔹 Main function
int main() {
    cout << "***** Deadlock Detection Algorithm *****\n";

    input();
    // show();
    calculate();

    return 0;
}