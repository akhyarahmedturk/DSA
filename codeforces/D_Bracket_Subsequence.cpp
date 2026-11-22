/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-13 16:57 (GMT+5)

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

bool check(int a,int b,string &s){
    return (s[a]=='(' && s[b]==')') || (s[a]=='[' && s[b]==']');
}

int dfs(int x,int y,vector<vi> &dp,string &s){
    if(x>=y) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    dp[x][y]=max(dfs(x+1,y,dp,s),dfs(x,y-1,dp,s));
    forn(i,x,y+1){
        if(i!=y) dp[x][y]=max(dp[x][y],dfs(x,i,dp,s)+dfs(i+1,y,dp,s));
        if(check(x,i,s)) dp[x][y]=max(dp[x][y],2LL+dfs(x+1,i-1,dp,s)+dfs(i+1,y,dp,s));
        if(check(i,y,s)) dp[x][y]=max(dp[x][y],2LL+dfs(x,i-1,dp,s)+dfs(i+1,y-1,dp,s));
    }
    return dp[x][y];
}

void dfs2(int x,int y,vector<vi> &dp,string &s,string &res){
    if(x>=y) return;
    if(dfs(x+1,y,dp,s)==dp[x][y]) {
        dfs2(x+1,y,dp,s,res);
        return;
    }
    if(dfs(x,y-1,dp,s)==dp[x][y]) {
        dfs2(x,y-1,dp,s,res);
        return;
    }
    forn(i,x,y){
        if(i!=y) {
            if(dp[x][y]==dfs(x,i,dp,s)+dfs(i+1,y,dp,s)){
                dfs2(x,i,dp,s,res);
                dfs2(i+1,y,dp,s,res);
                return;
            }
        }
        if(check(x,i,s)){
            if(dp[x][y]==2LL+dfs(x+1,i-1,dp,s)+dfs(i+1,y,dp,s)){
                res.pb(s[x]);
                dfs2(x+1,i-1,dp,s,res);
                res.pb(s[i]);
                dfs2(i+1,y,dp,s,res);
                return;
            }
        }
        if(dp[x][y]==2LL+dfs(x,i-1,dp,s)+dfs(i+1,y-1,dp,s)){
            dfs2(x,i-1,dp,s,res);
            res.pb(s[i]);
            dfs2(i+1,y-1,dp,s,res);
            res.pb(s[y]);
            return;
        }
    }
}

void solve() {
    string s; cin>>s;
    int n=s.length();
    vector<vi> dp(n,vi(n,-1));
    cout<<dfs(0,n-1,dp,s)<<endl;
    if(!dp[0][n-1]) return;
    string res="";
    dfs2(0,n-1,dp,s,res);
    cout<<res<<endl;
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