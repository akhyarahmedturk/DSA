/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-05-23 10:26 (GMT+5)

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
    vi a(n),b(n); input(a,n); input(b,n);
    vi mp1(n+2,n),mp2(n+2,n);
    // dp store like 1,1 -> 2,2 -> 3,3 ....
    vi dp(n+2,0); 
    int res=0;
    forr(i,n-1,0){
        mp1[a[i]]=i;
        mp2[b[i]]=i;
        if(a[i]==b[i]){
            if(mp1[a[i]+1]==mp2[a[i]+1]){
                dp[i]=dp[mp1[a[i]+1]] + (mp1[a[i]+1]-i);
            }
            else dp[i]=(min(mp1[a[i]+1],mp2[b[i]+1])-i);
            if(a[i]==1) res+=dp[i];
            else{
                if(mp1[1]==mp2[1]) res+=dp[mp1[1]] + (mp1[1]-i);
                else res+=(min(mp1[1],mp2[1])-i);
            }
        }
        else{
            if(mp1[1]==mp2[1]) res+=dp[mp1[1]] + (mp1[1]-i);
            else res+=(min(mp1[1],mp2[1])-i);
        }
    }
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