/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-22 10:23 (GMT+5)

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
map<int,pii> mp,prefix;// sum,count by digits

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve(vector<pii> &ya) {// ??????????????
    int n; cin>>n;
    int i=1;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    vector<pii> ya;
    ya.pb({10,45});
    int count=9,nums=9,sum=45;
    forn(i,2,13){
        ya.pb({ya.back().f*10*i,ya.back().ss*9});
        count*=10; nums+=(ya.back().f); sum+=ya.back().ss;
        cout<<count<<" "<<nums<<" "<<sum<<endl;
    }
    int t=1;
    cin >> t;
    while (t--) {
        solve(ya);
    }
    return 0;
}