/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-04 17:35 (GMT+5)

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
// #define mp make_pair
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

void DFS(int idx,int par,vector<vector<pii>> &graph,vi &res,int &val){
    forn(i,0,graph[idx].size()){
        if(graph[idx][i].first!=par){
            res[graph[idx][i].second]=val;
            val++;
            DFS(graph[idx][i].first,idx,graph,res,val);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    vector<vector<pii>> graph(n);
    vi res(n-1,-1);
    forn(i,0,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        graph[a].pb({b,i});
        graph[b].pb({a,i});
        res[i]=i;
    }
    int val=3;
    forn(i,0,n){
        if(graph[i].size()>=3){
            res[graph[i][0].second]=0;
            DFS(graph[i][0].first,i,graph,res,val);
            res[graph[i][1].second]=1;
            DFS(graph[i][1].first,i,graph,res,val);
            res[graph[i][2].second]=2;
            DFS(graph[i][2].first,i,graph,res,val);
            forn(j,3,graph[i].size()){
                res[graph[i][j].second]=val;
                val++;
                DFS(graph[i][j].first,i,graph,res,val);
            }
            break;
        }
    }
    forn(i,0,n-1) cout<<res[i]<<endl;
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