/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-29 17:05 (GMT+5)

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

vector<set<int>> graph;
vector<vi> tree1;
vector<set<int>> extra;
bool res;

void dfs_tree(int idx,vi & vis){
    vis[idx]=1;
    for(auto it:graph[idx]){
        graph[it].erase(idx);
        if(vis[it]) extra[idx].insert(it);
        else{
            tree1[idx].pb(it);
            dfs_tree(it,vis);
        }
    }
}


int check(int idx,int p,vi & vis){
    int c=0;
    for(auto it:tree1[idx]){
        int t=check(it,idx,vis);
        if(!t){
            res=false;
            return 0; 
        }
        c+=t;
    }
    for(auto it:extra[idx]){
        vis[it]++; c++;
    }
    c-=vis[idx];
    return c;
}

void solve() {
    int n,m; cin>>n>>m;
    graph.assign(n,{}); tree1.assign(n,{}); extra.assign(n,{}); res=true;;
    while(m--){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    vi vis(n,0);
    dfs_tree(0,vis);
    vi vvis(n,0);
    int t=check(0,-1,vvis);
    if(!res) cout<<0<<endl;
    else{
        forn(i,0,n){
            for(auto it:tree1[i]) cout<<i+1<<" "<<it+1<<endl;
        }
        forn(i,0,n){
            for(auto it:extra[i]) cout<<i+1<<" "<<it+1<<endl;
        }
    }
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