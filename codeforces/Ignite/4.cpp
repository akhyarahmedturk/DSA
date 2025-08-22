/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-29 12:53 (GMT+5)

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
const ld PI = acos(-1);
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

ld reduce(ld angle) {
    while (angle < 0) angle += 2 * PI;
    while (angle >= 2 * PI) angle -= 2 * PI;
    return angle;
}

void solve(){
    int n;
    ld r;
    cin >> n >> r;

    vector<pair<ld, ld>> intervals;

    forn(i, 0, n) {
        ld x, y;
        cin >> x >> y;
        ld d = hypot(x, y);
        if (d <= r) {
            cout << fixed << setprecision(6) << 0.0 << endl;
            return;
        }

        ld th = atan2(y, x);
        ld aa = asin(r / d);
        ld start = reduce(th - aa);
        ld end = reduce(th + aa);

        if (start > end) {
            intervals.pb({start, 2 * PI});
            intervals.pb({0, end});
        } else {
            intervals.pb({start, end});
        }
    }

    sort(all(intervals));
    vector<pair<ld, ld>> mm;

    for (auto curr : intervals) {
        if (mm.empty() || curr.f > mm.back().ss) {
            mm.pb({curr.f, curr.ss});
        } else {
            mm.back().ss = max(mm.back().ss, curr.ss);
        }
    }

    ld res = 0;
    for (int i = 0; i < mm.size(); i++) {
        ld curr_end = mm[i].ss;
        ld next_st = mm[(i + 1) % mm.size()].f;
        ld gap = (next_st - curr_end + 2 * PI);
        if (gap >= 2 * PI) gap = 0;
        res = max(res, fmod(gap, 2 * PI));
    }

    cout << fixed << setprecision(6) << res * 180.0 / PI << endl;
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