/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-11 20:13 (GMT+5)

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

int dfs(int idx,int val,vector<vi> &graph,vi &arr,vector<map<int,int>> &dp){
    if(dp[idx].find(val)!=dp[idx].end()) return dp[idx][val];
    int c=1;
    for(auto it:graph[idx]){
        if(arr[it]==val+arr[idx]){
            c=(c+dfs(it,arr[idx],graph,arr,dp))%mod2;
        }
    }
    return dp[idx][val]=c;
}

void solve() {
    int n,m; cin>>n>>m;
    vi arr(n); input(arr,n);
    vector<vi> graph(n);
    forn(i,0,m){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].pb(b);
    }
    vector<map<int,int>> dp(n);
    int res=0;
    forn(i,0,n){
        for(auto it:graph[i]){
            res=(res+dfs(it,arr[i],graph,arr,dp))%mod2;
        }
    }
    cout<<res<<endl;
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