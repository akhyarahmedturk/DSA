/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-22 16:39 (GMT+5)

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
    int n,m,q; cin>>n>>m>>q;
    vi arr1(n),arr2(m); input(arr1,n); input(arr2,m);
    sort(allr(arr1)); sort(allr(arr2));
    vi a(n+1,0),b(m+1,0);
    forn(i,1,n+1){ a[i]=a[i-1]+arr1[i-1];};
    forn(i,1,m+1){ b[i]=b[i-1]+arr2[i-1];};
    while(q--){
        int x,y,z; cin>>x>>y>>z;
        int l=max(0LL,z-y),r=min(x,z),res=0LL,mid;
        while(l<=r){
            int mid1=l+(r-l)/3,mid2=r-(r-l)/3;// learned ternary search 
            int m1=a[mid1]+b[max(0LL,z-mid1)],m2=a[mid2]+b[max(0LL,z-mid2)];
            if(m1>=m2){
                res=max(res,m1);
                r=mid2-1;
            }
            else{
                res=max(res,m2);
                l=mid1+1;
            } 
        }
        cout<<res<<endl;
    }
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