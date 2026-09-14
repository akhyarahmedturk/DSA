/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-07-05 13:11 (GMT+5)

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

void dfs1(int idx,int p,vector<vi> &graph,vector<vi> &dp,vi &sum){
    sum[idx]=1;
    for(auto it:graph[idx]) {
        if(it!=p) {
            dfs1(it,idx,graph,dp,sum);
            dp[idx].pb(sum[it]);
            sum[idx]+=sum[it];
        }
    }
}

void dfs2(int idx,int p,int up,vector<vi> &graph,vector<vi> &dp,vi &sum){
    dp[idx].pb(up);
    up+=sum[idx];
    for(auto it:graph[idx]) {
        if(it!=p) dfs2(it,idx,up-sum[it],graph,dp,sum);
    }
}

void solve() {
    // jo element khud perfect squere ho uske liy
    // usko 3 dafa lo baqi sab 2 dafa to ans will be arr[i]*(sum*sum) , also perfect square
    // we can, keep it as middle or other 2 saperate sides me se
    // keep it as,middle but 3no value distict sides se
    int n; cin>>n;
    vi arr(n+1);
    forn(i,1,n+1) cin>>arr[i];
    vector<vi> graph(n+1);
    forn(i,0,n-1){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vector<vi> dp(n+1);
    vi sum(n+1,0);
    dfs1(1,0,graph,dp,sum);
    dfs2(1,0,0,graph,dp,sum);
    int res=0;
    forn(i,1,n+1){
        int v=sqrt(arr[i]);
        if(v*v==arr[i]){
            int size=dp[i].size();
            vi prefix(size+2,0),suffix(size+2,0);
            forn(j,0,size) prefix[j+1]=prefix[j]+dp[i][j];
            forr(j,size-1,0) suffix[j]=suffix[j+1]+dp[i][j];
            forn(j,0,size){
                res+= dp[i][j]*(suffix[j+1]); // middle ko fix karo,2nd dp[i][j]th path se and 3rd suffix se bhi 
                // 3rd sirf suffix se because unordered chahy
                res+= dp[i][j]*prefix[j]*suffix[j+1]; // 1st dp[i][j]th path me se, 2nd prefix me se, 3rd suffix me se 
            }
        }
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