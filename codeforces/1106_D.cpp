#include<bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    while(m--){
        int a,b; cin>>a>>b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> vis(n,false);
    vector<int> res;
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(0);
    while(!pq.empty()){
        int v=pq.top();
        pq.pop();
        if(vis[v]) continue;
        vis[v]=true;
        res.push_back(v);
        for(auto it:graph[v]){
            if(!vis[it]) pq.push(it);
        }
    }
    for(int i=0;i<n;i++) cout<<res[i]+1<<" ";
    cout<<endl;
}
// LWLW
int32_t main(){
    int t=1;
    // cin >> t;
    while (t--){
        solve();
    }
} 