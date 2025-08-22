/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-12 17:10 (GMT+5)

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
// #define ss second
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

int n, base, s;
string curr = "";
bool check(int num){
    vi arr;
    while (num){
        arr.pb(num % base);
        num /= base;
    }
    for (int i = 0;i < arr.size() / 2;i++){
        if (arr[i] != arr[arr.size() - 1 - i]) return false;
    }
    return true;
}

int ss(int size, int i){
    int res = 0;
    if (i == (size + 1) / 2){
        string temp = curr;
        if (i * 2 <= s){
            string temp2 = temp;
            reverse(all(temp2));
            int num = stoll(curr + temp2);
            if (num <= n && check(num)) res = num;
        }
        temp.pop_back();
        reverse(all(temp));
        int num = stoll(curr + temp);
        if (num <= n && check(num)) return res + num;
        return res;
    }
    char st = '0';
    if (i == 0) st = '1';
    while (st <= '9'){
        curr.pb(st);
        res += ss(size, i + 1);
        curr.pop_back();
        st++;
    }
    return res;
}

void solve(){
    int res = 0;
    cin >> base >> n;
    s = to_string(n).length();
    for (int i = 1; i <= s; i += 2){
        curr.clear();
        res += ss(i, 0);
    }
    cout << res << endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}