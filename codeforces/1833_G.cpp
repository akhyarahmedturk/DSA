/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-06 21:17 (GMT+5)

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

int DFS(int idx, int par, vector<vector<pii>>& graph, vector<int>& res){
    int count = 1, curr = 0;
    forn(i, 0, graph[idx].size()){
        if (graph[idx][i].first != par){
            curr = DFS(graph[idx][i].first, idx, graph, res);
            if (curr == 3) res.pb(graph[idx][i].second);// agar nechy 3 hi bachy to kaat do
            else count += curr; // warna add kar lo uper bhej dena
        }
    }
    return count;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<pii>> graph(n);
    forn(i, 0, n - 1){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back({ v,i + 1 });
        graph[v].push_back({ u,i + 1 });
    }
    if (n == 3){ cout << 0 << endl << " " << endl; return; }
    if (n % 3){ cout << -1 << endl; return; }
    vi res;
    int a = DFS(0, -1, graph, res);
    if (res.size() == n / 3 - 1){// n/3-1 cuts lgany hongy total
        cout << res.size() << endl;
        for (auto it : res)cout << it << " ";
        cout << endl;
    }
    else cout << -1 << endl;

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