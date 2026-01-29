/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-27 10:29 (GMT+5)

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
#define vb vector<bool>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX
#define nl "\n"

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

//SCC( kosaraju )

class SCC{
    vector<bool> vis;
    vi order;

    void dfs1(int u) {
        vis[u] = true;
        for (int v : g[u])
            if (!vis[v])
                dfs1(v);
        order.push_back(u);
    }

    void dfs2(int u, vi& comp) {
        vis[u] = true;
        comp.push_back(u);
        for (int v : rg[u])
            if (!vis[v])
                dfs2(v, comp);
    }

    void find_scc(int n) {
        vis.assign(n, false);
        order.clear();
        for (int i = 0; i < n; ++i)
            if (!vis[i])
                dfs1(i);

        vis.assign(n, false);
        reverse(order.begin(), order.end());
        scc.clear();
        component_id.assign(n, -1);
        int id = 0;
        for (int u : order)
            if (!vis[u]) {
                vector<int> comp;
                dfs2(u, comp);
                for (int v : comp) {
                    component_id[v] = id;
                }
                scc.push_back(comp);
                id++;
            }
    }
    void build_condened_graph(vector<pii>& edges){
        int k = scc.size();
        dag.assign(k, {});
        for(auto [u,v]: edges){
            int cu = component_id[u];
            int cv = component_id[v];
            if(cu != cv){
                dag[cu].push_back(cv);
            }
        }
    }
    public:
    vi component_id;
    vector<vi> dag;
    vector<vi> g, rg, scc;
    SCC(int n, vector<pii>& edges){
        g.assign(n, {});
        rg.assign(n, {});
        for(auto& e: edges){
            int u = e.first;
            int v = e.second;
            g[u].push_back(v);
            rg[v].push_back(u);
        }
        find_scc(n);
        build_condened_graph(edges);
    }
};


void dfs(int idx,vi &dp,SCC &scc){
    if(dp[idx]!=-1) return;
    if(scc.dag[idx].size()==0) {
        dp[idx]=scc.scc[idx].size();
        return;
    }
    dfs(scc.dag[idx][0],dp,scc);
    dp[idx]=1+dp[scc.dag[idx][0]];
}


void solve() {
    int n; cin>>n;
    vector<pii> edges(n);
    forn(i,0,n){
        int x; cin>>x; x--;
        edges[i]={i,x};
    }
    SCC scc(n,edges);
    int comps=scc.scc.size();
    vi dp(comps,-1);
    forn(i,0,comps) dfs(i,dp,scc);
    forn(i,0,n){
        cout<<dp[scc.component_id[i]]<<" ";
    }
    cout<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}