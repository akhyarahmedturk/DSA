/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-21 22:55 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");

*    Those who can't remember the past are condemned to repeat it.
*                                                 -Dynamic Programming.
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
// #define INT_MAX LLONG_MAX

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

class BinaryLifting{
    int n, LOG;
    vector<vi> up;
    vector<vi> adj;

public:
    vi depth;// root sy distance kitna hy
    // leaf tak wali height hoti hy !

    BinaryLifting(int size, vector<vi>& graph){
        n = size;
        LOG = 32 - __builtin_clz(n); // ceil(log2(n))
        up.assign(n, vi(LOG,-1));
        depth.assign(n, 0);
        adj = graph;
    }

    void preprocess(int root){
        dfs(root, -1);
    }

    // kth ancestor of node u
    int lift(int u, int k){
        for (int j = 0; j < LOG; j++){
            if (k & (1 << j)){
                u = up[u][j];
                if (u == -1) break;
            }
        }
        return u;
    }

    int LCA(int u, int v){
        if (depth[u] < depth[v]) swap(u, v);

        // Lift u up to same depth as v
        int diff = depth[u] - depth[v];
        u = lift(u, diff);

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--){
            if (up[u][j] != up[v][j]){
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
    //private
    void dfs(int u, int p){
        up[u][0] = p;
        depth[u] = (p == -1 ? 0 : depth[p] + 1);

        for (int j = 1; j < LOG && up[u][j - 1] != -1; j++)
            up[u][j] = up[up[u][j - 1]][j - 1];

        for (int v : adj[u]){
            if (v != p)
                dfs(v, u);
        }
    }
};


void solve(){
    int n,q,r; cin>>n>>q>>r; r--;
    vector<vi> graph(n);
    forn(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    BinaryLifting bl(n,graph);
    bl.preprocess(r);
    while(q--){
        int u,k; cin>>u>>k; u--;
        int ya=bl.lift(u,k);
        if(ya==-1) cout<<-1<<endl;
        else cout<<ya+1<<endl;
    }
}

int32_t main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
