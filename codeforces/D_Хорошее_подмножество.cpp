/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-08 13:43 (GMT+5)

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

int dfs(int idx,int val,vi &arr,vector<unordered_map<int,int>> &dp){
    if(idx==arr.size()) return 0;
    if(dp[idx].find(val)!=dp[idx].end()) return dp[idx][val];
    dp[idx][val]=dfs(idx+1,val,arr,dp);
    int g=__gcd(arr[idx],val);
    if(g>1) dp[idx][val]=max(dp[idx][val],1+dfs(idx+1,g,arr,dp));
    return dp[idx][val]; 
}

void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n);
    vector<unordered_map<int,int>> dp(n);
    int res=1;
    forn(i,0,n){
        res=max(res,dfs(i+1,arr[i],arr,dp)+1);
    }
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