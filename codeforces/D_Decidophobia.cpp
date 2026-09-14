/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-06-28 21:02 (GMT+5)

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
    // vector<pii> arr2(n);
    // forn(i,0,n) arr2[i]={arr[i],i};
    // sort(allr(arr2));
    // vi vis(n,0);
    // int res=0,curr=0;
    // forn(i,0,n){
    //     int idx=arr2[i].ss,val=arr2[i].f;
    //     int ya=0;
    //     forn(j,1,k+1){
    //         if(vis[(idx+j)%n]) ya-=arr[(idx+j)%n]-val;
    //         else ya+=val-arr[(idx+j)%n];
    //         if(vis[(idx-j+n)%n]) ya-=arr[(idx-j+n)%n]-val;
    //         else ya+=val-arr[(idx-j+n)%n];
    //     }
    //     if(ya>=0) curr+=ya ,  vis[idx]=1 , res=curr;
    // }
    vi prefix(n,0),suffix(n,0);
    int curr=0;
    forn(i,0,2*n){
        if(i>=k){
            prefix[i%n]=(arr[i%n]*k-curr);
            curr-=arr[(i-k+n)%n];
        }
        curr+=arr[i%n];
    }
    curr=0;
    vi sum(n,0);
    forr(i,2*n-1,0){
        if(i+k<=2*n-1){
            suffix[i%n]=(arr[i%n]*k-curr);
            curr-=arr[(i+k)%n];
            sum[i%n]=prefix[i%n]+suffix[i%n];
        }
        curr+=arr[i%n];
    }
    sort(all(sum));
    int res=0;
    for(auto it:sum) res+=max(it,0LL);
    cout<<res<<endl;
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