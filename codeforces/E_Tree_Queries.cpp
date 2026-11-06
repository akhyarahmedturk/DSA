/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-27 22:07 (GMT+5)

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

void dfs(int idx,int p,vector<vi> &graph,vi &depth){
    for(auto it:graph[idx]){
        if(it==p) continue;
        depth[it]=depth[idx]+1;
        dfs(it,idx,graph,depth);
    }
}

void dfs2(int idx,int p,vector<vi> &graph,map<int,vi> &check,vector<vi> &qq,vi &res,vi &mp){
    for(auto it:graph[idx]){
        if(it!=p) mp[it]=1;
    }
    for(auto it:check[idx]){
        bool check=true;
        for(auto itt:qq[it]) check=(check && mp[itt]);
        res[it]=check;
    }
    for(auto it:graph[idx]){
        if(it!=p) dfs2(it,idx,graph,check,qq,res,mp);
    } 
    for(auto it:graph[idx]){
        if(it!=p) mp[it]=0;
    } 
}

void solve() {
    int n,q; cin>>n>>q;
    vector<vi> graph(n+1);
    forn(i,0,n-1){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi depth(n+1); depth[1]=1;
    dfs(1,-1,graph,depth);
    vector<vi> qq;
    map<int,vi> check;
    forn(i,0,q){
        int k; cin>>k;
        vi ya(k); input(ya,k); qq.pb(ya);
        int ch=ya[0];
        for(auto it:ya) {
            if(depth[it]>depth[ch]) ch=it;
        }
        check[ch].pb(i);
    }
    vi res(q,0),mp(n+1,0); 
    mp[1]=1;
    dfs2(1,-1,graph,check,qq,res,mp);
    for(auto it:res) yesno(it);
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