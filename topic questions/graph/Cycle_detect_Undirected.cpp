#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

//using BFS
bool BFS(int vertex, vector<vector<int>>& graph, vector<bool>& visited){
    int V = graph.size();
    vector<int> parent(V, -1);
    queue<int> q;
    q.push(vertex);
    while (!q.empty()){
        int vertex = q.front();
        visited[vertex] = true;
        q.pop();
        for (int i = 0;i < graph[vertex].size();i++){
            parent[graph[vertex][i]] = vertex;
            if (!visited[graph[vertex][i]]){
                q.push(graph[vertex][i]);
            }
            else if (graph[vertex][i] != parent[vertex]){
                return true;
            }
        }
    }
    return false;
}

// using DFS
bool DFS(int vertex, vector<vector<int>>& graph, vector<bool>& visited, int parent){
    visited[vertex] = true;
    for (int i = 0;i < graph[vertex].size();i++){
        if (!visited[graph[vertex][i]]){
            if (DFS(graph[vertex][i], graph, visited, vertex)){
                return true;
            }
        }
        else if (parent != graph[vertex][i]){
            return true;
        }
    }
    return false;
}


// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<vector<int>>& graph){
    vector<bool> visited(V);
    for (int i = 0;i < V;i++){
        if (!visited[i]){
            // if (DFS(i, graph, visited, -1)) return true; // for DFS
            if (BFS(i, graph, visited)) return true;        // for BFS
        }
    }
    return false;
}

int main(){
    int V = 4;
    vector<vector<int>> adj_list = { {1},{2,3,0},{3,1},{1,2} };
    if (isCyclic(V, adj_list)){
        cout << "Graph has a cycle!" << endl;
    }
    else{
        cout << "Graph not have a cycle!" << endl;
    }
    return 0;
}