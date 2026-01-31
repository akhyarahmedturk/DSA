/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-30 16:04 (GMT+5)

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

// bridges in graph

map<int,map<int,int>> res;
vector<set<int>> graph;
int DFS(int idx, vi & vis, vi & count){
    vis[idx] = 1;
    int upper = 0;// upper bhejna hy count
    int nechy = 0;// nechy sy mila
    for (auto it : graph[idx]){
        graph[it].erase(idx);//parent nikalo
        if (vis[it]){ upper++; count[it]++; }// it py subtract hoga
        else{
            int x = DFS(it, vis, count);
            if (!x) {
                res[idx][it]=1;
                res[it][idx]=1;
            }
            nechy += x;//nechy sy mila
        }
    }
    nechy -= count[idx];
    return nechy + upper;
}

void dfs2(int idx,vi &vis,vector<vi> graph,map<int,map<int,int>> &res2){
    vis[idx]=1;
    for(auto it:graph[idx]){
        if(vis[it]) continue;
        res2[idx][it]=1;
        if(res[idx][it]) res2[it][idx]=1; // bridge hy y
        dfs2(it,vis,graph,res2);
    }
}

bool solve(int t) {
    int n,m; cin>>n>>m;
    if(!n) return false;
    graph.resize(n+1);
    res.clear();
    vector<vi> g2(n+1);
    map<int,map<int,int>> edges;
    forn(i,0,m){
        int a,b; cin>>a>>b;
        edges[a][b]++;
        graph[a].insert(b);
        graph[b].insert(a);
        g2[a].pb(b);
        g2[b].pb(a);
    }
    vi vis1(n+1,0),count(n+1,0);
    int ya=DFS(1,vis1,count);
    map<int,map<int,int>> res2;
    vi vis2(n+1,0);
    dfs2(1,vis2,g2,res2);
    for(auto it:edges){
        for(auto itt:it.ss){
            if(res2.find(it.f)==res2.end() || res2.find(itt.f)==res2.end()) res2[it.f][itt.f]=1;
            else if(res2[it.f].find(itt.f)==res2[it.f].end() && res2[itt.f].find(it.f)==res2[itt.f].end()) res2[it.f][itt.f]=1;
        }
    }
    cout<<t<<endl<<endl;
    for(auto it:edges){
        for(auto itt:it.ss){
            if(itt.ss) cout<<it.f<<" "<<itt.f<<endl;
        }
    }
    cout<<"#"<<endl;
    return true;
}


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1; 
    // cin >> t;
    while (solve(t)) { t++; }
    return 0;
}