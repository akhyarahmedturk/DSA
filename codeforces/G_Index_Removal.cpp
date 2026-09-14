/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-05 20:10 (GMT+5)

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
    int n, k;
    cin >> n >> k;
    vi a(n), p(n), pref(n + 1), ans(n);
    input(a, n);
    forn(i, 0, n) {
        p[i] = a[i] - i * k;
        pref[i + 1] = pref[i] + p[i];
    }
    forn(i, 1, n - 1) {
        int e = a[i + 1] - a[i - 1] - k;
        if (e <= 0) continue;
        int need = p[i + 1] - e;
        int l = i + 1, r = n - 1, pos = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (p[mid] <= need) {
                pos = mid - 1;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        int cnt = pos - i;
        ans[i] = cnt * (e - p[i + 1]) + pref[pos + 1] - pref[i + 1];
    }
    forn(i, 0, n) cout << ans[i] << " ";
    cout << nl;
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

//mera code nahi he