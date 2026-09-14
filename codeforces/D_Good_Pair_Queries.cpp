/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-08-01 21:12 (GMT+5)

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
    int n,q; cin>>n>>q;
    string a,b; cin>>a>>b;
    vi prefixa(n+2,0),prefixb(n+2,0);
    vi same(n+2,0);
    forn(i,0,n) {
        prefixa[i+1]=prefixa[i];
        prefixb[i+1]=prefixb[i];
        if(a[i]=='0') prefixa[i+1]=prefixa[i]+(a[i]!=b[i]);
        else prefixb[i+1]=prefixb[i]+(a[i]!=b[i]);
        same[i+1]=same[i]+(a[i]==b[i]);
    }
    while(q--){
        int x,y; cin>>x>>y;
        int alag1=(prefixa[y]-prefixa[x-1]);
        int alag2=(prefixb[y]-prefixb[x-1]);
        int s=(same[y]-same[x-1]);
        int diff=abs(alag1-alag2);
        yesno(diff<=s);
    }
}
// 01
// 10

// 1010
// 1101

// 11

// 111
// 100

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