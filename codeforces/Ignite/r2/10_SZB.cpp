/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-17 12:32 (GMT+5)

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

struct SegmentTree {
    vi tree, lazy;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.resize(4*n,1);
        lazy.resize(4*n);
    }

    void propagate(int node, int l, int r) {
        if (lazy[node]) {
            tree[node] = (r - l + 1) - tree[node]; // flip
            if (l != r) {
                lazy[node*2] ^= 1;
                lazy[node*2+1] ^= 1;
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr) {
        propagate(node, l, r);
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            lazy[node] ^= 1;
            propagate(node, l, r);
            return;
        }
        int mid = (l + r)/2;
        update(node*2, l, mid, ql, qr);
        update(node*2+1, mid+1, r, ql, qr);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        propagate(node, l, r);
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r)/2;
        return query(node*2, l, mid, ql, qr) + query(node*2+1, mid+1, r, ql, qr);
    }
};



void solve() {
    int n,q;
    cin>>n>>q;
    SegmentTree s(n);
    int sum=0;
    forn(i,0,q){
        int a,b;
        cin>>a>>b;
        a--; b--;
        sum+=s.query(1,0,n-1,a,b);
        s.update(1,0,n-1,a,b);
    }
    cout<<sum/q<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}