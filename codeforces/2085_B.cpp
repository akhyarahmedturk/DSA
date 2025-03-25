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

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int num = -1, zero = 0, ones = 0;
    forn(i, 0, n){
        cin >> arr[i];
    }
    forn(i, 0, n){
        if (arr[i] == 0) zero++;
        else if (num == -1) num = i;
        else ones = i;
    }
    if (zero == 0){
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
    }
    else if (num == -1){
        cout << 3 << endl;
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << n - 1 << endl;
        cout << 1 << " " << 2 << endl;
    }
    else if (arr[0] != 0){
        cout << 2 << endl;
        cout << 2 << " " << n << endl;
        cout << 1 << " " << 2 << endl;
    }
    else if (arr[n - 1] != 0){
        cout << 2 << endl;
        cout << 1 << " " << n - 1 << endl;
        cout << 1 << " " << 2 << endl;
    }
    else{
        cout << 3 << endl;
        cout << 3 << " " << n << endl;
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << 2 << endl;
    }
}

int32_t main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}