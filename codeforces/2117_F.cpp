/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-08 21:12 (GMT+5)

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

int nn;

int binary_exp(int a, int b, int M){
    int ans = 1;
    while (b){
        if (b & 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

int DFS(int idx,int par,vector<vi> &graph){// path length leny ky liy
    for(auto it:graph[idx]){
        if(it!=par) return 1+DFS(it,idx,graph);
    }
    if(idx==0) return nn+10;// root waly path ko nahi lena to inf assign kar diya
    return 1;
}

void solve() {
    int n;
    cin>>n;
    nn=n;
    vector<vector<int>> graph(n);
    int v=-1;
    forn(i,0,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        graph[a].pb(b);
        graph[b].pb(a);
        if(graph[a].size()>=3){
            if(v==-1) v=a;
            else { v=-5;}// 3 wala sirf 1 hi aa sakta 
        }
        if(graph[b].size()>=3){
            if(v==-1) v=b;
            else { v=-5;}
        }
    }
    // leaf nodes max 2 hony chahy( pehly ko 2 dosry ko 1 dy sakty)
    // root sy max 2 path nikal sakty
    // middle one sy 1 root or max 2 path
    if(v==-5 || (graph[0].size()==2 && v!=-1) || graph[0].size()==3){ cout<<0<<endl; return;}
    else if(v==-1 && graph[0].size()==1) {
        cout<<binary_exp(2,n,mod)<<endl;// agar 1 hi leaf node ho to 2^n 
    }
    else if(graph[0].size()==2){
        vi a(2);
        a[0]=DFS(graph[0][0],0,graph);
        a[1]=DFS(graph[0][1],0,graph);
        sort(all(a));
        // cout<<a[0]<<" vd "<<a[1]<<endl;
        if(a[0]==a[1]){
            cout<<binary_exp(2,n-a[0]*2+1,mod)<<endl; // length brabar ho tu dono path ko excange bhi kar sakty to 2*res
        }
        else{
            // length brabar na ho tu dono path ko excange bhi kar sakty to magar 1 uper waly ko fix karna pary ga 2 py dosyry change me
            cout<<(binary_exp(2,n-a[0]*2,mod)+binary_exp(2,n-a[0]*2-1,mod))%mod<<endl; 
        }
    }
    else{
        vi a(3); 
        a[0]=DFS(graph[v][0],v,graph);
        a[1]=DFS(graph[v][1],v,graph);
        a[2]=DFS(graph[v][2],v,graph);
        sort(all(a));
        if(a[0]==a[1]){
            cout<<binary_exp(2,n-a[0]*2+1,mod)<<endl;
        }
        else{
            cout<<(binary_exp(2,n-a[0]*2,mod)+binary_exp(2,n-a[0]*2-1,mod))%mod<<endl;
        }
    }
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