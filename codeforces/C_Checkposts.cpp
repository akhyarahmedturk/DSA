/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-23 19:00 (GMT+5)

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

void dfs1(int idx,vector<vi> &graph,vi &vis,vi &st){
    if(vis[idx]) return;
    vis[idx]=1;
    for(auto it:graph[idx]) dfs1(it,graph,vis,st);
    st.pb(idx);
}

void dfs2(int idx,vector<vi> &graph,vi &vis,int &mm,int &count,vi &arr){
    if(vis[idx]) return;
    vis[idx]=1;
    if(arr[idx]<mm){ mm=arr[idx]; count=1;}
    else if(arr[idx]==mm) count++;
    for(auto it:graph[idx]) dfs2(it,graph,vis,mm,count,arr);
}

void solve() {
    int n; cin>>n; 
    vi arr(n); input(arr,n);
    vector<vi> g1(n),g2(n);
    int m; cin>>m;
    while(m--){
        int a,b; cin>>a>>b; a--; b--;
        g1[a].pb(b);
        g2[b].pb(a);
    }
    vi vis(n,0),st;
    forn(i,0,n) dfs1(i,g1,vis,st); 
    reverse(all(st));
    vi vis2(n,0);
    int sum=0,res=1;
    for(auto it:st){
        if(!vis2[it]){
            int mm=inf,count=1;
            dfs2(it,g2,vis2,mm,count,arr);
            sum+=mm; res=(res*count)%mod; 
            // cout<<it+1<<" "<<mm<<" "<<count<<endl;
        }
    }
    cout<<sum<<" "<<res<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}