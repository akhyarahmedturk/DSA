/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-14 13:24 (GMT+5)

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


void solve() {
    int n,c; cin>>n>>c;
    vi arr(n),prefix(n+1,0),res(n);
    int mx=0;
    forn(i,0,n){
        cin>>arr[i];
        if(i==0) arr[0]+=c;
        if(arr[i]>arr[mx]) mx=i;
    }
    res[mx]=0;
    forn(i,mx+1,n){
        res[i]=i;
    }
    int prv=0;
    forn(i,0,mx){
        prv+=arr[i];
        if(prv<arr[mx]) res[i]=i+1;
        else res[i]=i;
    }
    forn(i,0,n) cout<<res[i]<<" ";
    cout<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}