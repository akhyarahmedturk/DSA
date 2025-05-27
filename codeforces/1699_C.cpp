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
    int n;
    cin >> n;
    vi arr(n);
    forn(i, 0, n){
        int a;
        cin >> a;
        arr[a] = i;
    }
    if (n == 0){ cout << 1 << endl; return; }
    int l = arr[0], r = arr[1], ans = 1, occupied = 0;
    if (l > r) swap(l, r);// current range is from l+1 to r-1
    occupied = 2; // currently 2 places are occupied
    forn(i, 2, n){
        if (arr[i] < l){
            l = arr[i]; // not in range so cannot place anywhere elece except original pos
        }
        else if (arr[i] > r){
            r = arr[i]; // not in range so cannot place anywhere elece except original pos
        }
        else{
            ans = (ans * (r - l + 1 - occupied)) % mod; // can place anywhere in range
        }
        occupied++;
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