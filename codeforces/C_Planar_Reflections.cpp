/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-16 20:29 (GMT+5)

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

void solve() {
    int n,k; cin>>n>>k;
    vector<vector<vi>> dp(n+2,vector<vi>(k+1,vi(2,0)));//0=left , 1=Right
    forn(i,0,k+1){
        dp[0][i][1]=1;//left boundary
        dp[n+1][i][0]=1;//right bondary
    }
    forn(i,1,n+1){//base case
        dp[i][1][0]=1;
        dp[i][1][1]=1;
    }
    forn(i,2,k+1){
        //left sy maaro
        forr(j,n,1){
            dp[j][i][0]=(dp[j][i][0]+dp[j+1][i][0]+dp[j-1][i-1][1])%mod;//right py same, left py -1 
        }
        //right sy maaro
        forn(j,1,n+1){
            dp[j][i][1]=(dp[j][i][1]+dp[j-1][i][1]+dp[j+1][i-1][0])%mod;//right py same, left py -1 
        }
    }
    cout<<dp[1][k][0]<<endl;
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