/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-07-09 23:17 (GMT+5)

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
// #define int long long
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

int n,m;
string a,b; 
int dp[1002][1002][10];


int dfs(int x,int y,int c){
    if(x==n && y==m) return c==0;
    if(dp[c][y][x]!=-1) return dp[c][y][x];
    if(c==0 && x!=n && y!=m){
        int cc=((a[x]-'0')-(b[y]-'0')+10)%10;
        cc=dfs(x+1,y+1,cc);
        if(cc) dp[c][y][x]=cc+1;
        else  dp[c][y][x]=0;
    }
    else{
        dp[c][y][x]=0;
        int c1=0,c2=0;
        if(x!=n){
            c1=(c+(a[x]-'0')+10)%10;
            c1=dfs(x+1,y,c1);
        }
        if(y!=m){
            c2=(c-(b[y]-'0')+10)%10;
            c2=dfs(x,y+1,c2);
        }
        dp[c][y][x]=max(c1,c2);

    }
    return dp[c][y][x];
}

void solve() {
    cin>>a>>b;
    n=a.length(),m=b.length();
    // vector<vector<vi>> dp(10,vector<vi>(m+2,vi(n+2,-1)));
    memset(dp,-1,sizeof(dp));
    int cc=((a[0]-'0')-(b[0]-'0')+10)%10;
    int res=dfs(1,1,cc);
    cout<<(res?res:-1)<<nl;
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