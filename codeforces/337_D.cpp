/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-04 07:10 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");

*    Those who can’t remember the past are condemned to repeat it.
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
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

int dfs1(int idx,int p,vector<vector<pii>> &graph,vi &arr){
    int res=0;
    // dp me 2 max dis store karo
    for(auto &it:graph[idx]){
        if(it.f!=p){
            it.ss=dfs1(it.f,idx,graph,arr);
            res=max(it.ss,res);
        }
    }
    if(res) res++;
    if(arr[idx]) return max(res,1LL);
    return res;
}

void dfs2(int idx,int p,int curr,vector<vector<pii>> &graph,vi &arr,vi &dp){
    dp[idx]=curr;
    vi ya={0,0};
    for(auto it:graph[idx]){
        ya.pb(it.ss);
        sort(allr(ya));
        ya.pop_back();
    }
    dp[idx]=max(dp[idx],ya[0]);
    for(auto it:graph[idx]){
        if(it.f!=p){
            int s=0;
            if(ya[0]==it.ss) s=(ya[1]==0)?0:ya[1]+1;
            else s=(ya[0]==0)?0:ya[0]+1;
            if(arr[idx]) s=max(s,1LL);
            if(curr) s=max(s,curr+1);
            dfs2(it.f,idx,s,graph,arr,dp);
        }
    }
}

void solve() {
    int n,m,d; cin>>n>>m>>d;
    vi arr(n,0);
    forn(i,0,m){ int x; cin>>x; x--; arr[x]=1;}
    vector<vector<pii>> graph(n);
    forn(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].pb({b,0});// is edge sy kitna distance mila
        graph[b].pb({a,0});
    }
    int t=dfs1(0,-1,graph,arr);
    vi dp(n,0);
    dfs2(0,-1,0,graph,arr,dp);
    int res=0;
    forn(i,0,n) {res+=(dp[i]<=d);}
    cout<<res<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}