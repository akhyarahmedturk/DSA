/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-12 22:54 (GMT+5)

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
#define yesno(b) cout << ((b) ? "Alice" : "Bob") << "\n";
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
    // jo bhi karlo in the end same number of moves hi hongi
    // because for ex last one will always gives left one x*k stones and then 2nd last will .....
    int n,k; cin>>n>>k;
    vi arr(n); input(arr,n);
    int c=0,t=0;
    vi diff(n,0);
    forr(i,n-1,0){
        arr[i]+=c;
        diff[max(0ll,i-k)]=arr[i];
        arr[i]%=2;
        c+=arr[i];
        c-=diff[i];
        t+=arr[i];
        c=abs(c); 
        c%=2;
        t%=2;
    }
    yesno(t);
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
    // for(int i=0;i>=-10;i--) cout<<i%2<<" ";
    return 0;
}