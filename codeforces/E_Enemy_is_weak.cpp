/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-28 00:04 (GMT+5)

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

// BIT Fenwick Tree

struct BIT{
    int n;
    vi bit;
    BIT(int nn){
        n = nn;
        bit.assign(n + 2, 0);
    }
    // Point update: add 'val' to index 'i'
    void update(int i, int val){ //bit[i]+=x;
        while (i <= n){
            bit[i] += val;
            i += i & -i;
        }
    }
    // Prefix sum: sum[1...i]
    int query(int i){
        int res = 0;
        while (i > 0){
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
};

void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n);
    // quadratic compression
    vi comp;
    forn(i, 0, n){
        comp.pb(arr[i]);
    }
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    forn(i, 0, n){
        arr[i] = upper_bound(all(comp), arr[i]) - comp.begin()+2;  // 1,2,3.....
    }
    BIT bit1(n+10),bit2(n+10);
    int res=0;
    forn(i,0,n){
        res+=(bit2.query(n+5)-bit2.query(arr[i]));
        bit2.update(arr[i],(i-bit1.query(arr[i])));
        bit1.update(arr[i],1);
    }
    cout<<res<<nl;
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