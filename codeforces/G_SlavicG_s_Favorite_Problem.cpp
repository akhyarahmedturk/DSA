/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-18 21:51 (GMT+5)

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

void dfs1(int idx,int p,int curr,vector<vector<pii>> &graph,set<int> &st){
    for(auto it:graph[idx]){
        if(it.f!=p){
            st.insert(it.ss^curr);
            dfs1(it.f,idx,it.ss^curr,graph,st);
        }
    }
}

bool dfs2(int idx,int p,int b,int curr,vector<vector<pii>> &graph,set<int> &st){
    if(st.find(curr)!=st.end()) return true;
    for(auto it:graph[idx]){
        if(it.f!=p && it.f!=b){
            if(dfs2(it.f,idx,b,it.ss^curr,graph,st)) return true;
        }
    }
    return false;
}

void solve() {
    int n,a,b; cin>>n>>a>>b; a--; b--;
    vector<vector<pii>> graph(n);
    forn(i,0,n-1){
        int a,b,c; cin>>a>>b>>c; a--; b--;
        graph[a].pb({b,c}); 
        graph[b].pb({a,c}); 
    } 
    set<int> st;
    dfs1(b,-1,0,graph,st);
    yesno(dfs2(a,-1,b,0,graph,st));
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