#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

bool DFS(int vertex, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& in_path){
    visited[vertex] = true;
    in_path[vertex] = true;
    for (int i = 0;i < graph[vertex].size();i++){
        if (!visited[graph[vertex][i]]){
            if (DFS(graph[vertex][i], graph, visited, in_path)){
                return true;
            }
        }
        else if (in_path[graph[vertex][i]]){
            return true;
        }
    }
    in_path[vertex] = false;
    return false;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<vector<int>>& graph){
    vector<bool> visited(V);
    vector<bool> in_path(V);
    for (int i = 0;i < V;i++){
        if (!visited[i]){
            if (DFS(i, graph, visited, in_path)) return true;
        }
    }
    return false;
}

int main(){
    int V = 4;
    vector<vector<int>> adj_list = { {1,2},{2,3},{3,1},{0,1} };
    if (isCyclic(V, adj_list)){
        cout << "Graph has a cycle!" << endl;
    }
    else{
        cout << "Graph not have a cycle!" << endl;
    }
    return 0;
}