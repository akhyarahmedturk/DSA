/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-15 14:04 (GMT+5)

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
    int a,b,x,y,k,res=0;
    cin>>k>>a>>b>>x>>y;
    if(k<a && k<b){ cout<<0<<endl; return;}
    else if(k>=a && k<b){
        cout<<(k-a)/x+1<<endl;
    }
    else if(k>=b && k<a){
        cout<<(k-b)/y+1<<endl;
    }
    else if(x<=y){
        res+=(k-a)/x+1;
        k-=res*x;
        if(k>=b) res+=(k-b)/y+1;
        cout<<res<<endl;
    }
    else {
        res+=(k-b)/y+1;
        k-=res*y;
        if(k>=a) res+=(k-a)/x+1;
        cout<<res<<endl;
    }
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