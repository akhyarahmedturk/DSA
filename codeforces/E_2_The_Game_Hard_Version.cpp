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
    vi dp2;
    vector<set<int>> dp1;
    dp_on_tree(int nn,vector<vi> g,vi &a){
        n=nn;
        graph=g;
        vals=a;
        dp1.resize(n+1);
        dfs1(1,-1);
        dfs2(1,-1,{-2,-1});
    }
    void dfs1(int idx,int p){
        dp1[idx].insert(vals[idx]);
        dp1[idx].insert(-1);
        for(auto it:graph[idx]){
            if(it!=p) {
                dfs1(it,idx);
                for(auto it:dp1[it]) dp1[idx].insert(it);
                while(dp1[idx].size()>2) dp1[idx].erase(dp1[idx].begin());
            }
        }
    }
    void dfs2(int idx,int p,set<int> curr){
        while(curr.size()>2) curr.erase(curr.begin());
        if(vals[idx]<*(--curr.end()) && vals[idx]>=*curr.begin()) dp2.pb(idx);
        curr.insert(vals[idx]);
        map<int,int> mp;
        for(auto it:curr) mp[it]++;
        for(auto it:graph[idx]){
            if(it!=p) {
                for(auto it:dp1[it]){
                    if(it>=*curr.begin()){
                        curr.insert(it); mp[it]++; 
                        while(curr.size()>4) curr.erase(curr.begin());
                    }
                }
            }
        }
        for(auto it:graph[idx]){
            if(it==p) continue;
            vi temp;
            for(auto it:dp1[it]){
                if(mp[it]==1) curr.erase(it) , temp.pb(it);
            }
            dfs2(it,idx,curr);
            for(auto it:temp) curr.insert(it);
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
    cout<<dp.dp2.size()<<" ";
    sort(all(dp.dp2));
    for(auto it:dp.dp2) cout<<it<<" ";
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