/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-05-05 20:24 (GMT+5)

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

void dfs(int idx,int p,int &curr,vector<vi> &graph,vi &rank){
    for(auto it:graph[idx]){
        if(it!=p) dfs(it,idx,curr,graph,rank);
    }
    rank[idx]=curr;
    curr++;
}

// binary lifting  1-base

class BinaryLifting{
    int n, LOG;
    vector<vi> up;
    vector<vi> adj;

public:
    vi depth;// root sy distance kitna hy
    // leaf tak wali height hoti hy !

    BinaryLifting(int size, vector<vi>& graph){
        n = size+1;
        LOG = 32 - __builtin_clz(n); // ceil(log2(n))
        up.assign(n, vi(LOG, -1));
        depth.assign(n, 0);
        adj = graph;
    }

    void preprocess(int root = 1){
        dfs(root, -1);
    }

    // void preprocess(){ for Directed Cyclic graphs ( planet queries)
    //     forn(i,1,n) up[0][i]=adj[i];//child 2^0=1 dis py hoga
    //     forn(i,1,LOG){
    //         forn(j,1,n) up[i][j]=  up[i-1][up[i-1][j]];//2^1 hy to child ka child
    //     }
    // }

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

void solve() {
    int n,q; cin>>n>>q;
    vector<vector<int>> graph(n+1);
    forn(i,0,n-1){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi rank(n+1);
    int curr=1;
    dfs(0,-1,curr,graph,rank);
    vector<vector<pii>> queries;
    forn(i,0,q){
        int size; cin>>size;
        vector<pii> temp(size);
        forn(j,0,size){
            int x; cin>>x; 
            temp[j]={rank[x],x};
        }
        sort(all(temp));
        queries.pb(temp);
    }
    BinaryLifting bl(n,graph);
    bl.preprocess();
    for(auto it:queries){
        int size=it.size();
        if(size==1){ cout<<0<<endl; continue;}
        int d=bl.depth[it[0].ss]+bl.depth[it[1].ss]-bl.depth[bl.LCA(it[0].ss,it[1].ss)]*2;
        int curr=(it[0].ss*it[1].ss)%mod;
        int res=(curr*d)%mod;
        forn(i,2,it.size()){
            int d1=bl.depth[it[i-1].ss]-bl.depth[bl.LCA(it[i].ss,it[i-1].ss)];
            int d2=bl.depth[it[i-1].ss]-bl.depth[bl.LCA(it[i-1].ss,it[i-2].ss)];
            res=(res+mod-min(d1,d2)*curr)%mod;
            cout<<min(d1,d2)<<endl;

            curr=(curr*it[i].ss)%mod;
            d=bl.depth[it[i].ss]+bl.depth[it[i-1].ss]-bl.depth[bl.LCA(it[i].ss,it[i-1].ss)]*2;
            cout<<d<<endl;
            res=(res+curr*d)%mod;
        }
        // d=bl.depth[it[size-1].ss]+bl.depth[it[size-2].ss]-bl.depth[bl.LCA(it[size-1].ss,it[size-2].ss)]*2;
        // res=(res+it[size-1].ss*d)%mod,curr=(it[size-1].ss*it[size-2].ss)%mod;
        // forr(i,size-3,0){
        //     int d1=bl.depth[it[i+1].ss]-bl.depth[bl.LCA(it[i].ss,it[i+1].ss)];
        //     int d2=bl.depth[it[i+1].ss]-bl.depth[bl.LCA(it[i+1].ss,it[i+2].ss)];
        //     res=(res+mod-min(d1,d2)*curr)%mod;
        //     curr=(curr*it[i].ss)%mod;
        //     d=bl.depth[it[i].ss]+bl.depth[it[i+1].ss]-bl.depth[bl.LCA(it[i].ss,it[i+1].ss)]*2;
        //     res=(res+curr*d)%mod;
        // }
        cout<<res<<endl;
    }
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