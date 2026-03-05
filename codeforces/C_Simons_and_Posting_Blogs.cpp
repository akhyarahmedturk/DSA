/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-02-27 15:28 (GMT+5)

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
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
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
    int n; cin >> n;
    set<vi> st;
    forn(i, 0, n){
        int m; cin >> m;
        vi ya(m); input(ya, m);
        vi ya2;
        set<int> st2;
        forr(i, m - 1, 0){
            if (st2.find(ya[i]) == st2.end()){
                st2.insert(ya[i]); ya2.pb(ya[i]);
            }
        }
        st.insert(ya2);
    }
    vi mp(1e6 + 10, 0);
    vi res;
    while (!st.empty()){
        vi ya = *st.begin(); st.erase(st.begin());
        set<vi> st2;
        for (auto it : ya){
            if (!mp[it]) res.pb(it);
            mp[it] = 1;
        }
        for(auto it:st){
            vi ya;
            reverse(all(it));
            for(auto itt:it){
                if(!mp[itt]) ya.pb(itt);
            }
            if(ya.size()){
                reverse(all(ya)); st2.insert(ya);
            }
        }
        swap(st,st2);
    }
    for (auto it : res) cout << it << " ";
    cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}