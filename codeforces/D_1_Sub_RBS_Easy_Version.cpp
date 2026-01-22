/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-17 20:13 (GMT+5)

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
// #define mod 1000000007
#define mod 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX
#define nl "\n"

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

// void dfs(int idx,int open,vector<vector<vi>> &dp,string &s){
//     if(dp[idx][open][0]!=-1) return ;
//     dfs(idx+1,open,dp,s);
//     dp[idx][open]=dp[idx+1][open];
//     if(s[idx]=='('){
//         dfs(idx+1,open+1,dp,s);
//         for(int i=2;i<=s.length();i+=2) dp[idx][open][i]+=dp[idx+1][open+1][i];
//     }
//     else{
//         if(open){
//             dfs(idx+1,open-1,dp,s);
//             for(int i=2;i<=s.length()-2;i+=2) {
//                 if(dp[idx+1][open-1][i]>=1) dp[idx][open][i+2]+=dp[idx+1][open-1][i];
//             }
//         }
//     }
// }

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    vector<vi> dp(n+1,vi(n+2,0));
    forr(i,n-2,0){
        dp[i]=dp[i+1];
        if(s[i]=='('){
            forn(j,i+1,n){
                if(s[j]==')'){
                    dp[i][2]++;
                    for(int k=2;k<=n-2;k+=2){
                        dp[i][k+2]+=dp[j+1][k];
                    }
                }
            }
        }
    }
    forn(i,0,n){
        cout<<i<<" i "<<endl;
        for(int j=0;j<=n;j+=2){
            cout<<dp[i][j]<<" ";
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}