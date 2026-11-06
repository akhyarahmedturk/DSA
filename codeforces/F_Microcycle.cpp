/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-25 11:48 (GMT+5)

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

struct BRIDGE{
    int n;
    void apply(set<vi>& edges, int nn){
        n = nn;
        vector<set<pii>> graph(n + 1);
        for (auto it : edges){
            graph[it[1]].insert({ it[2],it[0] });
            graph[it[2]].insert({ it[1],it[0] });
        }
        vi vis(n + 1, 0);
        vi count(n + 1, 0);
        int ya;
        forn(i, 1, n + 1){//graph is not connected!!!!!!!!!
            if (!vis[i]) ya = DFS(i, vis, count, edges, graph);
        }
    }
    int DFS(int idx, vi& vis, vi& count, set<vi>& edges, vector<set<pii>>& graph){
        vis[idx] = 1;
        int upper = 0;// upper bhejna hy count
        int nechy = 0;// nechy sy mila
        for (auto it : graph[idx]){
            graph[it.f].erase({ idx,it.ss });//parent nikalo
            if (vis[it.f]){ upper++; count[it.f]++; }// it py subtract hoga
            else{
                int x = DFS(it.f, vis, count, edges, graph);
                if (!x) edges.erase({ it.ss,min(idx,it.f),max(idx,it.f) });
                nechy += x;//nechy sy mila
            }
        }
        nechy -= count[idx];
        return nechy + upper;
    }
};


bool dfs(int idx, int end, vi& vis, vi& res, vector<vi>& graph){
    vis[idx] = 1;
    if (idx == end){
        res.pb(idx);
        return true;
    }
    bool ya = false;
    for (auto it : graph[idx]){
        if (!vis[it]){
            if (dfs(it, end, vis, res, graph)){ ya = true; break; }
        }
    }
    if (ya) res.pb(idx);
    return ya;
}

void solve(){
    int n, m; cin >> n >> m;
    set<vi> edges;
    vector<vi> graph(n + 1);
    forn(i, 0, m){
        int a, b, c; cin >> a >> b >> c;
        if (a > b) swap(a, b);
        edges.insert({ c,a,b });
        graph[a].pb(b);
        graph[b].pb(a);
    }
    BRIDGE br;
    br.apply(edges, n);// jo bridges nahi -> un me se sab se small edge select karo
    int a = (*edges.begin())[1], b = (*edges.begin())[2], res = (*edges.begin())[0];
    vi ans = { b };
    vi vis(n + 1, 0); vis[b] = 1;
    for (auto it : graph[b]){
        if (it == a) continue;
        if (dfs(it, a, vis, ans, graph)) break;
    }
    cout << res << " " << ans.size() << endl;
    for (auto it : ans) cout << it << " ";
    cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}