#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

// Step 1: Determine an arbitrary vertex as the starting vertex of the MST.
// Step 2: Follow steps 3 to 5 till there are vertices that are not included in the MST (known as fringe vertex).
// Step 3: Find edges connecting any tree vertex with the fringe vertices.
// Step 4: Find the minimum among these edges.
// Step 5: Add the chosen edge to the MST if it does not form any cycle.
// Step 6: Return the MST and exit
typedef pair<int, int> pp;
typedef pair<int, pair<int, int>> ppp;

vector<ppp> Prims(vector<vector<pp>>& graph, int vertex){
    vector<ppp> MST;
    vector<int> visited(graph.size(), false);
    priority_queue<ppp, vector<ppp>, greater<>> pq;
    pq.push({ 0,{vertex,vertex} });
    while (!pq.empty()){
        int current = pq.top().second.first;
        if (visited[current]){
            pq.pop();
            continue;
        }
        MST.push_back(pq.top());
        pq.pop();
        visited[current] = true;
        for (auto neighbour : graph[current]){
            pq.push({ neighbour.second,{neighbour.first,current} });
        }
    }
    return MST;
}

int main(){
    int N, E, u, v, w;
    int start;
    cin >> N >> start >> E;
    vector<vector<pp>> graph(N);
    for (int i = 0;i < E;i++){
        cin >> u >> v >> w;
        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }
    vector<ppp> MST = Prims(graph, start);
    for (int i = 1;i < MST.size();i++){
        cout << MST[i].second.second << "-" << MST[i].second.first << "  cost: " << MST[i].first << endl;
    }
    return 0;
}