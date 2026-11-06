/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-26 15:55 (GMT+5)

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

// DP on trees (1 based graph and val)
struct dp_on_tree{
    int n;
    vector<vi> graph;
    vi vals;
    vi dp1,dp2;
    dp_on_tree(int nn,vector<vi> g,vi &a){
        n=nn;
        graph=g;
        vals=a;
        dp1.assign(n+1,0);
        dp2.assign(n+1,0);
        int ya=dfs1(1,-1);
        dfs2(1,-1,0);
    }
    int dfs1(int idx,int p){
        dp1[idx]=vals[idx];
        for(auto it:graph[idx]){
            if(it!=p) dp1[idx]=max(dp1[idx],dfs1(it,idx));
        }
        return dp1[idx];
    }
    void dfs2(int idx,int p,int top){
        dp2[idx]=top;
        vi curr={top,vals[idx]};
        for(auto it:graph[idx]){
            if(it!=p) {
                curr.pb(dp1[it]); sort(allr(curr)); curr.pop_back();
            }
        }
        for(auto it:graph[idx]){
            if(it==p) continue;
            if(curr[0]==dp1[it]) dfs2(it,idx,curr[1]);
            else dfs2(it,idx,curr[0]);
        }
    }
};


void solve() {
    int n; cin>>n;
    vi arr(n+1); 
    forn(i,1,n+1) cin>>arr[i];
    vector<vi> graph(n+1);
    forn(i,0,n-1){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dp_on_tree dp(n,graph,arr);
    vector<pii> ya(n);
    forn(i,1,n+1) ya[i-1]={arr[i],i}; 
    sort(allr(ya));
    forn(i,0,n){
        if(dp.dp2[ya[i].ss]>arr[ya[i].ss]){ cout<<ya[i].ss<<endl; return;}
    }
    cout<<0<<endl;
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