/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-29 08:53 (GMT+5)

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


void DFS(int idx, vi& bin, vi& res){
    if (idx == bin.size() - 1){
        res.pb(bin[idx]);
    }
    else{
        if (bin[idx + 1] == 1){
            res.pb(bin[idx]);

            DFS(idx + 1, bin,res);
        }
        else{
            DFS(idx + 1, bin,res);
            res.pb(bin[idx]);

        }
    }
}

void solve(){
    int n;
    cin >> n ;
    vector<int> bin,res;
    while (n){
        bin.pb(n % 2);
        n /= 2;
    }
    reverse(all(bin));
    DFS(0,bin,res);
    int rr=0;
    reverse(all(res));
    for(int i=0;i<res.size();i++){
        if( res[i]) rr+=(1LL<<(i));
    }
    cout<<rr<<endl;
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