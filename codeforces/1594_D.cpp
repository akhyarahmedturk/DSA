/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-10 17:03 (GMT+5)

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

bool dfs(int idx,int p,vector<vector<pii>> &graph,vi &vis,int &count,int &c2){
    if(vis[idx]==0) c2++;
    count++;
    for(auto it:graph[idx]){
        if(it.f==p) continue;
        if(vis[it.f]!=-1){
            if(vis[idx]==0 && (vis[it.f]!=it.ss)) return false;  
            if(vis[idx]==1 && (vis[it.f]==it.ss)) return false;  
        }
        else {
            if(vis[idx]==0) vis[it.f]=it.ss;
            else vis[it.f]=(it.ss+1)%2;
            if(!dfs(it.f,idx,graph,vis,count,c2)) return false;
        }
    }
    return true;
}

void solve() {
    int n,m; cin>>n>>m;
    vector<vector<pii>> graph(n);
    forn(i,0,m){
        int a,b; cin>>a>>b; a--; b--;
        string s; cin>>s;
        if(s=="imposter") {
            graph[a].pb({b,1});//1=imposter
            graph[b].pb({a,1});
        }
        else {
            graph[a].pb({b,0});
            graph[b].pb({a,0});
        }
    }
    vi vis(n,-1);
    int res=0;
    forn(i,0,n){
        if(vis[i]==-1){
            int count=0,c2=0;
            vis[i]=0;
            if(!dfs(i,-1,graph,vis,count,c2)){ cout<<-1<<endl; return;}
            res+=max(c2,count-c2);
        }
    }
    cout<<res<<endl;
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