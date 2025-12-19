/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-19 15:12 (GMT+5)

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

int dfs1(int idx,int p,vector<vector<int>> &graph,vi &dp){
    for(auto it:graph[idx]) {
        if(it!=p) dp[idx]=max(dp[idx],dfs1(it,idx,graph,dp));
    }
    return dp[idx]+1;
}

void dfs2(int idx,int p,int curr,vector<vector<int>> &graph,vi &dp){
    dp[idx]=max(dp[idx],curr);
    vi ya={curr,0};
    for(auto it:graph[idx]) {
        if(it!=p) {
            ya.pb(dp[it]+1);
            sort(allr(ya));
            ya.pop_back();
        }
    }
    for(auto it:graph[idx]) {
        if(it==p) continue;
        if(ya[0]==dp[it]+1) dfs2(it,idx,ya[1]+1,graph,dp);
        else dfs2(it,idx,ya[0]+1,graph,dp);
        
    }
}

void solve() {
    int n; cin>>n;
    vector<vector<int>> graph(n);
    forn(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].pb(b); graph[b].pb(a);
    }
    vi dp(n,0);
    int t=dfs1(0,-1,graph,dp);
    dfs2(0,-1,0,graph,dp);
    map<int,int> mp;
    for(auto it:dp) mp[it]++;
    int curr=0;
    for(int i=0;i<n;i++){
        curr+=mp[i];
        cout<<min(curr+1,n)<<" ";
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