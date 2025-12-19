/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-15 19:12 (GMT+5)

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
#define mod2 1000000007
#define mod 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

vector<vector<int>> dp;
vi a,b;
int n;

int ss(int idx,int prv){
    prv++;
    if(dp[idx][prv]!=-1) return dp[idx][prv];
    int res=0;
    swap(a[idx],b[idx]);
    int ya=idx;
    forn(i,idx+1,n){
        if(a[i]>=b[ya] && b[i]>=a[ya]) res=(res+ss(i,idx))%mod;
        if(a[i]>=a[ya] && b[i]>=b[ya]) ya++;
        else break;
    }
    if(ya==n-1) res=(res+1)%mod;
    swap(a[idx],b[idx]);
    return dp[idx][prv]=res;
}

void solve() {
    cin>>n;
    a.resize(n);
    b.resize(n);
    dp.assign(n+2,vi(n+2,-1));
    input(a,n); input(b,n);
    int res=ss(0,-1);
    {
        int ya=0;
        forn(i,1,n){
            if(a[i]>=b[ya] && b[i]>=a[ya]) res=(res+ss(i,-1))%mod;
            if(a[i]>=a[ya] && b[i]>=b[ya]) ya++;
            else break;
        }
       if(ya==n-1) res=(res+1)%mod;
    }
    cout<<res<<endl;
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
// 50 50 148 150 150
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// 1 1 1 2 2 2 3 3 3 3 4 4 4  