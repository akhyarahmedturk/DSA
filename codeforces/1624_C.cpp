/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-25 17:12 (GMT+5)

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
    int n; cin>>n;
    string s; cin>>s;
    int l=0,r=n-1;
    vi a,b;
    forn(i,0,n){ (s[i]=='a')? a.pb(i):b.pb(i);}
    if(a.size()<=1 || b.size()<=1){ cout<<0<<endl; return;}
    int res=0,r2=0,s1=a.size(),s2=b.size();
    int m1=a[a.size()/2],m2=b[b.size()/2];
    forn(i,0,a.size()) res+=abs(a[i]-m1)-abs(s1/2-i);
    forn(i,0,b.size()) r2+=abs(b[i]-m2)-abs(s2/2-i);
    cout<<min(res,r2)<<endl;
}
// 1 2 5 15

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// b b b a