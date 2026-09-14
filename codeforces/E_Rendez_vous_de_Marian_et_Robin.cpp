/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-13 01:44 (GMT+5)

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

vector<vi> dijkstra(int start,vector<vector<pii>> &graph,int n,vi &mp){
    vector<vi> dp(n+1,vi(2,inf));
    set<array<int,3>> q; // res,horse,idx
    q.insert({0,1,start});
    while(!q.empty()){
        auto[res,horse,idx]=*q.begin(); q.erase(q.begin());
        horse=horse & mp[idx];
        if(dp[idx][horse]<res) continue;
        dp[idx][horse]=res;
        for(auto it:graph[idx]){
            if(!horse){
                if(dp[it.f][horse]>res+it.ss/2) dp[it.f][horse]=res+it.ss/2 , q.insert({res+it.ss/2,horse,it.f});
            }
            else{
                if(dp[it.f][horse]>res+it.ss) dp[it.f][horse]=res+it.ss , q.insert({res+it.ss,horse,it.f});
            }
        }
    }
    return dp;
}

void solve() {
    int n,m,h; cin>>n>>m>>h;
    vector<vector<pii>> graph(n+1);
    vi mp(n+1,1);
    forn(i,0,h) {
        int x; cin>>x;
        mp[x]=0;
    }
    forn(i,0,m){
        int a,b,c; cin>>a>>b>>c;
        graph[a].pb({b,c});
        graph[b].pb({a,c});
    }
    vector<vi> dp1=dijkstra(1,graph,n,mp);
    vector<vi> dp2=dijkstra(n,graph,n,mp);
    int res=inf;
    forn(i,1,n+1){
        dp1[i][0]=min(dp1[i][0],dp1[i][1]);
        dp2[i][0]=min(dp2[i][0],dp2[i][1]);
        res=min(res,max(dp1[i][0],dp2[i][0]));
        // cout<<res<<" ";
    }
    cout<<(res==inf?-1:res)<<nl;
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