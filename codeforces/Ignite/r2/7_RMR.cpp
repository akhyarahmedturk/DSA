/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-17 11:52 (GMT+5)

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
// #define mp make_pair
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

int ss(int i,int j,vector<vi> &arr,vector<vi> &dp){
    if(dp[i][j]!=-1) return dp[i][j];
    int mx=0,n=arr.size(),m=arr[0].size();
    if(i!=0 && arr[i-1][j]>arr[i][j]) mx=max(mx,ss(i-1,j,arr,dp));
    if(j!=0 && arr[i][j-1]>arr[i][j]) mx=max(mx,ss(i,j-1,arr,dp));
    if(i!=n-1 && arr[i+1][j]>arr[i][j]) mx=max(mx,ss(i+1,j,arr,dp));
    if(j!=m-1 && arr[i][j+1]>arr[i][j]) mx=max(mx,ss(i,j+1,arr,dp));
    return dp[i][j]=mx+1;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vi> arr(n,vi(m)),dp(n,vi(m,-1));
    forn(i,0,n) input(arr[i],m);
    int mx=1;
    forn(i,0,n){
        forn(j,0,m){
            if(dp[i][j]==-1){
                int temp=ss(i,j,arr,dp);
            }
            mx=max(mx,dp[i][j]);
        }
    }
    cout<<mx<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}