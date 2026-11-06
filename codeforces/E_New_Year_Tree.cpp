/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-06 15:27 (GMT+5)

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

//Segment Tree

struct Node{
    int val;
    Node(int val = 0) : val(val){ }
    void merge(Node& left, Node& right){
        val = left.val | right.val;
    }
};

struct Update{
    int val;
    Update(int val = 0) : val(val){ }
    void apply(Node& node, int l, int r){
        node.val = (1LL<<val); // Currently lazyUpdate is via updating val NOT replacing.
    }
    void propagate(Update& newU){
        val = newU.val;
    }
    void modify(Node& node){
        node.val = (1LL<<val);
    }
};

class SegmentTree{
private:
    int n;
    vector<Node> segTree;
    vector<Update> lazyTree;

    void buildTree(int node, int start, int end, vi& arr){
        if (start == end){
            segTree[node] = Node(arr[start]);
            return;
        }

        int mid = start + (end - start) / 2;
        buildTree(2 * node + 1, start, mid, arr);
        buildTree(2 * node + 2, mid + 1, end, arr);
        segTree[node].merge(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

    void updateTree(int i, int l, int r, int& idx, Update& u1){
        pushdown(i, l, r);
        if (l == r){
            u1.modify(segTree[i]);
            return;
        }

        int mid = l + (r - l) / 2;
        if (idx <= mid)
            updateTree(2 * i + 1, l, mid, idx, u1);
        else
            updateTree(2 * i + 2, mid + 1, r, idx, u1);

        segTree[i].merge(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    void pushdown(int i, int l, int r){
        if (lazyTree[i].val){
            lazyTree[i].apply(segTree[i], l, r);
            if (l != r){
                lazyTree[2 * i + 1].propagate(lazyTree[i]);
                lazyTree[2 * i + 2].propagate(lazyTree[i]);
            }
            lazyTree[i] = Update();
        }
    }

    void lazyUpdateRange(int i, int l, int r, int start, int end, Update& u1){
        pushdown(i, l, r);                 // moved up
        if (r < start || l > end) return;
        if (start <= l && r <= end){
            u1.apply(segTree[i], l, r);
            if (l != r){
                lazyTree[2*i+1].propagate(u1);
                lazyTree[2*i+2].propagate(u1);
            }
            return;
        }
        int mid = l + (r - l) / 2;
        lazyUpdateRange(2*i+1, l, mid, start, end, u1);
        lazyUpdateRange(2*i+2, mid+1, r, start, end, u1);
        segTree[i].merge(segTree[2*i+1], segTree[2*i+2]);
    }

    Node query(int i, int l, int r, int start, int end){
        pushdown(i, l, r);                 // moved up
        if (r < start || l > end) return Node();
        if (start <= l && r <= end) return segTree[i];
        int mid = l + (r - l) / 2;
        Node left = query(2*i+1, l, mid, start, end);
        Node right = query(2*i+2, mid+1, r, start, end);
        Node res; res.merge(left, right);
        return res;
    }

public:
    SegmentTree(vi& nums) : n(nums.size()), segTree(4 * n, 0), lazyTree(4 * n, 0){
        // segTree.resize( 2 * n - 1 ) ;
        fill(all(segTree), Node());
        fill(all(lazyTree), Update());
        buildTree(0, 0, n - 1, nums);
    }

    void update(int index, int val){
        if (index < 0 || index >= n)  return;
        Update u1(val);
        updateTree(0, 0, n - 1, index, u1);
    }

    void lazyUpdateRange(int start, int end, int val){
        Update u1(val);
        lazyUpdateRange(0, 0, n - 1, start, end, u1);
    }

    int query(int start, int end){
        // if( start > end )   swap( start, end ) ;
        int v=query(0, 0, n - 1, start, end).val;
        v=__builtin_popcountll(v);
        return v;
    }
};

void euler(int idx,int p,vector<vi> &graph,vector<pii> &ya,vi &order){
    ya[idx].f=order.size();
    order.pb(idx);
    for(auto it:graph[idx]){
        if(it==p) continue;
        euler(it,idx,graph,ya,order);
    }
    ya[idx].ss=order.size()-1;
}

void solve() {
    int n,q; cin>>n>>q;
    vi arr(n+1);
    forn(i,1,n+1) cin>>arr[i];
    vector<vi> graph(n+1);
    forn(i,0,n-1){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi order={0};//dummy
    vector<pii> ya(n+1);//in , out
    euler(1,-1,graph,ya,order);
    vi arr2(n+1,0);
    forn(i,1,n+1) arr2[i]=(1LL<<arr[order[i]]);
    SegmentTree st(arr2);
    // for(auto it:order) cout<<it<<" ";
    // cout<<endl;
    while(q--){
        int kk; cin>>kk;
        if(kk==1){
            int x,k; cin>>x>>k;
            st.lazyUpdateRange(ya[x].f,ya[x].ss,k);
        }
        else{
            int x; cin>>x;
            cout<<st.query(ya[x].f,ya[x].ss)<<endl;
        }
        // for(auto it:order) cout<<ya[it].f<<" "<<ya[it].ss<<" "<<st.query(ya[it].f,ya[it].ss)<<"  | ";
        // cout<<endl;
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