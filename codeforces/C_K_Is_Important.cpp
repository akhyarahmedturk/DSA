/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-26 19:51 (GMT+5)

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
    int n,k; cin>>n>>k;
    vi arr(n); input(arr,n);
    if((k-1)*2<=n){
        int res=accumulate(all(arr),0LL);
        forn(i,0,k-1) res-=min(arr[i],arr[n-i-1]);
        cout<<res<<endl;
    }
    else{
        int res=0;
        k=n-k+1;
        forn(i,0,k) res+=max(arr[i],arr[n-i-1]);
        cout<<res<<endl;
    }
}

// 1 2 3 4 5
// 


// 1 2 3 4 5 6
// 1 2 3 5 6, 1 2 4 5 6
// 1 3 5 6, 1 2 4 6 , 1 3 5 6, 1 2 4 6
// 3 5 6, 1 2 4 , 3 5 6, 1 2 4 , 1 3 5, 2 4 6 , 1 3 5, 2 4 6

// 1 2 3 4 5 6
// 1 3 4 5 6 , 1 2 3 4 6
// 3 4 5 6 , 1 2 3 4 , 1 3 4 5 , 2 3 4 6

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