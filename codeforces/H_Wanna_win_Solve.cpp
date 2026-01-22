/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-01 22:42 (GMT+5)

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

int n;
string ans = "-1";
// aba
bool ss(string& curr, string& rem, map<string, set<string>>& dp){
    if(curr.length()>(n+1)/2){
        for (int i = 0;i < n / 2;i++){
            if (n - 1 - i<curr.length() && curr[i] != curr[n - 1 - i]) return false;
        }
    }
    if (rem.empty()){
        for (int i = 0;i < n / 2;i++){
            if (curr[i] != curr[n - 1 - i]) return false;
        }
        ans = curr;
        return true;
    }
    if (dp.find(curr) != dp.end() && dp[curr].find(rem) != dp[curr].end()) return false;
    if (rem.back() <= rem[0]){
        curr.pb(rem.back()); rem.pop_back();
        if (ss(curr, rem, dp)) return true;
        rem.pb(curr.back()); curr.pop_back();
        reverse(all(rem));
        curr.pb(rem.back()); rem.pop_back();
        reverse(all(rem));
        if (ss(curr, rem, dp)) return true;
        reverse(all(rem));
        rem.pb(curr.back()); curr.pop_back();
        reverse(all(rem));
    }
    else{
        reverse(all(rem));
        curr.pb(rem.back()); rem.pop_back();
        reverse(all(rem));
        if (ss(curr, rem, dp)) return true;
        reverse(all(rem));
        rem.pb(curr.back()); curr.pop_back();
        reverse(all(rem));
        curr.pb(rem.back()); rem.pop_back();
        if (ss(curr, rem, dp)) return true;
        rem.pb(curr.back()); curr.pop_back();
    }
    dp[curr].insert(rem);
    return false;
}

void solve(){
    string s; cin >> s;
    n = s.length();
    string ya = "";
    map<string, set<string>> dp;
    bool t = ss(ya, s, dp);
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}