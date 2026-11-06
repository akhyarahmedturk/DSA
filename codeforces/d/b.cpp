/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-03-04 15:14 (GMT+5)

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
// idx[0]ind_by_order(n); to get the nth value by order
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

int n,m;
vector<vector<vi>> uper;

int check(vector<vi> &vis){
    int res=0;
    forn(i,0,uper.size()){
        int c=0;
        forn(j,0,n){
            forn(k,0,m){
                if(vis[j][k] && uper[i][j][k]) c++;
            }
        }
        if(c==1) res++;
    }
    return res;
}

void dfs2(int x,int y,vector<vector<int>> &vis){
    if(x<0 || y<0 || x==n || y==m) return;
    vis[x][y]=1;
    if(x==n-1 && y==m-1){
        uper.pb(vis);
    }
    else{
        dfs2(x+1,y,vis);
        dfs2(x,y+1,vis);
    }
    vis[x][y]=0;
}

int dfs(int x,int y,vector<vector<int>> &vis){
    if(x<0 || y<0 || x==n || y==m) return 0;
    int res=0;
    vis[x][y]=1;
    if(x==0 && y==m-1){
        res=check(vis);
    }
    else{
        res=dfs(x-1,y,vis)+dfs(x,y+1,vis);
    }
    vis[x][y]=0;
    return res;
}

void solve(int a,int b) {
    n=a,m=b;
    uper.clear();
    vector<vector<int>> vis(n,vector<int>(m,0));
    dfs2(0,0,vis);
    cout<<n<<", "<<m<<": "<<dfs(n-1,0,vis)<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    // cin >> t;
    forn(i,3,4){
        forn(j,1,30) solve(i,j);
    }
    return 0;
}