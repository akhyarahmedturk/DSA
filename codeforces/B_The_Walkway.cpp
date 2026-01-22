/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-02 14:18 (GMT+5)

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
    int n,m,k; cin>>n>>m>>k;
    vi arr(m); input(arr,m);
    sort(all(arr));
    arr.pb(n+1);
    vi dp(m+1,0);
    forr(i,m-1,0){
        dp[i]=dp[i+1]+1+(arr[i+1]-arr[i]-1)/k;
    }
    if(arr[0]!=1) dp[0]+=(1+(arr[0]-2)/k);
    int mm=dp[0],c=0;
    int prv=1,curr=1;
    int i=0;
    if(arr[0]==1) { i++; c=1; } 
    while(i<m){
        int ya=curr+(arr[i+1]-prv-1)/k+dp[i+1];
        if(ya==mm) c++;
        else if(ya<mm){
            mm=ya; c=1;
        }
        curr+=1+(arr[i]-prv-1)/k;
        prv=arr[i];
        i++;
    }
    // for(auto it:dp) cout<<it<<" ";
    // cout<<endl;
    cout<<mm<<" "<<c<<endl;
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