/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-18 18:43 (GMT+5)

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
    int n,q; cin>>n>>q;
    vector<vi> arr(n-1,vi(3));//edges
    forn(i,0,n-1) cin>>arr[i][1]>>arr[i][2]>>arr[i][0];
    sort(all(arr));
    vector<pii> res={{0,0}};
    int curr=0;
    DSU dsu(n+2);
    forn(i,0,n-1){
        int u=arr[i][1],v=arr[i][2],c=arr[i][0];
        int a=dsu.size[dsu.find(u)],b=dsu.size[dsu.find(v)];
        curr-=(a*(a-1))/2; curr-=(b*(b-1))/2;
        dsu.unite(u,v);
        a=dsu.size[dsu.find(u)];
        curr+=(a*(a-1))/2;
        if(c==res.back().first) res[res.size()-1].second=curr;
        else res.pb({c,curr});
    }
    while(q--){
        int x; cin>>x;
        if(x>=res.back().first) cout<<res.back().second<<" ";
        else {
            auto it=upper_bound(all(res),make_pair(x,inf));
            it--;
            cout<<it->second<<" ";
        }
    }
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