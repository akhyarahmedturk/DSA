/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-22 15:04 (GMT+5)

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
#define INT_MAX LLONG_MAX
using vvi = vector<vi>;
using vb = vector<bool>;
#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];
#define nl "\n"

int BFS(int s, vvi& adj, vb& vis){
    queue<int> q;
    q.push(s);
    vis[s] = true;
    int far = s;
    while (!q.empty()){
        int sz = q.size();
        while (sz--){
            int u = q.front();
            q.pop();

            far = u;
            for (int& v : adj[u]){
                if (!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return far;
}

pair<bool, int> bipartitie(int s, vvi& adj, vi& colors){
    queue<int> q;
    q.push(s);
    int c = 1;
    colors[s] = c;
    c++ ;
    int mx = 1 ;
    while (!q.empty()){
        int sz = q.size() ;
        while( sz-- ) {
            int u = q.front();
            q.pop();
    
            for( int& v : adj[u] ) {
                if( colors[v] == -1 ) {
                    colors[v] = c ;
                    q.push( v ) ;
                    mx = max( mx , c ) ;
                }
                else if( colors[v] != c && colors[v] != c - 2 ) {
                    // cout << u << " " << v << " " << c << " " << colors[v] << " " << colors[u] << nl ;
                    return { false , -1 } ;
                }
            }
        }
        c++ ;
    }
    return { true , mx } ;
}

void solve(){
    int n, m;
    cin >> n >> m;
    n++ ;
    vector<vi> adj(n);

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        // u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vb vis(n, false);
    vi colors(n, -1);
    int res = 0;
    for (int i = 1; i < n; i++){
        if (!vis[i]){
            int far = BFS(i, adj, vis);
            cout << far << nl;
            pair<bool, int> bb = bipartitie( far , adj , colors ) ;
            if( !bb.f ) {
                cout << -1 << nl ;
                return ;
            } 
            res += bb.ss ;
        }
    }
    cout << res << nl;
    // for( int i = 1 ; i < n ; i++ )
    //     cout << colors[i] << " " ;
    // cout <<nl;
    // cout << *max_element( all( colors ) ) << nl ;
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