/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-22 20:03 (GMT+5)

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

//DSU

struct DSU{
    vi parent, size;
    DSU(int n){
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b){
        a = find(a), b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

void solve() {
    int n,m,k; cin>>n>>m>>k;
    vector<vi> e1,e2;
    forn(i,0,m){
        int a,b,c; cin>>a>>b>>c;
        if(c<=k) e1.pb({c,a,b});
        else e2.pb({c,a,b});
    }
    sort(allr(e1));
    sort(all(e2));
    DSU dsu(n+1);
    for(auto it:e1){
        bool c=dsu.unite(it[1],it[2]);
    }
    if(e1.size()){
        int size=dsu.size[dsu.find(e1[0][1])];
        if(size==n) { 
            if(e2.size()) cout<<min(k-e1[0][0],e2[0][0]-k)<<endl; 
            else cout<<k-e1[0][0]<<endl;
            return;
        }
    }
    int res2=0;
    for(auto it:e2){
        bool c=dsu.unite(it[1],it[2]);
        if(c) res2+=(it[0]-k);
        int size=dsu.size[dsu.find(it[1])];
        if(size==n) { cout<<res2<<endl; return; }
    }
    cout<<-1<<endl;
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