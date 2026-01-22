/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-06 10:15 (GMT+5)

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
// #define mod 1000000007
#define mod 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX
#define nl "\n"

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    int n; cin>>n;
    vector<vi> graph(n);
    vector<vi> levels(n); levels[0].pb(0);
    vi level(n,0);
    int mx=0;
    forn(i,1,n){
        int x; cin>>x; x--;
        int l=level[x]+1;
        levels[l].pb(i);  level[i]=l;
        graph[x].pb(i);
        mx=max(mx,l);
    }
    vi dp(n,0);
    int prv=0;
    forr(i,mx,1){
        int curr=0;
        for(auto it:levels[i]){
            dp[it]=(prv+1)%mod;
            for(auto child:graph[it]) dp[it]=(dp[it]-dp[child]+mod)%mod;
            curr=(curr+dp[it])%mod;
        }
        prv=curr;
    }
    cout<<(prv+1)%mod<<endl;
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