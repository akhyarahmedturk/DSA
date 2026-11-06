/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-24 21:26 (GMT+5)

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
    int n; cin>>n;
    vi arr(n+1);
    forn(i,1,n+1) cin>>arr[i];
    vi arr2=arr;
    int res=0;
    forn(i,1,n+1){
        while(arr[i]!=i) swap(arr[i],arr[arr[i]]) , res++;
    }
    int ans=res+1;
    forn(i,1,n){
        if(arr2[i]!=i && arr2[i+1]!=i+1) ans=min(res,ans);
        if(arr2[i]==i+1 && arr2[i+1]==i) ans=res-1;
        if(arr2[i]==i+1 || arr2[i+1]==i) { cout<<res-1<<endl; return;}
    }
    if(arr2[n]==n-1) { cout<<res-1<<endl; return;}
    cout<<res+1<<endl;
}
// 1 4 2 3

// 1 7 5 8 2 6 3 4
// 1 7 5 4 2 6 3 8

// 1 7 6 5 4 3 2 8

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