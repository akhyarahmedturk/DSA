/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-02-08 14:48 (GMT+5)

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
    int n,m; cin>>n>>m;
    vector<vi> arr(n,vi(m));
    forn(i,0,n) input(arr[i],m);
    vector<vi> dp1(n+2,vi(m+2,0));// 1,1 to x,y
    vector<vi> dp2(n+2,vi(m+2,0));// x,y t0 n,m
    
    dp1[1][1]=arr[0][0];
    dp2[n][m]=arr[n-1][m-1];
    forn(i,2,n+1) dp1[i][1]=arr[i-1][0]+dp1[i-1][1];
    forn(i,2,m+1) dp1[1][i]=arr[0][i-1]+dp1[1][i-1];
    forr(i,n-1,1) dp2[i][m]=arr[i-1][m-1]+dp2[i+1][m];
    forr(i,m-1,1) dp2[n][i]=arr[n-1][i-1]+dp2[n][i+1];

    forr(i,n-1,1){
        forr(j,m-1,1) dp2[i][j]=arr[i-1][j-1]+max(dp2[i+1][j],dp2[i][j+1]);
    }
    forn(i,2,n+1){
        forn(j,2,m+1) dp1[i][j]=arr[i-1][j-1]+max(dp1[i-1][j],dp1[i][j-1]);
    }


    vector<vi> prefix_x(n+2,vi(m+2,-1LL*inf));
    vector<vi> prefix_y(n+2,vi(m+2,-1LL*inf));
    
    forn(i,1,n+1){
        forn(j,1,m+1) prefix_x[i][j]=max(dp1[i][j]+dp2[i][j]-arr[i-1][j-1],prefix_x[i][j-1]);
    }

    forn(i,1,m+1){
        forn(j,1,n+1) prefix_y[j][i]=max(dp1[j][i]+dp2[j][i]-arr[j-1][i-1],prefix_y[j-1][i]);
    }
    int res=dp2[1][1];
    int x=1,y=1;
    while(x<=n && y<=m){
        int ya=dp1[x][y]+dp2[x][y]-arr[x-1][y-1] -2*arr[x-1][y-1];
        // cout<<x<<" "<<y<<" "<<prefix_x[x+1][y-1]<<endl;
        if(x-1>=1 && y+1<=m) ya=max(ya,prefix_y[x-1][y+1]);
        if(y-1>=1 && x+1<=n) ya=max(ya,prefix_x[x+1][y-1]);
        res=min(res,ya);
        if(x==n) y++;
        else if(y==m) x++;
        else if(dp2[x+1][y]>=dp2[x][y+1]) x++;
        else y++;
    }
    cout<<res<<endl;
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