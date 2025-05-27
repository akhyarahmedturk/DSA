/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-23 10:00 (GMT+5)

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

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> diff;
    int mx = 0;
    pii p;
    int prv, curr;
    cin >> prv;
    forn(i, 1, n){
        cin >> curr;
        int a = curr - prv;
        if (a >= mx){
            mx = a;
            p = { curr,prv };
        }
        diff[a]++;
        prv = curr;
    }
    set<int> a, b;
    forn(i, 0, m){
        int x;
        cin >> x;
        if (x < p.first) a.insert(x);
    }
    forn(i, 0, k){
        int x;
        cin >> x;
        if (x < p.first) b.insert(x);
    }
    if (diff[mx] >= 2 || mx == 0 || b.size() == 0){ cout << mx << endl; return; }
    int mm = 0;
    if (diff.size() >= 2){
        auto it = --diff.end();
        it--;
        mm = it->first;
    }
    // cout<<mm<<endl;
    int res = p.first - p.second, want;
    want = (p.second + p.first) / 2;
    // cout<<p.first<<" "<<p.second<<endl;
    for (auto it : a){
        if (it > p.first) break;
        int rem = want - it, x = -1, y = -1;
        if (*b.begin() >= rem){
            x = it + *b.begin();
            res = min(res, max(p.first - x, x - p.second));
        }
        else if (*b.rbegin() <= rem){
            x = it + *b.rbegin();
            res = min(res, max(p.first - x, x - p.second));
        }
        else{
            auto itt = upper_bound(all(b), rem);
            x = *itt + it;
            itt--;
            y = *itt + it;
            res = min(res, max(p.first - y, y - p.second));
            res = min(res, max(p.first - x, x - p.second));
        }
        // cout<<x<<" v "<<y<<endl;
        if (res <= mm){ cout << mm << endl; return; }
    }
    cout << res << endl;
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