/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-07 22:46 (GMT+5)

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

void solve() {
    int n;
    string a,b;
    cin>>a>>b;
    if(a.length() != b.length()) {
        cout << -1 << endl;
        return;
    }
    n= a.length();
    vector<vi> dist(26, vi(26, inf));
    int m;
    cin >> m;
    while(m--) {
        char u,v;
        int w;
        cin >> u >> v >> w;
        if(dist[u - 'a'][v - 'a'] < w) continue; 
        dist[u - 'a'][v - 'a'] = w;
    }
    forn(k, 0, 26) {
        forn(i, 0, 26) {
            forn(j, 0, 26) {
                if(i==j) dist[i][j] = 0;
                else if(dist[i][k] != inf && dist[k][j] != inf){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    int ans = 0;
    string res = "";
    forn(i, 0, n) {
        int d=inf;
        int ch=-1;
        forn(j, 0, 26) {
            if(dist[a[i] - 'a'][j] == inf || dist[b[i] - 'a'][j] == inf) continue;
            if(d > dist[a[i] - 'a'][j] + dist[b[i] - 'a'][j]) {
                d = dist[a[i] - 'a'][j] + dist[b[i] - 'a'][j];
                ch = j;
            }
        }
        if(d==inf) {
            cout << -1 << endl;
            return;
        }
        ans += d;
        res.push_back(ch + 'a');
    }
    cout << ans << endl<<res << endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}