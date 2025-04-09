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
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

vi vec1, vec2;

void solve(){
    int n, q;
    cin >> n >> q;
    while (q--){
        char a, b;
        cin >> a >> b;
        if (a == '<'){
            int val;
            cin >> val;
            // cout<<val<<endl;
            int row_s = 1, col_s = 1;
            while (val > 1){
                int idx = lower_bound(all(vec1), val) - vec1.begin() - 1;
                // cout<<" idx" <<idx<<" val " <<val<<endl;
                int bef = vec1[idx], diff = vec2[idx];
                // cout<<bef<<" "<<diff<<endl;
                if (val <= bef) continue; // do nothing
                else if (val <= 2LL * bef){
                    val -= bef;
                    row_s += diff;
                    col_s += diff;
                }
                else if (val <= 3LL * bef){
                    val -= 2 * bef;
                    row_s += diff;
                }
                else{
                    val -= 3 * bef;
                    col_s += diff;
                }
                // cout<<" dv "<<row_s<<" "<<col_s<<endl;
            }
            cout << row_s << " " << col_s << endl;
        }
        else{
            int row, col;
            cin >> row >> col;
            int val = 1;
            while ((row != 1 || col != 1)){
                int idx = lower_bound(all(vec2), max(row, col)) - vec2.begin() - 1;
                // cout << " idx" << idx << " val " << val << endl;
                int bef = vec1[idx], diff = vec2[idx];
                // cout << bef << " " << diff << endl;
                if (row <= diff && col <= diff) continue; // do nothing
                else if (row > diff && col > diff){
                    val += bef;
                    row -= diff;
                    col -= diff;
                }
                else if (row > diff && col <= diff){
                    val += 2 * bef;
                    row -= diff;
                }
                else{
                    val += 3 * bef;
                    col -= diff;
                }
                // cout << " dv " << row << " " << col << endl;
            }
            cout << val << endl;
        }
    }
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t = 1;
    cin >> t;
    int a = 1LL;
    int rows = 2LL;
    vec1.push_back(0LL);
    vec2.push_back(0LL);
    vec1.push_back(1LL);
    vec2.push_back(1LL);
    for (int i = 2LL;i <= 64LL;i += 2LL){
        a = a << 2;
        vec1.push_back(a);
        vec2.push_back(rows);
        rows *= 2LL;
    }
    while (t--){
        solve();
    }
    return 0;
}