/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-22 14:38 (GMT+5)

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
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];
#define nl "\n"

int ss1(int idx, int& mm, int cur, vector<vi>& dp){
    if (!idx){
        return !cur ? 1 : 0;
    }
    else if (cur <= 0)
        return 0;

    if (dp[idx][cur] != -1)
        return dp[idx][cur];

    int res = 0;
    for (int j = mm; j <= cur ; j++)
        res += ss1(idx - 1, mm, cur - j, dp);

    return dp[idx][cur] = res;
}

void solve(){
    int n, t, m; cin >> n >> t >> m;
    int res = 0;

    vector<vi> dp(n + 1, vi(t + 1, -1));
    cout << ss1(n, m, t, dp) << nl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}