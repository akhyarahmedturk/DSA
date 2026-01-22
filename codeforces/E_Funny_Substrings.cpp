/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-29 22:52 (GMT+5)

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
// #define int long long
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
    map<string, pair<pair<string, string>, int>> mp;
    string res = "";
    while (n--){
        string a, b, c, d, e; cin >> a >> b;
        string start="", end="";
        int curr = 0;
        // cout<<"a" <<a<<endl;
        if (b == ":="){
            cin >> c;
            if (c.length() >= 4) curr += (c.substr(0, 4) == "haha");
            if (c.length() >= 5) curr += (c.substr(1, 4) == "haha");
            start = c; end = c;
        }
        else{
            cin >> c >> d >> e;
            string ya = mp[c].f.ss + mp[e].f.f;
            // cout << a << " " << b << " " << c << " " << d << " " << e << " " << ya << endl;
            curr = mp[c].ss + mp[e].ss;
            forn(i, 0, ya.length() - 3){
                if(ya.substr(i, 4) == "haha") curr++;
            }
            start = mp[c].f.f, end = mp[e].f.ss;
            if (start.length() < 3) start = start + mp[e].f.f;
            if (end.length() < 3) end = mp[c].f.ss + end;
        }
        // cout << start << " " << end << " " << curr << endl;
        while(start.length()>3) start.pop_back();
        reverse(all(end));
        while(end.length()>3) end.pop_back();
        reverse(all(end));
        mp[a] = { {start,end},curr };
        res = a;
    }
    cout << mp[res].ss << endl;
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