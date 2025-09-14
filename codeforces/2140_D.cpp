/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-13 11:20 (GMT+5)

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
    vector<pii> arr(n);
    int res=0;
    forn(i,0,n){
        int a,b; cin>>a>>b;
        res+=(b-a);
        res-=a;
        arr[i]={a,b};
    }
    sort(all(arr),[&](pii&a,pii&b){
        return a.f+a.ss>b.f+b.ss;
    });
    int ya=0;
    forn(i,0,n/2) ya+=arr[i].f+arr[i].ss;
    if(n&1) {
        int mx=0;
        forn(i,0,n) { 
            if(i<n/2){
                mx=max(mx,ya-arr[i].ss+arr[n/2].f+arr[n/2].ss);
            }
            else mx=max(mx,ya+arr[i].f);
        }
        res+=mx;
    }
    else res+=ya;
    cout<<res<<endl;
}

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