/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-02 19:20 (GMT+5)

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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> vec(n);
    forn(i, 0, n) cin >> vec[i];
    vector<vector<vi>> dp(n + 2, vector<vi>(m + 2, vi(4, 0)));// for prefix sums
    vector<vector<vi>> diffs(n + 1, vector<vi>(m + 1, vi(2, 0)));// difference array
    forn(i, 0, n){ // left and top sy prefix sum bna rahy
        forn(j, 0, m){
            if (vec[i][j] == '*'){
                dp[i + 1][j + 1][0] = dp[i + 1][j][0] + 1;
                dp[i + 1][j + 1][1] = dp[i][j + 1][1] + 1;
            }
        }
    }
    forr(i, n - 1, 0){// right and bottom sy prefix sum bna rahy
        forr(j, m - 1, 0){
            if (vec[i][j] == '*'){
                dp[i + 1][j + 1][2] = dp[i + 1][j + 2][2] + 1;
                dp[i + 1][j + 1][3] = dp[i + 2][j + 1][3] + 1;
            }
        }
    }
    vector<vi> res;
    forn(i, 0, n){
        forn(j, 0, m){
            sort(all(dp[i + 1][j + 1]));
            int a = dp[i + 1][j + 1][0];// sab sy bra star possible
            if (a <= 1) continue;
            res.push_back({ i + 1,j + 1,a - 1 });
            diffs[i - a + 1][j][1] += (a * 2 - 1); // add kia jaha sy start shuru
            diffs[i + a][j][1] -= (a * 2 - 1); // jaha py khatam
            diffs[i][j - a + 1][0] += (a * 2 - 1); // same for left and right
            diffs[i][j + a][0] -= (a * 2 - 1);
        }
    }
    vi x(n, 0), y(m, 0);
    forn(i, 0, n){
        forn(j, 0, m){
            x[i] += diffs[i][j][0];
            y[j] += diffs[i][j][1];
            if (vec[i][j] == '*' && x[i] == 0 && y[j] == 0){ cout << -1 << endl; return; } // agar x and y dono me available na ho to
        }
    }
    cout << res.size() << endl;
    forn(i, 0, res.size()){
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
    }
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}