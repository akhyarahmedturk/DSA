/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-23 10:15 (GMT+5)

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

struct Node{
    int mml,mmr,mxl,mxr,ans;
    Node(int v,int i){ 
        mml=v-i;  mmr=v+i;
        mxl=v+i;  mxr=v-i;
        ans=0;
    }
    Node(Node &a,Node &b){ 
        ans=max(a.ans,b.ans);
        //a ka right or b ka left merge karo
        ans=max(ans,max(a.mxr-b.mml,b.mxl-a.mmr));
        mml=min(a.mml,b.mml); mmr=min(a.mmr,b.mmr);
        mxl=max(a.mxl,b.mxl); mxr=max(a.mxr,b.mxr);
    }
};

class SegmentTree{
private:
    int n;
    vi arr;
    vector<Node> tree;
    void build(int node, int l, int r){
        if (l == r){
            tree[node]=Node(arr[l],l);
        }
        else{
            int mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            if(tree[2*node].mml==inf) tree[node]=tree[2*node+1];
            else if(tree[2*node+1].mml==inf) tree[node]=tree[2*node];
            else tree[node]=Node(tree[2*node],tree[2*node+1]);
        }
    }
    int query(int node, int l, int r, int ql, int qr){
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node].ans;
        int mid = (l + r) / 2;
        return max(query(2 * node, l, mid, ql, qr) , query(2 * node + 1, mid + 1, r, ql, qr));//
    }
    void update(int node, int l, int r, int idx, int val){
        if (l == r){
            arr[idx] = val;
            tree[node]=Node(arr[l],l);
        }
        else{
            int mid = (l + r) / 2;
            if (idx <= mid) update(2 * node, l, mid, idx, val);
            else update(2 * node + 1, mid + 1, r, idx, val);
            if(tree[2*node].mml==inf) tree[node]=tree[2*node+1];
            else if(tree[2*node+1].mml==inf) tree[node]=tree[2*node];
            else tree[node]=Node(tree[2*node],tree[2*node+1]);
        }
    }
public:
    SegmentTree(vi arr_1){
        arr = arr_1;
        n = arr.size();
        tree.assign(4 * n,Node(inf,0));
        build(1, 0, n - 1);
    }
    int rangeSum(int l, int r) { return query(1, 0, n - 1, l, r); }
    void Update(int idx, int val) { update(1, 0, n - 1, idx, val); }
};


void solve() {
    int n,q; cin>>n>>q;
    vi arr(n); input(arr,n);
    SegmentTree st(arr);
    cout<<st.rangeSum(0,n-1)<<endl;
    while(q--){
        int a,b; cin>>a>>b; a--;
        st.Update(a,b);
        cout<<st.rangeSum(0,n-1)<<endl;
    }
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