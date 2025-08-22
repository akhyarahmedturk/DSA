/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-01 12:47 (GMT+5)

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

int ask(vi& arr){
    cout << "? ";
    cout << arr.size() << " ";
    forn(i, 0, arr.size()) cout << arr[i] << " ";
    cout << endl;
    int x; cin >> x;
    return x;
}

void solve(){
    int n;
    cin >> n;
    vi arr(n);
    forn(i, 0, n) arr[i] = i + 1;
    int l, r;// opening and closing bracket find karo
    if (ask(arr)){
        int st = 1, e = n, ans=1, mid;
        while (st < e){
            mid = (st + e) / 2;
            vi arr(e-mid + 1);
            forn(i, 0, e - mid + 1) arr[i] = mid + i;
            if (ask(arr)){
                ans = mid;
                st = mid +1;
            }
            else e = mid;
        }
        l = ans; r = ans + 1;
    }
    else{ l = n; r = 1; }
    // Now we have at least 500 qurries so for every two index we can use 1 querry
    // if we send l?l?lr then
    // ))-> ()()() ans=6
    // ((-> ((((() ans=1
    // ()-> ((()() ans=3
    // )(-> ()((() ans=2
    vector<char> res(n);
    for (int i = 0;i < n - 1;i += 2){
        vi arr = { l,i + 1,l,i + 2,l,r };
        int r = ask(arr);
        if (r == 6){ res[i] = ')'; res[i + 1] = ')'; }
        else if (r == 1){ res[i] = '('; res[i + 1] = '('; }
        else if (r == 3){ res[i] = '('; res[i + 1] = ')'; }
        else{ res[i] = ')'; res[i + 1] = '('; }
    }
    if (n & 1){
        vi arr = { l,n - 1,l,n,l,r };
        int r = ask(arr);
        if (r == 6){ res[n - 2] = ')'; res[n - 1] = ')'; }
        else if (r == 1){ res[n - 2] = '('; res[n - 1] = '('; }
        else if (r == 3){ res[n - 2] = '('; res[n - 1] = ')'; }
        else{ res[n - 2] = ')'; res[n - 1] = '('; }
    }
    cout << "! ";
    forn(i, 0, n) cout << res[i];
    cout << endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}