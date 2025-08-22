/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-09 21:58 (GMT+5)

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

vector<vector<pii>> graph;
vector<pii> edges,res;
vi arr;


bool dfs(int idx,int par){
    bool ya = false;
    for(auto [v, id] : graph[idx]){
        if(v == par) continue;
        if(graph[v].size() == 1){
            if(edges[id].f==v) res[id].f=arr[v];
            else res[id].ss=arr[v];
        }
        else if(ya) return false;
        else {
            ya=true;
            if(edges[id].f==idx) res[id].f=arr[idx];
            else res[id].ss=arr[idx];
            if(!dfs(v, idx)) return false;
        }
    }
    if(!ya){
        int id=graph[idx][0].ss;
        if(edges[id].f==idx) res[id].f=arr[idx];
        else res[id].ss=arr[idx];
    }
    return true;
}

void solve() {
    int n; cin>>n;
    arr.resize(n); input(arr, n);
    res.resize(n-1);
    edges.resize(n-1,{0,0});
    graph.assign(n,{});
    forn(i, 0, n-1) {
        int u, v; cin >> u >> v; u--; v--;
        graph[u].pb({v, i});
        graph[v].pb({u, i});
        edges[i] = {u, v};
    }
    if(n == 1){
        cout << "NO" << endl;
        return;
    }
    forn(i, 0, n) {
        if(graph[i].size() == 1) {
            int id = graph[i][0].ss;
            if(edges[id].f == i) res[id].f = arr[i];
            else res[id].ss = arr[i];
            if(!dfs(i, -1)) { cout << "NO"<<endl; return; };
            break;
        }
    }
    cout << "YES"<<endl;
    forn(i, 0, n-1) {
        cout << res[i].f << " " << res[i].ss << endl;
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