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
    int res = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq[3];
    vector<vector<pii>> mp(3, vector<pii>(3));
    for (int j = 0;j < 3;j++){
        forn(i, 0, n){
            int x;
            cin >> x;
            pq[j].push({ x,i });
            if (pq[j].size() > 3) pq[j].pop();
        }
        mp[j][0] = pq[j].top();
        pq[j].pop();
        mp[j][1] = pq[j].top();
        pq[j].pop();
        mp[j][2] = pq[j].top();
        pq[j].pop();
    }
    for (int i = 0;i < 3;i++){
        for (int j = 0;j < 3;j++){
            if (mp[0][i].second == mp[1][j].second) continue;
            for (int k = 0;k < 3;k++){
                if (mp[0][i].second == mp[2][k].second || mp[1][j].second == mp[2][k].second) continue;
                res = max(res, mp[0][i].first + mp[1][j].first + mp[2][k].first);
            }
        }
    }
    cout << res << endl;
}

int32_t main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}