#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

//cycle detection
bool isCyclic(vector<vector<int>>& graph, int vertex, vector<bool>& visited, vector<bool>& recStack) {
    visited[vertex] = true;
    recStack[vertex] = true;
    for (int i : graph[vertex]) {
        if (!visited[i] && isCyclic(graph, i, visited, recStack)) return true;
        else if (recStack[i]) return true;
    }
    recStack[vertex] = false;
    return false;
}

// topological sort
void Topo_sort(vector<vector<int>>& graph, int vertex, vector<bool>& visited, stack<int>& s){
    visited[vertex] = true;
    for (int i = 0;i < graph[vertex].size();i++){
        if (!visited[graph[vertex][i]])
            Topo_sort(graph, graph[vertex][i], visited, s);
    }
    s.push(vertex);
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> graph(n + 1);
    vector<bool> main(n + 1, false);
    for (int i = 0;i < k;i++){
        int temp;
        cin >> temp;
        main[temp] = true;
    }
    for (int i = 1;i <= n;i++){
        int size = 0;
        cin >> size;
        while (size--){
            int temp;
            cin >> temp;
            graph[i].push_back(temp);
        }
    }
    vector<bool> visited(n + 1, false);
    vector<bool> recStack(n + 1, false);
    bool has_cycle = false;
    for (int i = 1;i <= n;i++){
        if (main[i] && !visited[i] && isCyclic(graph, i, visited,recStack)){
            has_cycle = true;
            break;
        }
    }
    if (!has_cycle){
        stack<int> s;
        vector<bool> visited(n + 1, false);
        for (int i = 1;i <= n;i++)
            if (!visited[i] && main[i]) Topo_sort(graph, i, visited, s);
        int size = s.size(), ssize = s.size();
        vector<int> order(size, 0);
        cout << size << endl;
        while (size--){
            order[size] = s.top();
            s.pop();
        }
        for (int i = 0; i < ssize; i++){
            cout << order[i] << " ";
        }
        cout << endl;
    }
    else cout << "-1" << endl;
    return 0;
}