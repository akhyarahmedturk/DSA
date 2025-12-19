/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-02 22:46 (GMT+5)

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

void comps(int idx,vi &vis,vector<vi> &graph,set<int> &comp){
    comp.insert(idx);
    vis[idx]=true;
    for(auto it:graph[idx]){
        if(!vis[it]) comps(it,vis,graph,comp); 
    }
}

void comps2(int idx,vi &vis,vector<vi> &graph){
    vis[idx]=true;
    for(auto it:graph[idx]){
        if(it!=-1 && !vis[it]) comps2(it,vis,graph); 
    }
}

void solve() {
    int n,m1,m2; cin>>n>>m1>>m2;
    vector<vi> g1(n),g2(n);
    forn(i,0,m1){
        int a,b; cin>>a>>b; a--; b--;
        g1[a].pb(b);
        g1[b].pb(a);
    }
    forn(i,0,m2){
        int a,b; cin>>a>>b; a--; b--;
        g2[a].pb(b);
        g2[b].pb(a);
    }
    vi vis1(n,0);
    int res=0,count=0;
    forn(i,0,n){
        if(!vis1[i]){
            count++;
            set<int> comp;
            comps(i,vis1,g2,comp);
            for(auto it:comp){
                for(auto &itt:g1[it]){
                    if(comp.find(itt)==comp.end()){ itt=-1; res++; }
                }
            }
        }
    }
    vi vis2(n,0);
    int count2=0;
    forn(i,0,n){
        if(!vis2[i]){
            count2++;
            comps2(i,vis2,g1);
        }
    }
    cout<<res/2+count2-count<<endl;
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