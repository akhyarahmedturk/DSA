#include<bits/stdc++.h>
using namespace std ;
#define nl "\n"
using ll = long long ;

int DFS(int idx,int p,vector<vector<int>> &graph, bool ch){
    int mx=0;
    if(graph[idx].size()==1 && idx!=0) return 0;
    if(ch) mx++;
    for(auto it:graph[idx]){
        if(it!=p) mx+=DFS(it,idx,graph,!ch);
    }
    return mx;
}

void solve() {
    int n, m;
    cin >> n; 
    vector<vector<int>> graph(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);  
    }
    cout<<DFS(0,-1,graph,false)<<endl;
}

int main(){
    solve() ;    
    return 0;
}