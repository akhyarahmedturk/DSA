/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-02-26 00:35 (GMT+5)

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
// #define int long long
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
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    vi mp(n+m+10,0);
    for(auto it:a){
        for(int i=it;i<=n+m;i+=it) mp[i]++; 
    }
    int c1=0,c2=0,c3=0;
    for(auto it:b){
        if(mp[it]==0) c1++;
        else if(mp[it]==a.size()) c2++;
        else c3++;
    }
    if(c3&1){
        if(c2>=c1) cout<<"Alice"<<nl;
        else cout<<"Bob"<<nl;
    } 
    else{
        if(c2>c1) cout<<"Alice"<<nl;
        else cout<<"Bob"<<nl;
    }
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