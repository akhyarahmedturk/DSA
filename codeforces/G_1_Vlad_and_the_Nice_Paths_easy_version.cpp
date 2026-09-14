/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-08-27 00:01 (GMT+5)

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

int batch,n;

int dfs(int idx,int curr,int k,vector<vector<vi>> &dp,vi &arr){
    if(curr==0) k--;
    if(dp[idx][curr][k]!=-1) return dp[idx][curr][k];
    if(!curr && !k) return 1;
    if(idx==n-1) return 0;
    dp[idx][curr][k]=0;
    forn(i,idx+1,n){
        if(!curr) dp[idx][curr][k]=(dp[idx][curr][k]+dfs(i,batch-1,k,dp,arr))%mod;
        else if(arr[i]!=arr[idx]) continue;
        else dp[idx][curr][k]=(dp[idx][curr][k]+dfs(i,curr-1,k,dp,arr))%mod;
    }
    return dp[idx][curr][k];
}

void solve() {
    int k; cin>>n>>k;
    batch=k;
    vi arr(n); input(arr,n);
    vi dp1(n+1,0);
    map<int,vi> mp;
    forr(i,n-1,0){
        mp[arr[i]].pb(i);
        if(mp[arr[i]].size()<k) dp1[i]=dp1[i+1];
        else{
            int idx=mp[arr[i]][mp[arr[i]].size()-k]+1;
            // cout<<i<<" "<<idx<<endl;
            dp1[i]=max(dp1[i+1],1+dp1[idx]);
        }
    }
    int mx=dp1[0]; //tL=mx*k
    // cout<<" mx "<<mx<<endl;
    if(!mx) { cout<<1<<endl; return;}
    vector<vector<vi>> dp(n+2,vector<vi>(n+2,vi(n+2,-1)));
    int res=0;
    forn(i,0,n){
        res=(res+dfs(i,batch-1,mx,dp,arr))%mod;
    }
    cout<<res<<endl;
}
// 6, 4

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