/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-05 11:12 (GMT+5)

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

bool check(int mid,vi &arr,int n){
    vi dp(n+10,0);
    multiset<int> st;
    st.insert(0); st.insert(0);
    int r=n,sum=0;
    forr(i,n-1,0){
        while(sum>mid) sum-=arr[r] , st.erase(st.find(dp[r+1])) , r--;
        dp[i]=arr[i]+*st.begin();
        st.insert(dp[i]);
        sum+=arr[i];
        // if(mid==5) cout<<dp[i]<<" "<<r<<endl;
    }
    int idx=0,curr=0;
    while(idx<n && curr+arr[idx]<=mid && dp[idx]>mid) curr+=arr[idx] , idx++;
    return dp[idx]<=mid;
}

void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n); arr.pb(0);
    int res,l=*max_element(all(arr)),r=1e9*n,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid,arr,n)) res=mid , r=mid-1;
        else l=mid+1;
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