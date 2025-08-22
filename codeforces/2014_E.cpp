/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-23 17:48 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
// idx.find_by_order(n); to get the nth value by order
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
// #define mp make_pair
#define pb push_back
#define f first
#define ss second
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

vector<int> dijkstra(int src,vector<vector<pii>> &graph,vector<bool> &horse){
    int n=graph.size();
    vector<int> dist(n,LONG_LONG_MAX);
    dist[src]=0;
    vector<bool> vis(n,false);
    priority_queue<vi,vector<vi>,greater<vi>> pq;
    if(horse[src]) pq.push({1,0,src});// horse,dist,node
    else pq.push({0,0,src}); 
    while(!pq.empty()){
        vi curr=pq.top();
        pq.pop();
        if(!curr[0]){
            if(dist[curr[2]]<curr[1]) continue;
        }
        else{
            if(vis[curr[2]] && dist[curr[2]]<curr[1]) continue;
        }
        int h=curr[0];
        if(horse[curr[2]]) h=1;
        for(auto v:graph[curr[2]]){
            if(h){
                pq.push({1,curr[1]+v.second/2,v.first});
                dist[v.first]=min(dist[v.first],curr[1]+v.second/2);
            }
            else if(dist[v.first],curr[1]+v.second/2)
        }
    }
}

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<bool> horse(n,false);
    while(k--){
        int a;
        cin>>a;
        a--;
        horse[a]=true;
    }
    vector<vector<pii>> graph(n);
    forn(i,0,m){
        int a,b,d;
        cin>>a>>b>>d;
        a--;
        b--;
        graph[a].pb({b,d});
        graph[b].pb({a,d});
    }
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}