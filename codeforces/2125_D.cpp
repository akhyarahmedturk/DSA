/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-22 21:22 (GMT+5)

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


int power(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % mod2;
        a = (a * a) % mod2;
        b /= 2;
    }
    return ans;
}
 
int inv(int a) {
    return power(a, mod2 - 2) % mod2;
}


void solve() {
    int n,m;
    cin>>m>>n;
    vector<vi> arr(m);
    vi dp(n+1,0);
    dp[0]=1;
    forn(i,0,m){
        int a,b,p,q;
        cin>>a>>b>>p>>q;
        int exclude=(1+mod2-(p*inv(q))%mod2);
        dp[0]=(dp[0]*exclude)%mod2;
        arr[i]={b,a,(p*inv(q-p))%mod2};// b,a
    }
    sort(all(arr));
    forn(i,0,m){
        int end=arr[i][0],st=arr[i][1],diff=arr[i][2];
        dp[end]=(dp[end]+(dp[st-1]*diff)%mod2)%mod2;
    }
    cout<<dp[n]<<endl;
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