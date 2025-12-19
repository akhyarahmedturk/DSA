/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-14 19:23 (GMT+5)

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

void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n);
    int sum=0;
    forn(i,0,n) sum+=arr[i];
    int mm=0,mx=sum;
    int curr=0;
    forn(i,0,n){
        int b=curr-(i+1)*(i);//-prefix[r-1]+(r^2-r).
        mm=max(mm,b);
        curr+=arr[i];
        int ya=-1LL*curr+(i+1)*(i+2);//-prefix[r]+(r^2-r).
        mx=max(mx,ya+mm+sum);
    }
    cout<<mx<<endl;
}

// mx=sum-(prefix[r]-prefix[l-1])+(l+r)*(r-l+1)
// mx=prefix[n]-prefix[r]+prefix[l-1] + l*r-l*l+l+r*r-l*r+r
// mx=prefix[n]-prefix[r]+prefix[l-1] + r^2-l^2+(l+r)
// mx=sum-prefix[r]+prefix[l-1] + (r^2+r)-(l^2-l)
// mx=sum + (-prefix[r] + r(r+1) ) + (prefix[l-1] - l(l-1))
int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}