/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-04 16:10 (GMT+5)

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

int dfs(int idx,int k,vector<pii> &arr,vector<vi> &dp) {
    int res = 0,n=arr.size();
    if(idx==n-1) return res;
    if (dp[idx][k] != -1) return dp[idx][k];
    forn(l,idx,n-1) {
        res+=(arr[l+1].f-arr[l].f)*(arr[l].ss);
    }
    if(k==0) return dp[idx][k]=res;
    forn(l,idx+1,n) {
        if(l-(idx+1)>k) break;
        int c1=(arr[l].f-arr[idx].f)*arr[idx].ss;
        int c2=dfs(l,k-(l-idx-1),arr,dp);
        res=min(res,c1+c2);
    }
    return dp[idx][k] = res;
}

void solve() {
    int n,l,k; cin>>n>>l>>k;
    vector<pii> arr(n);
    forn(i,0,n) cin>>arr[i].f; 
    forn(i,0,n) cin>>arr[i].ss;
    arr.pb({l,-1});
    n++;
    vector<vi> dp(n,vi(k+1,-1));
    cout<<dfs(0,k,arr,dp)<<endl; 
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