/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-29 14:05 (GMT+5)

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

void dfs(int idx,vector<vi> &graph,vi &vis,vector<vi> &dp){
    vis[idx]=1;
    for(auto it:graph[idx]){
        if(!vis[idx]) dfs(it,graph,vis);
        forn(i,0,graph.size()) {
            dp[idx][i]=dp[idx][i] | dp[it][i];
            dp[idx][it]=1;
        }
    }
}

void solve() {
    int n,m; cin>>n>>m;
    vector<vi> graph(n),g2(n);
    vector<vi> dp(n,vi(n));
    forn(i,0,m){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].pb(b);
    }
    int c=0;
    vi vis1(n,0),vis2(n,0);
    forn(i,0,n){
        if(!vis1[i]){
            c++;
            dfs(0,graph,vis1,dp);
        }
    }
    if(c>2){ cout<<"NO"<<endl; return;}
    forn(i,0,n){
        if(!vis2[i]){
            dfs(0,graph,vis2,dp);
        }
    }
    if(c==1){
        
    }
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