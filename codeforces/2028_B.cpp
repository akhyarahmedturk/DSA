/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-20 17:51 (GMT+5)

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
    int n, b, c;
    cin >> n >> b >> c;
    // if(b==0 && c==0 && n){ cout<<-1<<endl; return; }
    if (b == 1 && c == 0){ cout << 0 << endl; return; }
    if (n == 1){
        if (c == 0) cout << 0 << endl;
        else cout << 1 << endl;
        return;
    }
    if (b == 0){
        if (c >= n){ cout << n << endl; return; }
        n -= c;
        if (n <= 2) cout << n - 1 << endl;
        else cout << -1 << endl;
        return;////////////////////////////////////

        ////////////////////////////////////

        ////////////////////////////////////

        ////////////////////////////////////

        ////////////////////////////////////
        //////////////////////////////////// not solved
        ////////////////////////////////////
    }
    int start = 1LL, end = n, ans = n, mid;
    // if(c-1>n){ cout<<-1<<endl; return; }
    while (start <= end){
        mid = (start + end) / 2LL;
        if ((__int128)(n - mid) * b + c - 1 <= n){
            if (mid == 263382062451470182) cout << (n - mid) * b + c << endl;
            ans = mid;
            end = mid - 1LL;
        }
        else start = mid + 1LL;
    }
    cout << ans << endl;
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