#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve(){
    int n, num, bits = 0;
    cin >> n;
    if (n <= 3){ cout << "Day " << n << ": Level = " <<0<<endl; return; }
    num = n;
    while (n){
        bits++;
        n = n >> 1;
    }
    n = num;
    int res = 0LL;
    bits-=2LL;
    if (bits >= 3LL){
        int curr=1LL;
        forn(i,0,3) curr*=bits-i;
        res+=curr/6;
    }
    if (bits >= 6LL){
        int curr=1LL;
        forn(i,0,6) curr*=bits-i;
        res+=curr/720;
    }
    if (bits >= 9LL){
        int curr=1LL;
        forn(i,0,9) curr*=bits-i;
        res+=curr/362880LL;
    }
    int start = pow(2, bits);
    while (start <= n){
        int a = start, bb = 0LL;
        while (a){
            if (a & 1) bb++;
            a = a >> 1;
        }
        if (bb % 3 == 0) res++;
        start++;
    }
    cout << "Day " << n << ": Level = " << res<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t = 3;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}