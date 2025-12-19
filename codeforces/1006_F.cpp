/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-26 07:39 (GMT+5)

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



void ss1(int x,int y,int val,int curr,vector<vi> &arr,vector<vector<map<int,int>>> &dp){
    val^=arr[x][y];
    int n=arr.size(),m=arr[0].size();
    int mid=(n+m+1)/2;
    if(curr==mid) {dp[x][y][val]++; return;}
    if(x<n-1) ss1(x+1,y,val,curr+1,arr,dp);
    if(y<m-1) ss1(x,y+1,val,curr+1,arr,dp);
}

void ss2(int x,int y,int val,int curr,vector<vi> &arr,vector<vector<map<int,int>>> &dp,int &k,int &res){
    int n=arr.size(),m=arr[0].size();
    int mid=(n+m)/2;
    if(curr==mid) {
        // cout<<x<<" "<<y<<endl;
        int req=val^k;
        res+=dp[x][y][req];
        return;
    }
    val^=arr[x][y];
    if(x>0) ss2(x-1,y,val,curr+1,arr,dp,k,res);
    if(y>0) ss2(x,y-1,val,curr+1,arr,dp,k,res);
}


void solve() {
    //meet in middle
    int n,m,k; cin>>n>>m>>k;
    vector<vi> arr(n,vi(m));
    forn(i,0,n) input(arr[i],m);
    vector<vector<map<int,int>>> dp(n,vector<map<int,int>>(m));
    ss1(0,0,0,1,arr,dp);
    int res=0;
    ss2(n-1,m-1,0,1,arr,dp,k,res);
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