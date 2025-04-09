#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input_vec(vec, n) for(int i = 0; i < (n); i++) cin >> vec[i];
#define input_set(vec, n) for(int i = 0; i < (n); i++) { int x; cin>>x; vec.insert(x); }
#define input_map(vec, n) for(int i = 0; i < (n); i++) { int x; cin>>x; vec[x]++; }

void solve(){
    int n;
    cin >> n;
    map<int, int> mp;
    input_map(mp, n);
    int res = 0, curr = 0, prv = -1;
    for (auto it : mp){
        if (it.first == prv + 1) res += max(0LL, curr - it.second);
        else res += curr;
        curr = it.second;
        prv = it.first;
    }
    cout << res + curr << endl;
}

int32_t main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}