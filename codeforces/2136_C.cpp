/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-28 20:11 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");
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
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

int ss(int idx,vector<pii> &arr,vector<vi> &ya,vi &dp){
    if(dp[idx]!=-1) return dp[idx];
    int v=arr[idx].f,c=arr[idx].ss;
    int a=ss(idx+1,arr,ya,dp),b=0;
    int s=ya[v].size();
    if(v==1) b=1+a;
    else if(s-c+1>=v){
        // cout<<idx<<" "<<ya[v][c+v-2]+1<<endl;
        b=v+ss(ya[v][c+v-2]+1,arr,ya,dp);
    }
    return dp[idx]=max(a,b);
}

void solve() {
    int n; cin>>n;
    vector<pii> arr(n);
    vector<vi> ya(n+1);
    vi dp(n+1,-1);
    dp[n]=0;
    forn(i,0,n){
        cin>>arr[i].f;
        ya[arr[i].f].pb(i);
        arr[i].ss=ya[arr[i].f].size();
    }
    cout<<ss(0,arr,ya,dp)<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}