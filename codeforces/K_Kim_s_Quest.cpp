/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-12 11:51 (GMT+5)

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

// 1 1 2 1 1 2  odd-> (odd,even...)
// 1 2 1 1 2 odd ->(even ,odd,odd..)
// 2 1 1 even -> (odd,odd)
// 2 2 2 even ->(even,even)

// states
// 0-> even
// 1-> >=2 even
// 2-> odd
// 3-> even + dp[2] | even + dp[5] , even even even even | even even odd odd even ...
// 4-> odd + dp[3] | odd +dp[0] , odd even odd odd even ...
// 5-> odd + dp[2] | odd + dp[4] , odd odd even odd odd ...

void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n);
    vector<vi> dp(n+1,vi(10,0));
    forr(i,n-1,0){
        if(arr[i]%2==0){
            dp[i][0]=1;
            dp[i][1]=(dp[i+1][0]+dp[i+1][1])%mod2;
            dp[i][3]=(dp[i+1][2]+dp[i+1][5])%mod2;
            dp[i][6]=(dp[i+1][1]+dp[i+1][5])%mod2;
            // cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][3];
        }
        else{
            dp[i][2]=1;
            dp[i][4]=(dp[i+1][3]+dp[i+1][0])%mod2;
            dp[i][5]=(dp[i+1][2]+dp[i+1][4])%mod2;
            dp[i][6]=(dp[i+1][4]+dp[i+1][3])%mod2;
            // cout<<dp[i][2]<<" "<<dp[i][4]<<" "<<dp[i][5];
        }
        forn(j,0,7) dp[i][j]=(dp[i][j]+dp[i+1][j])%mod2;
        // cout<<" "<<dp[i][6]<<endl;
    }
    cout<<dp[0][6]<<endl;
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