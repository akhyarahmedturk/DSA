/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-07-18 16:39 (GMT+5)

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

bool dfs(int idx,int &v,vi &mp,vi &res,vector<vi> &graph,vi &indeg){
    indeg[idx]--;
    if(indeg[idx]>0 ||indeg[idx]<-1) return true;
    if(mp[idx]) res[idx]=v;
    else res[idx]=-1LL*v;
    v++;
    for(auto it:graph[idx]){
        if(!dfs(it,v,mp,res,graph,indeg)) return false;
    }
    return true;
}

void solve() {
    int n,m; cin>>n>>m;
    // from editorial
    // 1 , i , i so, a[i]>=0
    // 2 , i , i so, a[i]<0
    // for others
    // 1 i,j so, the positive one shoud be >= , so edge from neg to pos
    // 2 i,j so,  the negative one should be > in absolute , so edge from pos to neg
    vector<int> mp(n+1,0); // pos/neg
    vector<pii> pos,neg;
    forn(i,0,m){
        int x,u,v; cin>>x>>u>>v;
        if(x==1) {
            if(u==v) mp[u]=1;//pos
            else pos.pb({u,v});
        }
        else if(u!=v) neg.pb({u,v});
    }
    vector<vi> graph(n+1);
    vi indeg(n+1,0);
    for(auto it:neg){
        if(mp[it.f]!=mp[it.ss]){
            if(!mp[it.f]) graph[it.ss].pb(it.f) , indeg[it.f]++;
            else graph[it.f].pb(it.ss) , indeg[it.ss]++;
        }
        else if(mp[it.f]) { cout<<"NO"<<endl; return;} //both +ve edge -ve
    }
    for(auto it:pos){
        if(mp[it.f]!=mp[it.ss]){
            if(mp[it.f]) graph[it.ss].pb(it.f) , indeg[it.f]++;
            else graph[it.f].pb(it.ss) , indeg[it.ss]++;
        }
        else if(!mp[it.f]) { cout<<"NO"<<endl; return;} //both negative edge +ve
    }
    int curr=1;
    vi res(n+1,0);
    forn(i,1,n+1){
        if(indeg[i]!=0) continue;
        if(!dfs(i,curr,mp,res,graph,indeg)){ cout<<"NO"<<endl; return;}
    }
    int cnt=0;
    forn(i,1,n+1) cnt+=(indeg[i]>0);
    if(cnt) { cout<<"NO"<<endl; return;}
    cout<<"YES"<<endl;
    forn(i,1,n+1) cout<<res[i]<<" ";
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