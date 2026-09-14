/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-04-16 09:31 (GMT+5)

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

void dfs(int idx,int p,vi &arr,vector<vi> &graph,vector<vector<pii>> &dp,vi &child){
    child[idx]=1;
    vector<pii> ndp(32,{0,0});
    for(auto it:graph[idx]){
        if(it!=p) {
            dfs(it,idx,arr,graph,dp,child);
            child[idx]+=child[it];
            forn(i,0,32) ndp[i].f+=dp[it][i].f , ndp[i].ss+=dp[it][i].ss;
        }
    }
    forn(i,0,32){
        if(arr[idx-1]&(1LL<<i)) dp[idx][i]={ndp[i].f,ndp[i].f+(1LL<<i)*child[idx]};
        else dp[idx][i]={ndp[i].ss+(1LL<<i)*child[idx],ndp[i].ss};
    }
    // cout<<"idx "<<idx<<endl;
    // forn(i,0,32) cout<<"["<<dp[idx][i].f<<","<<dp[idx][i].ss<<"],";
    // cout<<endl;
}

void dfs2(int idx,int p,int child,vi &arr,vector<vi> &graph,vector<pii> &ndp,vector<vector<pii>> &dp){
    child++;
    for(auto it:graph[idx]){
        if(it!=p) {
            dfs(it,idx,arr,graph,dp,child);
            child[idx]+=child[it];
            forn(i,0,32) ndp[i].f+=dp[it][i].f , ndp[i].ss+=dp[it][i].ss;
        }
    }
    forn(i,0,32){
        if(arr[idx-1]&(1LL<<i)) dp[idx][i]={ndp[i].f,ndp[i].f+(1LL<<i)*child[idx]};
        else dp[idx][i]={ndp[i].ss+(1LL<<i)*child[idx],ndp[i].ss};
    }
    // cout<<"idx "<<idx<<endl;
    // forn(i,0,32) cout<<"["<<dp[idx][i].f<<","<<dp[idx][i].ss<<"],";
    // cout<<endl;
}

void solve() {
    int n; cin>>n;
    vi arr(n);  input(arr,n);
    vector<vi> graph(n+1);
    forn(i,0,n-1){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi child1(n+1,0),child2(n+1,0);
    vector<vector<pii>> dp_d(n+1,vector<pii>(32,{0,0})),dp_u;
    dp_u=dp_d; 
    dfs(1,-1,arr,graph,dp_d,child1);
    dfs2(1,-1,arr,graph,ndp_u,child2);
    forn(idx,1,n+1){
        int ya=0;
        forn(i,0,32) ya+=min(dp[idx][i].f,dp[idx][i].ss);
        cout<<ya<<" ";
    }
    cout<<endl;
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