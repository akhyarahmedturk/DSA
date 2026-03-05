/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-02-23 11:20 (GMT+5)

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

void dfs1(int idx,int p,vi &depth,vi &cost,vi &sum,vi &arr,vector<vi> &graph){
    sum[idx]=arr[idx-1];
    for(auto it:graph[idx]){
        if(it==p) continue;
        dfs1(it,idx,depth,cost,sum,arr,graph);
        cost[idx]+=cost[it]+sum[it];
        sum[idx]+=sum[it];
        depth[idx]=max(depth[idx],depth[it]+1);
    }
}

void dfs2(int idx,int p,vi &depth,vi &cost,vi &sum,vi &arr,vector<vi> &graph,vi &res){
    vi ya={0,0};
    for(auto it:graph[idx]){
        if(it==p) continue;
        ya.pb(depth[it]);
        sort(allr(ya)); ya.pop_back();
    }
    res[idx]=cost[idx];
    for(auto it:graph[idx]){
        if(it==p) continue;
        dfs2(it,idx,depth,cost,sum,arr,graph,res);
        int curr_sum=sum[it];
        //is subtree to max depth tak ly jao
        if(depth[it]==ya[0]) res[idx]=max(res[idx],cost[idx]+curr_sum*(ya[1]+1));
        else res[idx]=max(res[idx],cost[idx]+curr_sum*(ya[0]+1));
        res[idx]=max(res[idx],cost[idx]+(res[it]-cost[it]));
    }
    if(idx==1){// 1 hi child hy
        if(graph[idx].size()==1) res[idx]=res[graph[idx][0]]+sum[graph[idx][0]];
    }
    else if(graph[idx].size()==2){ // child 1 hi hy magar size=2 because parent ka edge bhi hy
        if(graph[idx][0]==p){
            res[idx]=res[graph[idx][1]]+sum[graph[idx][1]];
        }
        else{
            res[idx]=res[graph[idx][0]]+sum[graph[idx][0]];
        }
    }
    // cout<<" idx "<<idx<<" dept "<<depth[idx]<<" sum "<<sum[idx]<<" cost "<<cost[idx]<<endl;
}

void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n);
    vector<vi> graph(n+1);
    forn(i,0,n-1){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vi depth(n+1,0),cost(n+1,0),sum(n+1,0),res(n+1,0);
    dfs1(1,-1,depth,cost,sum,arr,graph);
    dfs2(1,-1,depth,cost,sum,arr,graph,res);
    forn(i,0,n) cout<<res[i+1]<<" ";
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