/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-08-26 23:42 (GMT+5)

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
#define yesno(b) cout << ((b) ? "YES" : "NO") << endl;
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

vi fib;

bool dfs(int n,int x,int y){
    // cout<<"n "<<n<<" x "<<x<<" y "<<y<<endl;
    if(x>fib[n] || y>fib[n+1]) return false;
    if(n<=1) return true;
    x=min(x,fib[n]-x+1);
    y=min(y,fib[n+1]-y+1);
    return dfs(n-2,x,y);
}


void solve() {
    int n,x,y; cin>>n>>x>>y;
    yesno(dfs(n,x,y));
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    cin >> t;
    fib={1,1};
    forn(i,2,46){
        fib.pb(fib[i-1]+fib[i-2]);
    }
    while (t--) {
        solve();
    }
    return 0;
}