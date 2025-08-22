/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-06 16:50 (GMT+5)

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

bool DFS(int idx,int par,vector<set<int>> &graph,vector<bool> &vis){
    vis[idx]=true;
    bool ch=false;
    for(int it:graph[idx]){
        if(!vis[it]){
            if(DFS(it,idx,graph,vis)) ch=true;
        }
        else if(it!=par) return true;
    }
    return ch;
}

void solve() {
    int n;
    cin>>n;
    vector<set<int>> graph(n);
    forn(i,0,n){
        int a;
        cin>>a;
        a--;
        graph[i].insert(a);
        graph[a].insert(i);
    }
    int mx=0,mm=0,cy=0;
    vector<bool> vis(n,false);
    forn(i,0,n){
        if(!vis[i]){
            mx++;
            if(DFS(i,-1,graph,vis)) cy++;
            else mm++;
        }
    }
    if(cy==mx) cout<<cy<<" "<<mx<<endl;
    else cout<<cy+1<<" "<<mx<<endl;
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