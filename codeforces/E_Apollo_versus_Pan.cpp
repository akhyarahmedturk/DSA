/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-23 09:48 (GMT+5)

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

void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n);
    vi mp(64,0);
    vi vals(64);
    for(auto it:arr){
        forn(i,0,62) {
            if(it&(1LL<<i)) mp[i]++;
        }
    }
    forn(i,0,63) vals[i]=(1LL<<i)%mod;
    int res=0;
    for(auto it:arr){
        int a=0,b=0;
        forn(i,0,62){
            a=(a+vals[i])%mod;
            b=(b+vals[i]*mp[i])%mod;
        }

        forn(i,0,62){
            if(it&(1LL<<i)){
                int c=(a*vals[i])%mod;
                c=(c*n);
                c=(c*mp[i]);
                res=(res+c)%mod;
            }
            else {
                int c=(b*vals[i])%mod;
                c=(c*mp[i]);
                res=(res+c)%mod;
            }
        }
        // forn(i,0,62) {
        //     if(it&(1LL<<i)){
        //         forn(j,0,62) {
        //             if(it&(1LL<<j)) {
        //                 int c=(vals[i]*vals[j])%mod;
        //                 c=(c*n)%mod;
        //                 c=(c*mp[i])%mod;
        //                 res=(res+c)%mod;
        //             }
        //             else{
        //                 int c=(vals[i]*vals[j])%mod;                        
        //                 c=(c*mp[j])%mod;
        //                 c=(c*mp[i])%mod;
        //                 res=(res+c)%mod;
        //             }
        //         }
        //     }
        // }
    }
    cout<<res<<nl;
}

// 1 1 1 -> 1
// 7 1 1 -> 1
// 1 1 7 -> 7
// 7 1 7 -> 7

// 1 7 1 -> 7
// 7 7 1 -> 49 
// 1 7 7 -> 7
// 7 7 7 -> 49

// 8,4

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