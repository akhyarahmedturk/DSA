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

void solve(int t){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> grid(n, vector<int>(n));
    forn(i, 0, n){
        forn(j, 0, n) cin >> grid[i][j];
    }
    int i = 0, j = n - 1;
    while (i <= j){
        if (k < 0) break;
        forn(l, 0, n){
            if (grid[i][l] != grid[j][n - l - 1]){
                k--;
                grid[i][l] = grid[j][n - l - 1];
            }
        }
        i++;
        j--;
    }
    yesno((k >= 0 && (n % 2 == 1 || k % 2 == 0)));
}

int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve(t);
    }
    return 0;
}