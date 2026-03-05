/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-03-03 17:59 (GMT+5)

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

// euler cycle(1-based edge list)

// for directed graphs(indeg=outdeg)

// for Euler path
// start and end ki degree odd hogi cause start py wapis nahi aana ans same for end
// baqi sab ki degree even



vi getEulerCycle(int start,int n, int m, vector<vector<pii>> &adj){
    vector<bool> used(m, false);
    vi euler;
    stack<int> st;
    st.push(start);
    while (!st.empty()){
        int u = st.top();
        while (!adj[u].empty() && used[adj[u].back().second])
            adj[u].pop_back();
        if (adj[u].empty()){
            euler.pb(u);
            st.pop();
        }
        else{
            auto [v, id] = adj[u].back();
            adj[u].pop_back();

            if (!used[id]){
                used[id] = true;
                st.push(v);
            }
        }
    }
    if ((int)euler.size() != m + 1)
        return {}; // Not connected
    reverse(euler.begin(), euler.end());
    return euler;
}


void solve() {
    int n; cin>>n;
    vector<pair<string,string>> arr(n); 
    vector<string> ya;
    forn(i,0,n){
        string s; cin>>s;
        string u=s.substr(0,2),v=s.substr(1,2);
        arr[i]={u,v};
        ya.pb(u); ya.pb(v);
    }
    sort(all(ya)); ya.erase(unique(all(ya)),ya.end());
    int size=ya.size();
    map<string,int> mp;
    forn(i,0,size) {mp[ya[i]]=i; cout<<ya[i]<<" ";}
    cout<<endl;
    vi indeg(size,0),outdeg(size,0);
    vector<vector<pii>> graph(size);
    int start=0,cnt_s=0,cnt_e=0;
    forn(i,0,n){
        indeg[mp[arr[i].f]]++;
        outdeg[mp[arr[i].ss]]++;
        graph[mp[arr[i].f]].pb({mp[arr[i].ss],i});
        // graph[mp[arr[i].ss]].pb({mp[arr[i].f],i});
    }
    forn(i,0,size){
        if(indeg[i]==outdeg[i]) continue;
        if(indeg[i]+1==outdeg[i]) {
            start=i; cnt_s++;
        }
        else if(indeg[i]==outdeg[i]+1) cnt_e++;
    }
    if(cnt_e>1 || cnt_e>1){ cout<<"NO"<<endl; return;}
    vi res=getEulerCycle(start,size,n,graph);
    stack<int> st;
    vector<int> path; 
    st.push(start);
    while(not st.empty()){
        int v = st.top();
        if(not graph[v].empty()){
            int u = graph[v].back().f;
            graph[v].pop_back();
            st.push(u);
        } else {
            path.pb(v); 
            st.pop();
        }
    }
    reverse(all(path));
    for(auto it:path) cout<<it<<" ";
    cout<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}