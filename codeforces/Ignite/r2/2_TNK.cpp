/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-17 13:21 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

class BinaryLifting {
    int n, LOG;
    vector<vi> up;
    vector<vi> adj;

public:
    vi depth, val, root_to;

    BinaryLifting(int size, vector<vi>& graph, vi& vals) {
        n = size;
        LOG = 32 - __builtin_clz(n); // log2(n)
        up.assign(n, vi(LOG));
        depth.assign(n, 0);
        root_to.assign(n, 0);
        adj = graph;
        val = vals;
    }

    void preprocess(int root = 0) {
        dfs(root, -1); // correct parent for root is -1
    }

    int LCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        for (int j = LOG - 1; j >= 0; j--)
            if (depth[u] - (1 << j) >= depth[v])
                u = up[u][j];

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--)
            if (up[u][j] != up[v][j])
                u = up[u][j], v = up[v][j];

        return up[u][0];
    }

private:
    void dfs(int u, int p) {
        up[u][0] = (p == -1 ? u : p);
        depth[u] = (p == -1 ? 0 : depth[p] + 1);
        root_to[u] = (p == -1 ? val[u] : root_to[p] + val[u]);

        for (int j = 1; j < LOG; j++)
            up[u][j] = up[up[u][j - 1]][j - 1];

        for (int v : adj[u]) {
            if (v != p)
                dfs(v, u);
        }
    }
};


void solve() {
    int n, q;
    cin >> n >> q;
    vi vals(n);
    input(vals, n);
    vector<vi> graph(n);

    forn(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--; // 0-based indexing
        graph[a].pb(b);
        graph[b].pb(a);
    }

    BinaryLifting bl(n, graph, vals);
    bl.preprocess();

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--; // 0-based
        int lca = bl.LCA(a, b);
        int sum = bl.root_to[a] + bl.root_to[b] - 2 * bl.root_to[lca] + bl.val[lca];
        cout << sum << " ";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
