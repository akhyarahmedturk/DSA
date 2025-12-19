/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-19 09:28 (GMT+5)

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

// Segment tree

class SegmentTree{
private:
    vi tree, arr;
    int n;
    void build(int node, int l, int r){
        if (l == r){
            tree[node] = arr[l];
        }
        else{
            int mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            tree[node] = max(tree[2 * node] , tree[2 * node + 1]); //
        }
    }
    int query(int node, int l, int r, int ql, int qr){
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return max(query(2 * node, l, mid, ql, qr) , query(2 * node + 1, mid + 1, r, ql, qr));//
    }
public:
    SegmentTree(vi arr_1){
        arr = arr_1;
        n = arr.size();
        tree.assign(4 * n, 0);
        build(1, 0, n - 1);
    }
    int rangeMax(int l, int r){
        return query(1, 0, n - 1, l, r);
    }
};

void solve() {
    int n,m; cin>>n>>m;
    vi arr(m); input(arr,m);
    SegmentTree st(arr);
    int q; cin>>q;
    while(q--){
        // go down max -> go left/right -> go up
        int a,b,x,y,k; cin>>a>>b>>x>>y>>k; b--; y--;
        if(b>y) {swap(a,x); swap(b,y);}
        if(arr[b]>=a || arr[y]>=x || (abs(b-y))%k) cout<<"NO"<<endl; 
        else{
            int ma=a+((n-a)/k)*k;//max kitna nechy jaa sakty
            if(abs(ma-x)%k) cout<<"NO"<<endl; 
            else{
                int mx=st.rangeMax(b,y);
                // cout<<" ma "<<ma<<" mx "<<mx<<" ";
                if(mx>=ma) cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
        }
    }
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