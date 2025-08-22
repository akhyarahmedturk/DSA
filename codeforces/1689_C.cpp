/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-30 18:58 (GMT+5)

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

int DFS(int idx, vector<vi>& graph, int par, vi& heights){
    int mx = INT_MAX;
    if (graph[idx].size() == 1) return heights[idx] = 1;
    if (graph[idx].size() == 2) return heights[idx] = 2;
    for (auto it : graph[idx]){
        if (it != par){
            mx = min(mx, DFS(it, graph, idx, heights));
        }
    }
    return heights[idx] = mx + 1;
}

int DFS3(int idx, vector<vi>& graph, int par, vi& childs){
    for (auto it : graph[idx]){
        if (it != par) childs[idx] += DFS(it, graph, idx, childs);
    }
    return childs[idx]+1;
}

void DFS2(int idx, vector<vi>& graph, int par, vi& heights, int& res, vi& childs){//Not solved
    res--;
    if (graph[idx].size() == 1) return;
    if (graph[idx].size() == 2){
        res--;
        return;
    }
    res--;
    if (graph[idx][0] == par){
        if (heights[graph[idx][1]] == heights[graph[idx][2]]){
            if (childs[graph[idx][1]] <= childs[graph[idx][2]]) DFS2(graph[idx][1], graph, idx, heights, res, childs);
            else DFS2(graph[idx][2], graph, idx, heights, res, childs);
        }
        else if (heights[graph[idx][1]] <= heights[graph[idx][2]]) DFS2(graph[idx][1], graph, idx, heights, res, childs);
        else DFS2(graph[idx][2], graph, idx, heights, res, childs);
    }
    else if (graph[idx][1] == par){
        if (heights[graph[idx][0]] == heights[graph[idx][2]]){
            if (childs[graph[idx][0]] <= childs[graph[idx][2]]) DFS2(graph[idx][0], graph, idx, heights, res, childs);
            else DFS2(graph[idx][2], graph, idx, heights, res, childs);
        }
        else if (heights[graph[idx][0]] <= heights[graph[idx][2]]) DFS2(graph[idx][0], graph, idx, heights, res, childs);
        else DFS2(graph[idx][2], graph, idx, heights, res, childs);
    }
    else{
        if (heights[graph[idx][1]] == heights[graph[idx][0]]){
            if (childs[graph[idx][1]] <= childs[graph[idx][0]]) DFS2(graph[idx][1], graph, idx, heights, res, childs);
            else DFS2(graph[idx][0], graph, idx, heights, res, childs);
        }
        else if (heights[graph[idx][0]] <= heights[graph[idx][1]]) DFS2(graph[idx][0], graph, idx, heights, res, childs);
        else DFS2(graph[idx][1], graph, idx, heights, res, childs);
    }
}

void solve(){
    int n;
    cin >> n;
    vi heights(n), childs(n, 0);
    vector<vi> graph(n);
    forn(i, 0, n - 1){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    if (graph[0].size() == 1){ cout << n - 2 << endl; return; }
    int len1 = DFS(graph[0][0], graph, 0, heights);
    int len2 = DFS(graph[0][1], graph, 0, heights);
    int a = DFS3(0, graph, -1, childs);
    int res = n - 2;
    if (heights[graph[0][1]] == heights[graph[0][0]]){
        if (childs[graph[0][0]] <= childs[graph[0][1]]) DFS2(graph[0][0], graph, 0, heights, res, childs);
        else DFS2(graph[0][1], graph, 0, heights, res, childs);
    }
    if (heights[graph[0][0]] <= heights[graph[0][1]]) DFS2(graph[0][0], graph, 0, heights, res, childs);
    else DFS2(graph[0][1], graph, 0, heights, res, childs);
    cout << res << endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}