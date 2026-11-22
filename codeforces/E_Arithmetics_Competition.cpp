/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-22 12:04 (GMT+5)

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

void solve() {
    int n,m,q; cin>>n>>m>>q;
    vi a(n),b(m); input(a,n); input(b,m);
    sort(allr(a)) ; sort(allr(b));
    vector<pii> mp(n+m+1); mp[0]={0,0};
    int x=0,y=0;
    forn(i,0,n+m){
        if(x==n) y++;
        else if(y==m || a[x]>=b[y]) x++;
        else y++;
        mp[i+1]={x,y};
    }
    vi prefixa(n+1,0),prefixb(m+1,0);
    forn(i,0,n) prefixa[i+1]=a[i]+prefixa[i]; 
    forn(i,0,m) prefixb[i+1]=b[i]+prefixb[i];
    while(q--){
        int x,y,z; cin>>x>>y>>z;
        // cout<<mp[z].f<<" "<<mp[z].ss<<" ";
        if(mp[z].f>=x) cout<<prefixa[x]+prefixb[z-x]<<endl;
        else if(mp[z].ss>=y) cout<<prefixa[z-y]+prefixb[y]<<endl;
        else cout<<prefixa[mp[z].f]+prefixb[mp[z].ss]<<endl;;
    } 
    // cout<<endl;
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