/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-12 20:00 (GMT+5)

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
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve(){
    int n; cin >> n;
    vi ya(n + 1, 1);
    int rem = n;
    set<int> res;
    forn(i, 1, n + 1){ res.insert(i); }
    for (int i = 1;res.size() > 1;i *= 2LL){
        int c = 0, rem = res.size();
        vi ans(n + 1, 0);
        forn(j, 1, n){
            if (ya[j]){
                cout << "? " << j << " " << i << endl;
                int x; cin >> x;
                ans[j] = x;
                if (x) c++;
            }
        }
        set<int> st2;
        int cc = 0;
        for (auto it : res) cc += ((it & i) == i);
        if (c != cc){
            ya = ans;
            for (auto it : res){
                if (it & i) st2.insert(it);
            }
        }
        else{
            forn(j, 1, n){
                if (ya[j]) ya[j] = (!ans[j]);
            }
            for (auto it : res){
                if (!(it & i)) st2.insert(it);
            }
        }
        swap(res, st2);
        // for(auto it:res)cout<<it<<" ";
        // cout<<endl;
        // cout<<rem<<endl;
    }
    cout << "! " << *res.begin() << endl;
}
// 1 2 3 4 5 6 7 8 9 10 11 12
// n-1=7 querries-> know parity of every including nth remaining(n+1, 13)
// it can be 2,4,6,8,10,12
// &2=2 waly kitny? 3
//so, divide ho rahy by 2??

// 1 2 3 4 5 6 7 8 9
// 1 3 5 7 9
// 1 5 9

//1 3 4 5 6 7 2
//6 4 ,2
//
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}