/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-23 08:32 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");
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
// #define mp make_pair
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    int n,m,k,d;
    cin>>n>>m>>k>>d;
    vi cost(n+1,0LL);
    forn(i,0,n){
        vi dp(m);
        input(dp,m);
        dp[m-1]=1;
        multiset<int> st;
        st.insert(dp[m-1]);
        forr(j,m-2,0){
            dp[j]+=1+*st.begin();
            st.insert(dp[j]);
            if(j+d+1<=m-1) st.erase(st.find(dp[j+d+1]));
        }
        cost[i+1]=cost[i]+dp[0];
        // cout<<cost[i+1]<<endl;
    }
    int res=cost[k]; 
    forn(i,k+1,n+1){
        res=min(res,cost[i]-cost[i-k]);
    }
    cout<<res<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}