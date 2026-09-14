/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-11 14:47 (GMT+5)

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


// 1 2 3 4 | 2 3 4 1 | 3 4 1 2 | 4 1 2 3 

void solve() {
    int n,q; cin>>n>>q;
    vi arr(n); input(arr,n);
    vi prefix(n+1,0);
    forn(i,0,n) prefix[i+1]=prefix[i]+arr[i];
    while(q--){
        int l,r; cin>>l>>r;
        int idx2=(r+n-1)/n;
        int idx1=(l+n-1)/n;
        int res=(idx2-idx1)*prefix[n];
        l=(l-1)%n;
        if(l>(n-idx1+1)){
            res-=prefix[l-(n-idx1+1)];   
        }
        if(l){
            res-=(prefix[min(n,idx1-1+l)]-prefix[idx1-1]);
        }
        r%n==0? r=n:r=r%n;
        if(r>=(n-idx2+1)){
            res+=(prefix[n]-prefix[idx2-1]);
            res+=prefix[r-(n-idx2+1)];
        }
        else res+=(prefix[idx2-1+r]-prefix[idx2-1]);
        cout<<res<<endl;
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