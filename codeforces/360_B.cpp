/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-02 15:40 (GMT+5)

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

int dfs(int idx,int &mid,vi &arr,vi &dp){
    if(dp[idx]!=-1) return dp[idx];
    else {
        dp[idx]=arr.size()-idx-1;
        for(int i=1;i+idx<arr.size();i++){
            int mx=arr[idx]+i*mid;//inc order me max yha tak jaa sakty
            int mm=arr[idx]-i*mid;// dec me
            if(arr[i+idx]>=mm && arr[idx+i]<=mx) dp[idx]=min(dp[idx],i-1+dfs(idx+i,mid,arr,dp)); 
        }
        return dp[idx];
    }
}


void solve() {
    int n,k; cin>>n>>k;
    vi arr(n); input(arr,n);
    int l=0,r=1e9*2+1,res,mid;
    while(l<=r){
        mid=(l+r)/2;
        vi dp(n+1,-1);
        dp[n]=0LL;
        int mm=inf;
        forn(i,0,n){// shuru ky (i-1) change karo
            mm=min(mm,i+dfs(i,mid,arr,dp)); 
        }
        if(mm<=k) {
            res=mid; r=mid-1;
        }
        else l=mid+1;
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