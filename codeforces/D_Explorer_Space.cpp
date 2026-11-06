/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-18 21:49 (GMT+5)

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
#define vvvi vector<vvi>
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

//1-> L to R
//2-> R to L
//3-> T to B
//4-> B to U

int n,m;

int dfs(int x,int y,int k,vector<vi> &g1,vector<vi> &g2,vvvi &dp){
    if(dp[x][y][k]!=-1) return dp[x][y][k];
    if(k==0) return 0;
    dp[x][y][k]=inf;
    if(y!=0) dp[x][y][k]=min(dp[x][y][k],2*g1[x][y-1]+dfs(x,y-1,k-2,g1,g2,dp));
    if(y!=m-1) dp[x][y][k]=min(dp[x][y][k],2*g1[x][y]+dfs(x,y+1,k-2,g1,g2,dp));
    if(x!=0) dp[x][y][k]=min(dp[x][y][k],2*g2[x-1][y]+dfs(x-1,y,k-2,g1,g2,dp));
    if(x!=n-1) dp[x][y][k]=min(dp[x][y][k],2*g2[x][y]+dfs(x+1,y,k-2,g1,g2,dp));
    return dp[x][y][k];
}

void solve() {
    int k; cin>>n>>m>>k;
    vector<vi> g1(n,vi(m-1)),g2(n-1,vi(m));
    forn(i,0,n) input(g1[i],m-1);
    forn(i,0,n-1) input(g2[i],m);
    vvvi dp(n+1,vvi(m+1,vi(k+1,-1)));
    forn(i,0,n){
        forn(j,0,m) {
            cout<<(k%2==0?dfs(i,j,k,g1,g2,dp):-1)<<" ";
        }
        cout<<endl;
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