/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-24 19:09 (GMT+5)

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

struct Node {
    int pre,suff,size;
    Node( int val = 0,int size=0 ) : pre(val),suff(val),size(size) {}
    void merge( Node& left , Node& right ) {
        size=left.size+right.size;
        pre=min(right.pre,left.pre+right.size);
        suff=min(left.suff,right.suff+left.size);
    }
} ;

struct Update {
    int val ;
    Update( int val = 0 ) : val(val) {}
    void modify( Node& node ) {
        node.pre = val ;
        node.suff = val ;
    }
} ;

class SegmentTree {
    private:
        int n ;
        vector<Node> segTree ;
        void buildTree( int node , int start , int end , vi& arr ) {
            if( start == end ) {
                segTree[node] = Node( arr[start],1 ) ;
                return ;
            }

            int mid = start + (end - start) / 2 ;
            buildTree( 2 * node + 1 , start , mid , arr ) ;
            buildTree( 2 * node + 2 , mid + 1 , end , arr ) ;
            segTree[ node ].merge( segTree[2 * node + 1] , segTree[2 * node + 2] ) ;
            // cout<<start<<" "<<end<<" pre "<<segTree[node].pre<<" suff "<<segTree[node].suff<<endl;
        }
        
        void updateTree( int i , int l , int r , int& idx , Update& u1 ) {
            if( l == r ) {
                u1.modify( segTree[i] ) ;
                return ;
            }
            
            int mid = l + (r - l) / 2 ;
            if( idx <= mid )
            updateTree( 2*i + 1 , l , mid , idx , u1 ) ;
            else
            updateTree( 2*i + 2 , mid + 1 , r , idx , u1 ) ;
            
            segTree[i].merge( segTree[2 * i + 1] , segTree[2 * i + 2] ) ;
        }
        
        Node query( int i , int l , int r , int start , int end ) {
            if( r < start || l > end )
            // return Node( numeric_limits<int>::lowest() );
            return Node(inf,0) ;
            
            if( start <= l && r <= end )
            return segTree[i] ;
            
            int mid = l + (r - l) / 2 ;
            Node left = query( 2*i + 1 , l , mid , start , end ) ;
            Node right = query( 2*i + 2 , mid + 1 , r , start , end ) ;
            Node res ;
            res.merge( left , right ) ;
            // cout<<start<<" "<<end<<" pre "<<res.pre<<" suff "<<res.suff<<endl;
            return res ;
        }

    public:
        SegmentTree( vi& nums ) : n( nums.size() ) , segTree(4 * n , 0) {
            // segTree.resize( 2 * n - 1 ) ;
            fill( all( segTree ) , Node() ) ;
            buildTree( 0 , 0 , n - 1 , nums ) ;
        }

        void update( int index , int val ) {
            if( index < 0 || index >= n )  return ;
            Update u1( val ) ;
            updateTree( 0 , 0 , n - 1  , index , u1 ) ;
        }
        int query(int idx) {
            // if( start > end )   swap( start, end ) ;
            return min(query( 0 , 0 , n - 1 , 0 , idx ).pre,query( 0 , 0 , n - 1 , idx , n-1 ).suff);
        }
} ;

void solve() {
    int n,q; cin>>n>>q;
    vi arr(n); input(arr,n);
    SegmentTree st(arr);
    while(q--){
        int x; cin>>x; 
        if(x==2){
            int idx; cin>>idx;
            cout<<st.query(idx-1)<<endl;
        }
        else{
            int idx,v; cin>>idx>>v;
            st.update(idx-1,v);
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