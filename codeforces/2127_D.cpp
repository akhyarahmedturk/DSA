
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

vector<vi> graph;
vi fact;   

void solve() {
    int n,m; cin>>n>>m;
    graph.assign(n,{});
    forn(i,0,m){
        int u,v; cin>>u>>v; u--; v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    if(m!=n-1){ cout<<0<<endl; return;} // not a tree
    forn(i,0,n){
        if(graph[i].size()==0){cout<<0<<endl; return;}
    }
    int res=1,non_leaf=0;
    forn(i,0,n){
        if(graph[i].size()==1) continue; // a leaf node 
        int leaf=0;
        for(auto it: graph[i]){
            if(graph[it].size()==1) leaf++;
        }
        int other=graph[i].size()-leaf;
        if(other>2) { cout<<"0"<<endl; return;}// the bridges will cross each other
        non_leaf++;
        res=(res*fact[leaf])%mod;
    }
    if(non_leaf<=1) res=(res*2LL)%mod;
    else res=(4LL*res)%mod;
    cout<<res<<endl;
}

int32_t main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t=1;
    cin >> t;
    int n=2e5+10;
    fact.resize(n);
    fact[0]=1; fact[1]=1;
    forn(i,2,n) { fact[i]=(fact[i-1]*i)%mod; }
    while (t--) {
        solve();
    }
    return 0;
}