/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-24 13:52 (GMT+5)

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
// #define mod 1000000007
#define mod 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

int binary_exp(int a, int b, int M){
    int ans = 1;
    while (b){
        if (b & 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

int NCR(int n){
    int fact=1,inv_fact;
    for (int i = 1;i <=n;i++){
        fact = (i * fact) % mod;
        if(i==n/2) inv_fact= binary_exp(fact, mod - 2, mod) % mod;
    }
    return (((fact * inv_fact) % mod) * inv_fact) % mod;
}


void solve() {
    int n;
    cin>>n;
    int res=NCR(n/3);
    forn(i,0,n/3){
        vi arr(3);
        cin>>arr[0]>>arr[1]>>arr[2];
        sort(allr(arr));
        if(arr[0]==arr[2]) res=(res*3LL)%mod;
        else if(arr[1]==arr[2]) res=(res*2LL)%mod;
    }
    cout<<res<<endl;
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