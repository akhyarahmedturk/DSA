/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-01 15:44 (GMT+5)

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
void dfs2(int idx,int p,int curr,vector<vi> &graph,int &ans){
    //parent nikalo
    forn(i,0,graph[idx].size()){
        if(graph[idx][i]==p){
            graph[idx].erase(graph[idx].begin()+i);
            break;
        }
    }
    if(!graph[idx].size()) ans=min(ans,curr);
    else if(graph[idx].size()==1){
        ans=min(ans,curr+1);
    }
    else{
        dfs2(graph[idx][0],idx,curr+2,graph,ans);
        dfs2(graph[idx][1],idx,curr+2,graph,ans);
    }
}

void solve() {
    int n; cin>>n;
    vector<vi> graph(n);
    forn(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi dp(n),par(n);
    int res=inf;
    dfs2(0,-1,1,graph,res);
    cout<<n-res<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}