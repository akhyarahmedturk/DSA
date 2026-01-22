#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds ;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Ordered Set (PBDS): Used when need indexing in sets for keys NOT duplicates. To use dups; replace 'T' with pair<T, int> and use counter for 2nd with increasing value.
// os.order_of_key(x) -> # elements strictly < x (like lower_bound index)
// osind_by_order(k) -> iterator to k-th smallest (0-based)
// Think of:
//   order_of_key(x)  -> "index of x" if sorted
//   find_by_order(k) -> "element at index k"
// Use for: rank queries, inversion count, kth smallest/largest, etc.

#define int long long
using pi = pair<int, int> ;
using ppi = pair<int , pi> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vs = vector<string> ;
using vpi = vector<pi> ;
using vvi = vector<vi> ;
template <size_t N>
using ai = array<int, N>;
const int MOD = 1e9 + 7 ;
const int INF = LLONG_MAX ;

#define all(x) begin(x), end(x)
#define nl "\n"
#define f first
#define ss second
void yesNo( bool b ) { cout << ( b ? "YES" : "NO" ) << nl ; }
int binaryExp( int base , int exp , int mod ) { int res = 1LL ; base %= mod ;  while ( exp > 0 ) {  if ( exp & 1 ) res = (res * base) % mod ;  base = (base * base) % mod ;  exp >>= 1LL ;  }  return res ; }
vi sieve( int n ) { vb isPrime( n + 1 , true ) ; isPrime[0] = isPrime[1] = false ;  vi primes ; for( int i = 2 ; i * i <= n ; i++ ) {  if( isPrime[i] ) {  primes.push_back( i ) ;  for( int j = i * i ; j <= n ; j += i )  isPrime[j] = false ;  }  }  return primes ;  }

int x , y , z ;
map<int,int> mp;
void DFS( int i , int j , int k , vector<vs>& grid,int &sum ,int &id,vector<vector<vector<int>>> &comp) {
    if( i < 0 || j < 0 || k < 0 || i >= z || j >= x || k >= y || grid[i][j][k] == '#' )
        return;
    grid[i][j][k] = '#' ;
    sum++;
    DFS( i + 1 , j , k , grid,sum,id,comp ) ;
    DFS( i - 1 , j , k , grid,sum,id,comp ) ;
    DFS( i , j + 1 , k , grid,sum,id,comp ) ;
    DFS( i , j - 1, k , grid,sum,id,comp ) ;
    DFS( i , j , k + 1 , grid,sum,id,comp ) ;
    DFS( i , j , k - 1 , grid ,sum,id,comp) ;
    comp[i][j][k]=id;
}

void solve() {
    cin >> x >> y >> z ;
    mp.clear();
    vector<vs> grid( z , vs( x ) ) ;
    for( int i = 0 ; i < z ; i++ ) {
        for( int j = 0 ; j < x ; j++ )
            cin >> grid[i][j] ;
        // cin.ignore() ;
    }
    vector<vs> temp=grid;
    vector<vector<vector<int>>> comp(z,vector<vector<int>>(x,vi(y)));
    int id=0;
    for(int i=0;i<z;i++){
        for( int j = 0 ; j < x ; j++ ) {
            for( int k = 0 ; k < y ; k++ ) {
                if(grid[i][j][k]=='.'){
                    int sum=0;
                    DFS(i,j,k,temp,sum,id,comp);
                    mp[id]=sum;
                    id++;
                }
            }
        }
    }
    int res=0;
    for( int j = 0 ; j < x ; j++ ) {
        for( int k = 0 ; k < y ; k++ ) {
            int curr=0;
            vector<int> vis(x*y*z,0);
            for(int i=0;i<z;i++){
                if(grid[i][j][k]=='.'){
                    if(vis[comp[i][j][k]]) continue;
                    vis[comp[i][j][k]]=1;
                    curr+=mp[comp[i][j][k]];
                }
            }
            res=max(res,curr);
        }
    }
    cout << res << nl; 
}

signed main() {
    FAST_IO
    if ( FILE* file = fopen("input.txt", "r") ) {
        freopen("input.txt", "r", stdin) ;
        freopen("output.txt", "w", stdout) ;
        fclose(file) ;
    }

    int t = 1 ;
    cin >> t ;
    for( int i = 1 ; i <= t ; i++ ) { 
        // cout << "Case " << i << ": " << nl ; 
        solve() ; 
    } 
    return 0;
}