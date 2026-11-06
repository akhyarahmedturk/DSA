/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-18 16:12 (GMT+5)

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

int get(int a,int b,int c,int d,int x,int y,vector<string> &s){
    if(a<0 || b<0 || c<0 || d<0 || x<0 || y<0) return -1LL*inf;
    return (s[a][b]=='A') + (s[c][d]=='A') + (s[x][y]=='A')>=2;
}

int dfs(int x,int y,vector<string> &s,vector<vi> &dp){
    if(x==-1 && y==0) return 0;
    if(x<0) return -1LL*inf;
    if(dp[x][y]!=-1) return dp[x][y];
    int a,b;
    if(y==0){
        a=get(0,x,0,x-1,0,x-2,s);
        b=get(1,x,1,x-1,1,x-2,s);
        dp[x][y]=a+b+dfs(x-3,0,s,dp);
        a=get(0,x,1,x,1,x-1,s);
        dp[x][y]=max(dp[x][y],a+dfs(x-1,1,s,dp));
        a=get(1,x,0,x,0,x-1,s);
        dp[x][y]=max(dp[x][y],a+dfs(x-2,3,s,dp));
    }
    else if(y==1){
        a=get(0,x,0,x-1,0,x-2,s);
        dp[x][y]=max(dp[x][y],a+dfs(x-3,4,s,dp));
        a=get(0,x,0,x-1,1,x-1,s);
        dp[x][y]=max(dp[x][y],a+dfs(x-2,0,s,dp));
    }
    else if(y==2){
        a=get(0,x,0,x-1,0,x-2,s);
        dp[x][y]=max(dp[x][y],a+dfs(x-3,3,s,dp));
    }
    else if(y==3){
        a=get(1,x+1,1,x,1,x-1,s);
        dp[x][y]=max(dp[x][y],a+dfs(x,2,s,dp));
        a=get(1,x+1,1,x,0,x,s);
        dp[x][y]=max(dp[x][y],a+dfs(x-1,0,s,dp));
    }
    else if(y==4){
        a=get(1,x+2,1,x+1,1,x,s);
        dp[x][y]=max(dp[x][y],a+dfs(x,1,s,dp));
    }
    return dp[x][y];
}

void solve() {
    int n; cin>>n;
    vector<string> s(2); cin>>s[0]>>s[1];
    vector<vi> dp(n+10,vi(10,-1)); //0->same , 1 is left, 2 is left left, 3 is right , 4 is right right
    cout<<dfs(n-1,0,s,dp)<<endl;
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