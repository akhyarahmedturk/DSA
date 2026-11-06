/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-04 12:39 (GMT+5)

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

void dfs1(int idx,int p,vector<vector<int>> &graph,vi &dp1,vi &arr){
    if(!arr[idx]) arr[idx]=-1;
    dp1[idx]=arr[idx];
    for(auto it:graph[idx]){
        if(it==p) continue;
        dfs1(it,idx,graph,dp1,arr);
        if(dp1[it]>0) dp1[idx]+=dp1[it];
    }
}
void dfs2(int idx,int p,int sum,vector<vi> &graph,vi &dp1,vi &dp2){
    dp2[idx]=dp1[idx]+sum;
    for(auto it:graph[idx]){
        if(it==p) continue;
        sum=dp2[idx];
        if(dp1[it]>0) sum-=dp1[it];
        dfs2(it,idx,max(0LL,sum),graph,dp1,dp2);
    }
}

void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n);
    vector<vi> graph(n);
    forn(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi dp1(n),dp2(n);
    dfs1(0,-1,graph,dp1,arr);
    dfs2(0,-1,0,graph,dp1,dp2);
    for(auto it:dp2) cout<<it<<" ";
    cout<<endl;
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