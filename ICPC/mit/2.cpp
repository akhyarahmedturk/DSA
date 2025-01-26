
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;


bool canOrder(int n, int k, vector<vector<int>>& scores, vector<int>& result){
    vector<vector<int>> adj(n); // Adjacency list
    vector<int> in_degree(n, 0); // In-degree of each node

    // Build the graph
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j){
                bool valid = true;
                for (int team = 0; team < k; team++){
                    if (scores[i][team] > scores[j][team]){
                        valid = false;
                        break;
                    }
                }
                if (valid){
                    adj[i].push_back(j);
                    in_degree[j]++;
                }
            }
        }
    }

    // Perform topological sort (Kahn's algorithm)
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (in_degree[i] == 0) q.push(i);
    }

    while (!q.empty()){
        int curr = q.front();
        q.pop();
        result.push_back(curr);
        for (int neighbor : adj[curr]){
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) q.push(neighbor);
        }
    }

    // Check if we visited all nodes
    return result.size() == n;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> scores(n, vector<int>(k));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            cin >> scores[i][j];
        }
    }

    vector<int> result;
    if (canOrder(n, k, scores, result)){
        cout << "YES\n";
        for (int idx : result){
            cout << idx + 1 << " "; // Convert 0-based to 1-based indexing
        }
        cout << endl;
    }
    else{
        cout << "NO\n";
    }
    return 0;
}