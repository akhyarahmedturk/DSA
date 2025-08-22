/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-19 16:39 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");
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
// #define mp make_pair
#define pb push_back
#define f first
#define ss second
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

vector<vi> graph,dp1,dp2;

void dfs1(int idx,int p,int k){
    dp1[idx][0]=1;
    for(auto it:graph[idx]){
        if(it!=p){
            dfs1(it,idx,k);
            forn(i,1,k+1) dp1[idx][i]+=dp1[it][i-1];
        }
    }
}

void dfs2(int idx,int p,int k){
    forn(i,0,k+1) dp2[idx][i]=dp1[idx][i];
    if(p!=-1){
        dp2[idx][1]+=1;
        forn(i,2,k+1){
            dp2[idx][i]+=(dp2[p][i-1]-dp1[idx][i-2]);
        }
    }
    for(auto it:graph[idx]){
        if(it!=p) dfs2(it,idx,k);
    }
}

void solve() {
    int n,k;
    cin>>n>>k;
    graph.resize(n);
    dp1.resize(n,vi(k+1,0));
    dp2.resize(n,vi(k+1,0));
    forn(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs1(0,-1,k); dfs2(0,-1,k);
    int res=0;
    forn(i,0,n) res+=dp2[i][k];
    cout<<res/2<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}