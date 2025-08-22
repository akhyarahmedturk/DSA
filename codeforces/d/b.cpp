/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-03 21:57 (GMT+5)

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

vector<vi> graph;
vi arr;

int dfs(int idx,int par){
    int res=-1;
    if(arr[idx]==1) return 0;
    for(auto it:graph[idx]){
        if(it!=par) {
            int a=dfs(it,idx);
            if(a!=-1){
                if(res=-1) res=a;
                else res=min(res,a);
            }
        }
    }
    if(res==-1) return res;
    else return res+1;
}

void solve() {
    int n,k;
    cin>>n>>k;
    arr.resize(n,0);
    graph.resize(n);
    forn(i,0,n-1){
        int a,b;
        cin>>a>>b; a--; b--;
        graph[a].pb(b); graph[b].pb(a);
    }
    forn(i,0,k){
        int a; cin>>a; a--; arr[a]=1;
        if(a==n-1){ cout<<"NO"<<endl; return;}
    }
    vi res;
    for(auto it:graph[n-1]){
        int r=dfs(it,n-1);
        if(r!=-1) res.pb(r+1);
    }
    int c=1;
    sort(all(res));
    forn(i,0,n){
        if(res[i]<=i){ cout<<"NO"<<endl; return;}
    }
    cout<<"YES"<<endl;
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