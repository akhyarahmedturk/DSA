/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-28 18:46 (GMT+5)

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

int dfs1(int idx,int p,vector<vi> &g1,vector<vi> &g2){
    int curr=0;
    for(auto it:g1[idx]){
        if(it!=p) curr+=dfs1(it,idx,g1,g2); 
    }
    for(auto it:g2[idx]){
        if(it!=p) curr+=(dfs1(it,idx,g1,g2)+1); 
    }
    return curr;
}

map<int,vi> res;

void dfs2(int idx,int p,int curr,vector<vi> &g1,vector<vi> &g2){
    res[curr].pb(idx+1);
    for(auto it:g1[idx]){
        if(it!=p) dfs2(it,idx,curr+1,g1,g2); 
    }
    for(auto it:g2[idx]){
        if(it!=p) dfs2(it,idx,curr-1,g1,g2); 
    }
}

void solve() {
    int n; cin>>n;
    vector<vi> g1(n),g2(n);
    forn(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        g1[a].pb(b);
        g2[b].pb(a);
    }
    vi dp(n,0);
    int v=dfs1(0,-1,g1,g2);
    dfs2(0,-1,v,g1,g2);
    cout<<res.begin()->f<<endl;
    vi ya=res.begin()->ss;
    sort(all(ya));
    for(auto it:ya) cout<<it<<" ";
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