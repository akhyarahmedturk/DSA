/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-24 21:21 (GMT+5)

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
    int val;
    Node( int val = 0 ) : val(val) {}
    void merge( Node& left , Node& right ) {
        val=left.val+right.val;
    }
} ;

struct Update {
    int val ;
    Update( int val = 0 ) : val(val) {}
    void modify( Node& node ) {
        node.val=!val;
    }
} ;

class SegmentTree {
    private:
        int n ;
        vector<Node> segTree ;
        void buildTree( int node , int x1 , int x2,int y1,int y2 , vector<vi>& arr ) {
            if( x1==x2 && y1==y2 ) {
                segTree[node] = Node( arr[x1][y1] ) ;
                return ;
            }
            if(x1==x2){
                int mid = y1 + (y2 - y1) / 2 ;
                buildTree( 2 * node + 1 , x1 , x2 , y1 , mid , arr ) ;
                buildTree( 2 * node + 2 , x1 , x2 , mid +1 , y2 , arr ) ;
                segTree[ node ].merge( segTree[2 * node + 1] , segTree[2 * node + 2] ) ;
            }
            else{
                int mid = x1 + (x2 - x1) / 2 ;
                buildTree( 2 * node + 1 , x1 , mid , y1 , y2 , arr ) ;
                buildTree( 2 * node + 2 , mid +1 , x2 , y1 , y2 , arr ) ;
                segTree[ node ].merge( segTree[2 * node + 1] , segTree[2 * node + 2] ) ;
            }
        }

        void updateTree( int i , int x1 , int x2 , int y1, int y2, int& xx ,int& yy , Update& u1 ) {
            if( x1 == x2 && y1==y2 ) {
                u1.modify( segTree[i] ) ;
                return ;
            }

            if(x1==x2){
                int mid = y1 + (y2 - y1) / 2 ;
                if( yy <= mid ) updateTree( 2 * i + 1 , x1 , x2 , y1 , mid , xx , yy  , u1 ) ;
                else updateTree( 2 * i + 2 , x1 , x2 , mid +1 , y2 ,xx , yy , u1 ) ;
                segTree[ i ].merge( segTree[2 * i + 1] , segTree[2 * i + 2] ) ;
            }
            else{
                int mid = x1 + (x2 - x1) / 2 ;
                if( xx <= mid ) updateTree( 2 * i + 1 , x1 , mid , y1 , y2 , xx , yy  , u1 ) ;
                else updateTree( 2 * i + 2 , mid +1, x2 , y1 , y2 , xx , yy , u1 ) ;
                segTree[ i ].merge( segTree[2 * i + 1] , segTree[2 * i + 2] ) ;
            }
        }

        Node query( int i , int x1 , int x2 ,int y1, int y2 , int xx1 , int xx2 , int yy1 ,int yy2 ) {
            if( x2< xx1 || x1>xx2 || y2<yy1 || y1>yy2 )
                // return Node( numeric_limits<int>::lowest() );
                return Node() ;
            
            if( x1>=xx1 && x2<=xx2){
                if(y1>=yy1 && y2<=yy2) return segTree[i] ;
                int mid=y1+(y2-y1)/2;
                Node left=query(2*i+1,x1,x2,y1,mid,xx1,xx2,yy1,yy2);
                Node right=query(2*i+1,x1,x2,mid+1,y2,xx1,xx2,yy1,yy2);
                Node res;
                res.merge( left , right ) ;
                return res ;
            }
            else{
                int mid=x1+(x2-x1)/2;
                Node left=query(2*i+1,x1,mid,y1,y2,xx1,xx2,yy1,yy2);
                Node right=query(2*i+2,mid+1,x2,y1,y2,xx1,xx2,yy1,yy2);
                Node res;
                res.merge( left , right ) ;
                return res ;
            }
        }

    public:
        SegmentTree( vector<vi>& nums ) : n( nums.size() )  {
            segTree.resize( 10 * n * n  ) ;
            fill( all( segTree ) , Node() ) ;
            buildTree( 0 , 0 , n - 1, 0 , n-1 , nums ) ;
        }

        void update( int xx , int yy , int val ) {
            // if( index < 0 || index >= n )  return ;
            Update u1( val ) ;
            updateTree( 0 , 0 , n - 1 , 0 , n-1 , xx , yy , u1 ) ;
        }
        int query( int xx1 ,int xx2 , int yy1 ,int yy2 ) {
            // if( start > end )   swap( start, end ) ;
            return query( 0 , 0 , n - 1 , 0 , n-1 , xx1 , xx2 , yy1 , yy2).val ;
        }
} ;

void solve() {
    int n,q; cin>>n>>q;
    vector<vi> arr(n,vi(n,0));
    forn(i,0,n){
        forn(j,0,n){
            char ch; cin>>ch;
            if(ch=='*') arr[i][j]=1;
        }
    }
    while(q--){
        int t,x1,y1,x2,y2,val; cin>>t;
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