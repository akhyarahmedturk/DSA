/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-01 00:57 (GMT+5)

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
#define f first
#define ss second
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

int solve(int idx, int x, int avail, vector<pii>& vals, vector<vi>& dp, vi& prefix){
    avail = min(avail, min(x * idx,prefix[idx]));
    if (dp[idx][avail]!=-1) return dp[idx][avail];
    if (avail - prefix[idx - 1] >= vals[idx].first || vals[idx].first==0) return dp[idx][avail] = solve(idx - 1, x, avail - vals[idx].first, vals, dp, prefix) + vals[idx].second;
    if (avail < vals[idx].first) return dp[idx][avail] = solve(idx - 1, x, avail, vals, dp, prefix);
    else if (avail - x * (idx - 1) >= vals[idx].first) return dp[idx][avail] = solve(idx - 1, x, avail, vals, dp, prefix) + vals[idx].second;
    else{
        return dp[idx][avail] = max(solve(idx - 1, x, avail - vals[idx].first, vals, dp, prefix) + vals[idx].second, solve(idx - 1, x, avail, vals, dp, prefix));
    }
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<pii> vals(n);
    forn(i, 0, n){
        cin>>vals[i].first>>vals[i].second;
    }
    vi prefix(n);
    prefix[0] = 0;
    forn(i, 1, n){
        prefix[i] = prefix[i - 1] + vals[i].first;
    }
    vector<vi> dp(n,vi(prefix[n-1]+10,-1));
    if(vals[0].first==0) dp[0][0]=vals[0].second;
    else dp[0][0]=0;
    cout <<solve(n - 1, x, (n - 1) * x, vals, dp, prefix) << endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}