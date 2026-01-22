/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-27 16:03 (GMT+5)

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

void dfs1(int idx,int p,vector<vector<pii>> &graph,vi &dp,vi &child){
    for(auto it:graph[idx]){
        if(it.f==p) continue;
        dfs1(it.f,idx,graph,dp,child);
        dp[idx]=(dp[idx]+dp[it.f]+it.ss*(child[it.f]+1))%mod;
        child[idx]+=child[it.f]+1;
    }
}

void dfs2(int idx,int p,int curr,vector<vector<pii>> &graph,vi &dp,vi &child,int &ans){
    curr=(curr+dp[idx])%mod;
    ans=(ans+curr)%mod;
    // cout<<idx<<" "<<curr<<" "<<dp[idx]<<endl;
    for(auto it:graph[idx]){
        if(it.f==p) continue;
        int c=child[0]-child[it.f];
        curr=(curr-dp[it.f]-it.ss*(child[it.f]+1) + mod + c*it.ss )%mod;
        dfs2(it.f,idx,curr,graph,dp,child,ans);
        curr=(curr+dp[it.f]+it.ss*(child[it.f]+1) + mod - c*it.ss )%mod;
    }
}

void solve() {
    int n; cin>>n;
    vector<vector<pii>> graph(n);
    forn(i,0,n-1){
        int a,b,c; cin>>a>>b>>c; a--; b--;
        graph[a].pb({b,c});
        graph[b].pb({a,c});
    }
    int ans=0;
    vi dp(n,0),child(n,0);
    dfs1(0,-1,graph,dp,child);
    dfs2(0,-1,0,graph,dp,child,ans);
    cout<<(ans*500000004)%mod<<endl;
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