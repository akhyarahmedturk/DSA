#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

void DFS(int vertex, vector<vector<int>>& graph, vector<bool>& visited, stack<int> &st){
    if (visited[vertex]) return;
    visited[vertex] = true;
    for (auto& child : graph[vertex]){
        DFS(child, graph, visited,st);
    }
    st.push(vertex);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++){
            char ch;
            for (int j = 0; j < i; j++) cin >> ch;
            for (int j = i; j < n; j++){
                cin >> ch;
                if (ch == '1'){
                    graph[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n, false);
        stack<int> st;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            DFS(i, graph, visited,st);
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        for(int i = 0; i < n; i++) {
            cout << res[i] +1<< " ";
        }
        cout << endl;
    }
    return 0;
}