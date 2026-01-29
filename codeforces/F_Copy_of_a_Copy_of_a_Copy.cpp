/*   Bismillah
*    Author: Aihyar Ahmed Turi
*    Created: 2026-01-24 23:44 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");

*    Those who can't remember the past are condemned to repeat it.
*                                                 -Dynamic Programming.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets liie (when you need lower upper bound while frequently updating set) 
// idx.order_of_iey(value) for nums<value idx.order_of_iey(value+1) for nums<=value
// idx.find_by_order(n); to get the nth value by order
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
#define pb push_back
#define f first
#define ss second
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX
#define nl "\n"

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve(){
    int n, m, k; cin >> n >> m >> k;
    int mx = 0;
    // map<int,vector<string>> mp;
    vector<vi> mp2(n, vi(m, 0));
    vector<vector<string>> arr(k + 1, vector<string>(n));
    forn(i, 0, k + 1){
        forn(j, 0, n) cin >> arr[i][j];
        forn(j, 1, n - 1){
            forn(xx, 1, m - 1){
                if (arr[i][j][xx] == '0'){
                    if (arr[i][j + 1][xx] == '1' && arr[i][j - 1][xx] == '1' && arr[i][j][xx + 1] == '1' && arr[i][j][xx - 1] == '1'){
                        mp2[j][xx]++;
                    }
                }
                else{
                    if (arr[i][j + 1][xx] == '0' && arr[i][j - 1][xx] == '0' && arr[i][j][xx + 1] == '0' && arr[i][j][xx - 1] == '0'){
                        mp2[j][xx]++;
                    }
                }
            }
        }
    }
    int curr=0;
    vi vis(k + 1, 0);
    forn(i, 0, k + 1){
        int d = 0;
        forn(j, 1, n - 1){
            forn(xx, 1, m - 1){
                if (!mp2[j][xx]) continue;
                if (arr[i][j][xx] == '0'){
                    if (arr[i][j + 1][xx] == '1' && arr[i][j - 1][xx] == '1' && arr[i][j][xx + 1] == '1' && arr[i][j][xx - 1] == '1'){
                        d = d;
                    }
                    else d++;
                }
                else{
                    if (arr[i][j + 1][xx] == '0' && arr[i][j - 1][xx] == '0' && arr[i][j][xx + 1] == '0' && arr[i][j][xx - 1] == '0'){
                        d = d;
                    }
                    else d++;
                }
            }
        }
        if (d == 0){
            curr = i;
            break;
        }
    }
    vis[curr] = 1;
    cout << curr + 1 << endl;
    vector<vi> res;
    int total=k;
    while(total){
        int d = inf, next = 0, x, y;
        forn(i, 0, k + 1){
            if (vis[i]) continue;
            int dd = 0;
            forn(j, 1, n - 1){
                forn(xx, 1, m - 1){
                    if (arr[curr][j][xx] != arr[i][j][xx]){
                        dd++; x = j; y = xx;
                    }
                }
            }
            if (dd < d){ d = dd; next = i; }
        }
        if (d>=1){
            res.pb({ 1,x + 1,y + 1 });
            arr[curr][x][y]=arr[next][x][y];
        }
        if(d>=2) continue;
        res.pb({ 2,next + 1 });
        curr = next;
        vis[curr] = 1;
        total--;
    }
    cout << res.size() << endl;
    for (auto it : res){
        for (auto itt : it) cout << itt << " ";
        cout << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}