/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-27 09:09 (GMT+5)

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

class BinaryLifting{
    int n, LOG;
    vector<vi> up;
    vi adj;
public:
    BinaryLifting(int size, vi & graph){
        n = size;
        LOG = 31;
        up.assign(LOG, vi(n,-1));
        adj = graph;
        preprocess();
    }

    void preprocess(){
        forn(i,1,n) up[0][i]=adj[i];//child 2^0=1 dis py hoga
        forn(i,1,LOG){
            forn(j,1,n) up[i][j]=  up[i-1][up[i-1][j]];//2^1 hy to child ka child
        }
    }

    // kth ancestor of node u
    int down(int u, int k){
        for (int j = 0; j < LOG; j++){
            if (k & (1LL << j)){
                u = up[j][u];
            }
        }
        return u;
    }
};



void solve() {
    int n,q; cin>>n>>q;
    vi graph(n+1);
    forn(i,0,n) cin>>graph[i+1];
    BinaryLifting bl(n+1,graph);
    while(q--){
        int idx,v; cin>>idx>>v;
        cout<<bl.down(idx,v)<<nl;
    }
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