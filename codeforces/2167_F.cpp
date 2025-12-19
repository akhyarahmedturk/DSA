/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-10-29 16:25 (GMT+5)

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
#define INT_MAX LLONG_MAX

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

int dfs1(int idx,int p,vector<vi> &graph,int &ans,int k){
    int curr=1,n=graph.size();
    for(auto it:graph[idx]){
        if(it!=p) {
            int x=dfs1(it,idx,graph,ans,k);
            //agar root is branch me ho to LCA kia hum curr node ko bna sakty?
            // baqi sab branches ka sum >=k hy to phir hum is branch ky sab ky liy bna sakty
            if(n-x>=k) ans+=x;
            curr+=x;
        }
    }
    // parent wali branch sy bhi chk karo
    if(curr>=k) ans+=(n-curr);
    return curr;
}

void solve() {
    int n,k; cin>>n>>k;
    vector<vi> graph(n);
    forn(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int ans=0;
    int t=dfs1(0,-1,graph,ans,k);
    // jab node khud root ho to hamesha bna sakty
    cout<<ans+n<<endl;
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