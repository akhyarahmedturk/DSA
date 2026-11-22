/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-07 18:46 (GMT+5)

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



bool dfs(int idx,int p,int start,vector<vi> &graph,vi &vis,vi &curr){
    vis[idx]=1;
    curr.pb(idx);
    for(auto it:graph[idx]){
        if(it==p) continue;
        if(it==start) return true;
        if(vis[it]) continue;
        if(dfs(it,idx,start,graph,vis,curr)) return true;
    }
    curr.pop_back();
    return false;
}

void solve() {
    int n,m; cin>>n>>m;
    vector<vi> graph(n+1);
    forn(i,0,m){
        int a,b; cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    forn(i,1,n+1){
        vi vis(n+1,0);
        for(auto it:graph[i]){
            if(vis[it]) continue;
            vi curr={i};
            if(dfs(it,i,i,graph,vis,curr)){
                set<int> st;
                for(auto it:curr) st.insert(it);
                vi ya;
                for(auto it:graph[i]){
                    if(st.find(it)==st.end()) ya.pb(it);
                }
                if(ya.size()>=2){
                    cout<<"YES"<<endl;
                    cout<<2+curr.size()<<endl;
                    forn(j,0,curr.size()-1) cout<<curr[j]<<" "<<curr[j+1]<<endl;
                    cout<<curr.back()<<" "<<curr[0]<<endl;
                    cout<<ya[0]<<" "<<curr[0]<<endl;
                    cout<<ya[1]<<" "<<curr[0]<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
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