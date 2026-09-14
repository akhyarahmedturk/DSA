/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-11 09:22 (GMT+5)

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
    int n; cin>>n;
    vi arr(2*n); input(arr,2*n);
    vector<vi> bulb(n+1);
    forn(i,0,2*n) bulb[arr[i]].pb(i);
    vi divs;
    int l=0,r=0;
    while(r<2*n){
        r=max(r,bulb[arr[l]][1]);
        if(l==r) divs.pb(l) , r++; 
        l++;
    }
    int res1=divs.size();
    int res2=1;
    DSU dsu(n+1);
    l=0;
    for(auto it:divs){
        r=it;
        set<pii> st; 
        forn(i,l,r+1){
            if(i==bulb[arr[i]][1]){
                st.erase({bulb[arr[i]][1],arr[i]});
                continue;
            }
            st.insert({bulb[arr[i]][1],arr[i]});
            for(auto it:st) {
                if(it.ss==arr[i]) break;
                dsu.unite(arr[i],it.ss);
            }
        }
        forr(i,r,l){
            if(i==bulb[arr[i]][0]){
                st.erase({bulb[arr[i]][0],arr[i]});
                continue;
            }
            st.insert({bulb[arr[i]][0],arr[i]});
            bool ch=false;
            for(auto it:st) {
                if(ch) dsu.unite(arr[i],it.ss);
                if(it.ss==arr[i]) ch=true;
            }
        }
        int ya=dsu.size[dsu.find(arr[l])];
        res2=(res2*ya*2)%mod2;
        l=it+1;
    }
    cout<<res1<<" "<<res2<<endl;
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