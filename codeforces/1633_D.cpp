/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-15 20:24 (GMT+5)

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

int ss(int idx,int k,vector<vi>& dp,vi& a,vi& c) {
    if (idx == a.size()) return 0;
    if (dp[idx][k] != -1) return dp[idx][k];
    int x = ss(idx + 1, k, dp, a, c);
    int y = 0;
    if (k >= a[idx]) y = c[idx] + ss(idx + 1, k - a[idx], dp, a, c);
    return dp[idx][k] = max(x, y);
}

void solve(vi& mp) {
    int n,k; cin>>n>>k;
    vi a(n),c(n);
    int req=0,sum=0;
    forn(i,0,n){
        int x; cin>>x;
        a[i]=mp[x];
        req+=a[i];
    }
    forn(i,0,n){ cin>>c[i]; sum+=c[i]; }
    if(k>=req){ cout<<sum<<endl; return;}
    vector<vi> dp(n,vi(k+1,-1));
    cout<<ss(0,k,dp,a,c)<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1,n=1e3+10;
    cin >> t;
    vi mp(n,inf);
    mp[1]=0;
    for(int i=1;i<mp.size();i++) {
        for(int j=1;j*j<=i;j++) {
            if(i+j<n) mp[i+j]=min(mp[i+j],mp[i]+1);
            if(i+i/j<n) mp[i+i/j]=min(mp[i+i/j],mp[i]+1);
        }
    }
    while (t--) {
        solve(mp);
    }
    return 0;
}
