#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

int DFS(int v,int par,vector<vector<pii>> &graph,vi &values,int curr){
    // cout<<v<<" par "<<par<<" curr "<<curr<<endl;
    int count=1LL;
    if(values[v]<curr) return 0LL;
    else{
        forn(i,0,graph[v].size()){
            if(graph[v][i].first!=par){
                int curr_a=max(curr+graph[v][i].second,graph[v][i].second);
                count+=DFS(graph[v][i].first,v,graph,values,curr_a);
            }
        }
    }

    return count;   
} 

void solve() {
    int n;
    cin>>n;
    vi arr(n);
    input(arr,n);
    vector<vector<pii>> graph(n);
    forn(i,1,n){
        int v,val;
        cin>>v>>val;
        v--;
        graph[i].pb({v,val});
        graph[v].pb({i,val});
    }
    cout<<n-DFS(0,-1,graph,arr,0LL)<<endl;
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