/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-26 21:21 (GMT+5)

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

void DFS(int idx,int par,vector<vi> &graph,vi &arr,vi &res,pii curr){
    res[idx]=curr.first+arr[idx];
    if(arr[idx]<curr.second) curr.second-=arr[idx];
    else curr.second=0;
    curr.first+=arr[idx];
    forn(i,0,graph[idx].size()){
        if(graph[idx][i]!=par){
            DFS(graph[idx][i],idx,graph,arr,res,{curr.second,curr.first});
        }
    }
}

void solve() {
    int n;
    cin>>n;
    vi arr(n),res(n);
    input(arr,n);
    res=arr;
    vector<vi> graph(n);
    forn(i,0,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    DFS(0,-1,graph,arr,res,{0,0});
    DFS(0,-1,graph,arr,res,{0,0});
    forn(i,0,n){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}