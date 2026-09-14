/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-11 10:08 (GMT+5)

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

int dfs1(int idx,vector<vi> &graph,vi &size){
    for(auto it:graph[idx]) size[idx]+=dfs1(it,graph,size);
    return size[idx];
}

int dfs2(int idx,int rem,vector<vi> &graph,vi &size){
    if(graph[idx].size()==0) return 0;
    int t=0,mx=0,mx_idx;
    for(auto it:graph[idx]){
        t+=size[it];
        if(size[it]>mx) mx=size[it] , mx_idx=it;
    }
    size[idx]--;
    int res;
    if(mx==t) {
        res=dfs2(mx_idx,max(rem-1,0LL),graph,size); 
    }
    else if(mx-rem>(t-mx)){
        res=(t-mx)+dfs2(mx_idx,rem-1+(t-mx),graph,size);
    }
    else res=(size[idx]-rem)/2;
    return res;
}

void solve() {
    int n; cin>>n;
    vector<vi> graph(n+1);
    forn(i,0,n-1){
        int x; cin>>x;
        graph[x].pb(i+2);
    }
    vi size(n+1,1);
    int ya=dfs1(1,graph,size);
    cout<<dfs2(1,0,graph,size)<<endl;
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