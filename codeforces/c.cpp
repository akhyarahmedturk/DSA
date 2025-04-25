#include <iostream>
#include <algorithm>
#include <vector>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
// #define int long long
// #define ld long double
// #define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
// #define mp make_pair
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
// #define mod 1000000007
// #define mod2 998244353
// const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve(){
    int n;  cin >> n;
    ll a, b, d = LLONG_MIN;
    fnr(i, n){
        ll x, y; cin >> x >> y;
        if (((x * x) + (y * y)) > d){
            d = x * x + y * y;
            a = x; b = y;
        }


    }
    cout << a << ' ' << b << endl;
}

void solve() {
    int n;  cin >> n;
    ll a, b, d = INT_MIN;
    fnr(i, n) {
        int x, y; cin >> x >> y;
        if (((x*x) + (y*y) ) > d) {
            d = x*x + y*y;
            a = x; b = y;
        }


    }
    cout << a << ' ' << b << endl;
}
 
int main() {
    //auto st = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    solve();
 
    //cerr << "Time measured: " << (ld)(chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - st)).count() / 1000.0 << " seconds.\n";
 
    return 0;
}
 

int main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (solve()){ }
    return 0;
};