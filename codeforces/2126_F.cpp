/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-17 21:06 (GMT+5)

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

int DFS(int idx,int p,vector<vector<pii>> &graph,vi &arr,vector<map<int,int>> &mp,vi &par){
    int c=0;
    par[idx]=p;
    for(auto it:graph[idx]){
        if(it.first!=p){
            mp[idx][arr[it.first]]+=it.second;
            if(arr[idx]!=arr[it.first]) { c+=it.second;}
            c+=DFS(it.first,idx,graph,arr,mp,par);
        }
    }
    return c;
}


void solve() {
    int n,q;
    cin>>n>>q;
    vi arr(n);
    input(arr,n);
    vector<vector<pii>> graph(n);
    map<int,map<int,int>> g2;// every edge cost
    forn(i,0,n-1){
        int a,b,w;
        cin>>a>>b>>w;
        a--; b--;
        graph[a].pb({b,w});
        graph[b].pb({a,w});
        g2[a][b]=w;
        g2[b][a]=w;
    }
    vector<map<int,int>> mp(n);// for every node comute cost for every color in it,s "childrens"  [node][color][cost] 
    vi p(n);// parent of node i
    int ans=DFS(0,-1,graph,arr,mp,p);
    while(q--){
        int idx,val;
        cin>>idx>>val;
        idx--;
        if(val==arr[idx]) { cout<<ans<<endl; continue;}
        if(idx!=0){// if it has parent
            int par=p[idx];
            int c=g2[idx][par];// node to parent cost
            if(arr[idx]==arr[par]) ans+=c; // agar pehly same thy to abb diff ho jay gy to add karo 
            mp[par][arr[idx]]-=c; // parent ky map me changing karo
            mp[par][val]+=c;
            if(arr[par]==val) ans-=c; // ab agar same hen to subt karo
        }
        // for childs
        if(mp[idx].find(arr[idx])!=mp[idx].end()) ans+=mp[idx][arr[idx]]; // agar pehly same thy to abb diff ho jay gy to add karo 
        arr[idx]=val;
        if(mp[idx].find(arr[idx])!=mp[idx].end()) ans-=mp[idx][arr[idx]]; // ab agar same hen to subt karo
        cout<<ans<<endl;
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