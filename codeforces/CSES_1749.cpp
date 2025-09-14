/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-11 12:51 (GMT+5)

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

struct BIT {
    int n;
    vi bit;
    BIT(int nn) {
        n = nn;
        bit.assign(n + 2, 0);
    }
    // Point update: add 'val' to index 'i'
    void update(int i,int val) { //bit[i]+=x;
        while (i <= n) {
            bit[i]+=val;
            i += i & -i;
        }
    }
    // Prefix sum: sum[1...i]
    int query(int i) {
        int res=0;
        while (i > 0) {
            res+=bit[i];
            i -= i & -i;
        }
        return res;
    }
};

void solve() {
    int n,k; cin>>n;
    vi arr(n),ya(n); input(arr,n); input(ya,n);
    BIT bit(n+2);
    forn(i,0,n){
        int x=ya[i]+bit.query(ya[i]+1);
        bit.update(ya[i]+1,1);
        if(i!=0 && ya[i-1]>=ya[i]) { bit.update(ya[i-1],1); bit.update(ya[i-1]+1,-1);}
        cout<<arr[x-1]<<" ";
    }
    cout<<endl; 
}
// 2 6 1 4 2
// 3-> 2 6 4 2 [0,0,1,1,0] 1
// 1-> 6 4 2   [1,2,2,0,0] 2
// 3-> 6 4     [1,2,0,0,0] 2
// 1-> 4       [3,0,0,0,0] 6
// 1->

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}