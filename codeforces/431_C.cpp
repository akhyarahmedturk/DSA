/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-02 14:10 (GMT+5)

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

int ss(int idx,int val,bool ya,int &k,int &d,vector<vector<vi>> &dp){
    // cout<<idx<<" "<<val<<" "<<ya<<endl;
    if(dp[idx][val][ya]!=-1) return dp[idx][val][ya];
    if(ya){
        dp[idx][val][ya]=(val>=d && val<=k);
        forn(i,1,min(k,val-1)+1) {
            if(i>=d) dp[idx][val][ya]=(dp[idx][val][ya]+ss(idx+1,val-i,true,k,d,dp)+ss(idx+1,val-i,false,k,d,dp))%mod;
            else dp[idx][val][ya]=(dp[idx][val][ya]+ss(idx+1,val-i,true,k,d,dp))%mod;
        }
    }
    else {
        dp[idx][val][ya]=(val<d);
        forn(i,1,min(k,val-1)+1) {
            if(i==d) break;
            dp[idx][val][ya]=(dp[idx][val][ya]+ss(idx+1,val-i,false,k,d,dp))%mod;
        }
    }
    return dp[idx][val][ya];
}

void solve() {
    int n,k,d; cin>>n>>k>>d;
    //max 100 level tak jay ga (saary 1 waly edges lo)
    vector<vector<vi>> dp(102,vector<vi>(102,vi(2,-1)));
    cout<<ss(0,n,true,k,d,dp)<<endl;
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