/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-26 19:12 (GMT+5)

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
    int mx,idx;
    Node( int val = 0,int idx=0 ) : mx(val),idx(idx) {}
    void merge( Node& left , Node& right ) {
        if(right.mx>=left.mx) {
            mx=right.mx; idx=right.idx;
        }
        else{
            mx=left.mx; idx=left.idx;
        }
    }
} ;

class SegmentTree {
    private:
        int n ;
        vector<Node> segTree ;

        void buildTree( int node , int start , int end , vi& arr ) {
            if( start == end ) {
                segTree[node] = Node( arr[start] ,start) ;
                return ;
            }

            int mid = start + (end - start) / 2 ;
            buildTree( 2 * node + 1 , start , mid , arr ) ;
            buildTree( 2 * node + 2 , mid + 1 , end , arr ) ;
            segTree[ node ].merge( segTree[2 * node + 1] , segTree[2 * node + 2] ) ;
        }
        Node query( int i , int l , int r , int start , int end ) {
            if( r < start || l > end )
                // return Node( numeric_limits<int>::lowest() );
                return Node() ;
            
            if( start <= l && r <= end )
                return segTree[i] ;
            
            int mid = l + (r - l) / 2 ;
            Node left = query( 2*i + 1 , l , mid , start , end ) ;
            Node right = query( 2*i + 2 , mid + 1 , r , start , end ) ;
            Node res ;
            res.merge( left , right ) ;
            return res ;
        }

    public:
        SegmentTree( vi& nums ) : n( nums.size() ) , segTree(4 * n , 0) {
            // segTree.resize( 2 * n - 1 ) ;
            fill( all( segTree ) , Node() ) ;
            buildTree( 0 , 0 , n - 1 , nums ) ;
        }

        int query( int start , int end ) {
            // if( start > end )   swap( start, end ) ;
            return query( 0 , 0 , n - 1 , start , end ).idx ;
        }
} ;

void solve() {
    int n,q; cin>>n>>q;
    vi arr(n); input(arr,n);
    SegmentTree st(arr); // is range me max element ki id kya hy
    vi dp(n+1,0); //is me save karo yhan sy end tak kitny dekh sakty
    stack<pii> st2; st2.push({inf,n}); //monotonic stack
    forr(i,n-1,0){
        while(st2.top().f<=arr[i]) st2.pop();
        dp[i]=1+dp[st2.top().ss];
        st2.push({arr[i],i});
    }
    while(q--){
        int a,b; cin>>a>>b; a--; b--;
        int res=dp[a];
        int mx=st.query(a,b);
        res-=(dp[mx]-1); // jo last max hoga usky aagy waly range sy bahar hongy
        // cout<<" mx "<<mx<<res<<endl;
        cout<<res<<endl;
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