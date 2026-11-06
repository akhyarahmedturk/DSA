/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-10-25 10:40 (GMT+5)

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
    int a1,a2,b1,b2; cin>>a1>>a2>>b1>>b2;
    vector<int> arr(n); input(arr,n);
    int mx=*max_element(all(arr));
    if(mx>a1 && mx>b1){ cout<<-1<<endl; return;}
    vector<int> dp(n+10,inf); dp[n]=0;
    vector<int> dp2(n+10,inf); dp2[n]=0;
    int r1=n-1,r2=n-1;
    int c1=0,c2=0;
    forr(i,n-1,0){
        c1+=arr[i];
        c2+=arr[i];
        while(c1>a1) c1-=arr[r1] , r1--;
        while(c2>b1) c2-=arr[r2] , r2--;
        if(r1>=i){
            if(c1*2LL>=a1) {
                dp[i]=min(dp[i],a2+dp[r1+1]);
                dp2[i]=min(dp2[i],a2+min(dp[r1+1],dp2[r1+1]));
            }
            else{
                dp2[i]=min(dp2[i],a2+dp[r1+1]);
            }
        }
        if(r2>=i){
            if(c2*2LL>=b1) {
                dp[i]=min(dp[i],b2+dp[r2+1]);
                dp2[i]=min(dp2[i],b2+min(dp[r2+1],dp2[r2+1]));
            }
            else{
                dp2[i]=min(dp2[i],b2+dp[r2+1]);
            }
        }
    }
    int res=min(dp[0],dp2[0]);
    if(res==inf) res=-1;
    cout<<res<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}