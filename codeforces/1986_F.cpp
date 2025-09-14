/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-10 17:27 (GMT+5)

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

// bridges in graph

int res;
int n,m; 

vector<set<int>> graph;
pii DFS(int idx,vi &vis,vi &count){
    vis[idx]=1;
    int upper=0;// upper bhejna hy count
    int nechy=0;// nechy sy mila
    int childs=0;
    for(auto it:graph[idx]){
        graph[it].erase(idx);
        if(vis[it]) { upper++; count[it]++;}// it py subtract hoga
        else {
            pii x=DFS(it,vis,count);
            if(x.f==0) {
                int ya=((n-x.ss)*((n-x.ss-1)))/2+((x.ss)*(x.ss-1))/2;
                if(res>ya) res=ya;
            }
            childs+=x.ss;
            nechy+=x.f;//nechy sy mila
        }
    }
    nechy-=count[idx];
    return {nechy+upper,childs+1};
}

void solve() {
    cin>>n>>m;
    graph.assign(n,{});
    forn(i,0,m){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].insert(b); graph[b].insert(a);
    }
    res=(n*(n-1))/2;
    vi vis(n),count(n);
    pii t=DFS(0,vis,count);
    cout<<res<<endl;
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