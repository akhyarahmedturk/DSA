/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-08 14:42 (GMT+5)

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

int dfs(int idx,int p,int idx_val,int p_val,string &s,vector<vi> &graph,vector<vector<vi>> &dp){
    if(dp[idx][p_val][idx_val]!=-1) return dp[idx][p_val][idx_val];
    dp[idx][p_val][idx_val]=0;
    if(idx_val!=p_val) dp[idx][p_val][idx_val]++;
    if((s[idx-1]-'0')!=idx_val) dp[idx][p_val][idx_val]++;
    for(auto it:graph[idx]){
        if(it==p) continue;
        dp[idx][p_val][idx_val]+=min(dfs(it,idx,0,idx_val,s,graph,dp),dfs(it,idx,1,idx_val,s,graph,dp));
        // if(idx==3 && !idx_val && !p_val) cout<<dp[3][0][0]<<" "<<it<<endl;
    }
    return dp[idx][p_val][idx_val];
}

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    vector<vi> graph(n+1);
    forn(i,0,n-1){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vector<vector<vi>> dp(n+1,vector<vi>(2,vi(2,-1)));
    int res=min(dfs(1,-1,1,0,s,graph,dp),dfs(1,-1,0,1,s,graph,dp));
    cout<<res<<endl;
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