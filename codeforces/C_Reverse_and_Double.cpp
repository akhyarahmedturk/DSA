/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-07 19:55 (GMT+5)

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
    vi arr(n); input(arr,n);
    int res=0;
    forn(i,1,n) res=max(res,abs(arr[i]-arr[i-1]));
    vi suffix(n+1,0);
    forr(i,n-2,0) suffix[i]=max(suffix[i+1],abs(arr[i]-arr[i+1]));
    int curr=0;
    int ans=res;
    forn(i,1,n){
        if(res==abs(arr[i]-arr[i-1])){
            int mx=curr;
            forn(j,i,n){
                int ya=abs(arr[j]*2LL-arr[i-1]);
                if(j!=n-1){
                    ya=max(ya,abs(arr[i]*2LL-arr[j+1]));
                    ya=max(ya,suffix[j+1]);
                }
                if(j!=i) mx=max(mx,abs(arr[j]*2LL-arr[j-1]*2LL));
                ya=max(ya,mx);
                ans=min(ans,ya);
            }
            break;
        }
        curr=max(curr,abs(arr[i]-arr[i-1]));
    }
    vi prefix(n+1,0);
    forn(i,1,n) prefix[i]=max(prefix[i-1],abs(arr[i]-arr[i-1]));
    curr=0;
    forr(i,n-2,0){
        if(res==abs(arr[i]-arr[i+1])){
            int mx=curr;
            forr(j,i,0){
                int ya=abs(arr[j]*2LL-arr[i+1]);
                if(j!=0){
                    ya=max(ya,abs(arr[i]*2LL-arr[j-1]));
                    ya=max(ya,prefix[j-1]);
                }
                if(j!=i) mx=max(mx,abs(arr[j]*2LL-arr[j+1]*2LL));
                ya=max(ya,mx);
                ans=min(ans,ya);
            }
            break;
        }
        curr=max(curr,abs(arr[i]-arr[i+1]));
    }
    cout<<ans<<endl;
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

// 500 502 2 3 