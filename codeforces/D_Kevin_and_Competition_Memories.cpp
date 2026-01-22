/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-23 17:46 (GMT+5)

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
    int n,m; cin>>n>>m;
    vi a(n),b(m); input(a,n); input(b,m);
    int x=a[0];
    vi bb,aa;
    for(auto it:a){
        if(it>x) aa.pb(it);
    }
    sort(all(aa));
    for(auto it:b){
        if(it>x && it<=aa.back()) bb.pb(it);
    }
    sort(all(bb));
    cout<<bb.size()<<endl;
    forn(i,1,m+1){
        int ya=m%i;
        int t=m/i;//total rounds
        if(ya>=bb.size()) cout<<t<<" ";//sari grater rating wali delete karo
        else{
            int res=0;
            int end=bb.size()-1;
            int t=0;
        }
    }
    cout<<endl;
}
// 3 4 5 7
// 2 4 5 6
// 7,4,2,3
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