/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-05 17:09 (GMT+5)

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

//sirf prfect square numbers ky number of divisors odd hoty
// to wo sab arrays find karo jin ka XOR perfect square ho 
// ans=total - those
// 0 1 4 25 36 .....10^3*10^3    a[i]<=1e5 so, max 1e3
void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n);
    int res=(n*(n+1))/2; //total
    // map<int,int> mp;
    vi mp(2*n+10+1,0);
    int ya=2e5;
    vi sq;
    for(int j=0;j*j<=2*n+10;j++) sq.pb(j*j);
    mp[0]=1;
    int curr=0;
    forn(i,0,n){
        curr^=arr[i];
        for(auto it:sq){
            int req=curr^it;
            if(req<=2*n+1) res-=mp[req];
        }
        if(curr<=2*n+1) mp[curr]++;
    }
    cout<<res<<nl;
}

// 7 10 


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