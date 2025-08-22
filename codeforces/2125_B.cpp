/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-22 19:49 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long

void solve(){
    int a, b, k;
    cin >> a >> b >> k;
    int gcd = __gcd(a, b);
    if (a / gcd <= k && b / gcd <= k) cout << 1 << endl;
    else cout << 2 << endl;
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