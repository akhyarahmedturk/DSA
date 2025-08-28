/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-27 22:06 (GMT+5)

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
#define piii pair<int,pii>
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

vector<vi> graph;
vi ya;

int DFS1(int idx, int p, int dis){
    int val = 0;// no of childs
    for (auto it : graph[idx]){
        if (it != p) val+=DFS1(it, idx, dis + 1);
    }
    // isko select kiya to uper sy dis mily ga
    // per neechy jo saary childs hongy un me sy -1 hoga to
    // total mily ga dist-val
    ya.pb(dis-val);
    return val + 1;
}

void solve(){
    int n, k; cin >> n >> k;
    graph.assign(n, {});
    forn(i, 0, n - 1){
        int u, v; cin >> u >> v; u--; v--;
        graph[u].pb(v); graph[v].pb(u);
    }
    DFS1(0, -1, 0);
    sort(allr(ya));
    int res=0;
    forn(i, 0,k){
        res +=ya[i];
    }
    cout << res << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}