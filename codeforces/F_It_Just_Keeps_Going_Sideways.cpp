/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-07-05 21:56 (GMT+5)

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
    // to the right
    // for an ith tower of length x, what we want (n-i - number of 1s) +(n-i - number of 2s) ... (n-i - number of 3s)
    // so, all the towers that are <=x will complete fall
    // so, eq will reduce to
    // (n-i)*x - sum(<=x) -x*(number of towers greater)
    BIT bit1(n+10); // for sum 
    BIT bit2(n+10); // for >
    bit1.update(arr.back(),arr.back());
    bit2.update(arr.back(),1);
    int res=0;
    forr(i,n-2,0){
        res+=(arr[i]*(n-i-1) - bit1.query(arr[i]) - arr[i]*(n-i-1 - bit2.query(arr[i])));
        bit1.update(arr[i],arr[i]);
        bit2.update(arr[i],1);
    }
    BIT bit3(n+10);
    int extra=0;
    forn(i,0,n){
        extra=max(extra,i-bit3.query(arr[i]-1));
        bit3.update(arr[i],1);
    }
    cout<<res+extra<<endl;
}

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