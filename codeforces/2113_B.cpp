/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-15 14:03 (GMT+5)

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
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dy = abs(y2 - y1), dx = abs(x2 - x1);
    if (dx == a || dy == b){ cout << "YES" << endl; return; }// agar corners joint hen
    if (dx < a){// agar x me overlap ho rha
        dy -= b;
        if (dy % b == 0){ cout << "YES" << endl; } // y wali sheets fit honi chahy
        else cout << "NO" << endl;
    }
    else if (dy < b){// same as above
        dx -= a;
        if (dx % a == 0){ cout << "YES" << endl; }
        else cout << "NO" << endl;
    }
    else{// agar averlaap nahi to y sy bhi fill kar sakty x sy bhi 
        if (dx % a == 0 || dy % b == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
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