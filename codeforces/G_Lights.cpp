/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-02 23:35 (GMT+5)

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

//SCC( kosaraju ) (0-based edge list)

class SCC{
    vector<bool> vis;
    vi order;

    void dfs1(int u){
        vis[u] = true;
        for (int v : g[u])
            if (!vis[v])
                dfs1(v);
        order.push_back(u);
    }

    void dfs2(int u, vi& comp){
        vis[u] = true;
        comp.push_back(u);
        for (int v : rg[u])
            if (!vis[v])
                dfs2(v, comp);
    }

    void find_scc(int n){
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
            if (!vis[u]){
                vector<int> comp;
                dfs2(u, comp);
                for (int v : comp){
                    component_id[v] = id;
                }
                scc.push_back(comp);
                id++;
            }
    }
    void build_condened_graph(vector<pii>& edges){
        int k = scc.size();
        dag.assign(k, {});
        for (auto [u, v] : edges){
            int cu = component_id[u];
            int cv = component_id[v];
            if (cu != cv){
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
        for (auto& e : edges){
            int u = e.first;
            int v = e.second;
            g[u].push_back(v);
            rg[v].push_back(u);
        }
        find_scc(n);
        build_condened_graph(edges);
    }

};

bool dfs(int idx,SCC &scc,vi &indeg,vi &res,string &s){
    indeg[idx]--;
    if(indeg[idx]>0) return true;
    indeg[idx]=-1;
    cout<<idx<<" "<<s<<endl;
    for(auto it:scc.scc[idx]) cout<<it<<" ";
    cout<<endl;
    if(scc.scc[idx].size()==1){
        if(s[scc.scc[idx][0]]=='1'){
            res.pb(scc.scc[idx][0]);
            s[scc.scc[idx][0]]='0';
            s[scc.g[scc.scc[idx][0]][0]]=(s[scc.g[scc.scc[idx][0]][0]]=='1'?'0':'1');
        }
        return dfs(scc.dag[idx][0],scc,indeg,res,s);
    }
    else{
        int start=-1;
        for(auto it:scc.scc[idx]){
            if(s[it]=='0') start=it;
        }
        if(start==-1){
            if(scc.scc.size()&1) return false;
            start=scc.scc[idx][0];
        }
        for(int i=0;i<scc.scc[idx].size();i++){
            if(s[start]=='1') {
                res.pb(start);
                s[start]='0';
                start=scc.g[start][0];
                s[start]=(s[start]=='1'?'0':'1');
            }
            else start=scc.g[start][0]; 
        }
    }
    return true;
}

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    vi arr(n); input(arr,n);
    vector<pii> edges;
    forn(i,0,n) edges.pb({i,arr[i]-1});
    SCC scc(n,edges);
    vi indeg(scc.dag.size(),0LL);
    for(auto it:scc.dag){
        for(auto itt:it) indeg[itt]++;
    }
    vi res;
    for(int i=0;i<scc.dag.size();i++){
        if(indeg[i]==0) {
            if(!dfs(i,scc,indeg,res,s)){ cout<<-1<<endl; return;}
        }
    }
    cout<<s<<endl;
    sort(all(s));
    if(s.back()=='1') { cout<<-1<<endl; return;}
    cout<<res.size()<<endl;
    for(auto it:res) cout<<it+1<<" ";
    cout<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}