/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-16 17:19 (GMT+5)

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
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    vector<pii> arr(n);
    forn(i,0,n) cin>>arr[i].first>>arr[i].second;
    a--; b--; k--;
    int res=LONG_LONG_MAX;
    if(a<=k){
        if(b<=k) res=0;
        else{
            forn(i,0,k+1){
                res=min(res,abs(arr[i].first-arr[b].first)+abs(arr[i].second-arr[b].second));
            }
        }
    }
    else if(b<=k){
        forn(i,0,k+1){
            res=min(res,abs(arr[i].first-arr[a].first)+abs(arr[i].second-arr[a].second));
        }
    }
    else{
        res=abs(arr[a].first-arr[b].first)+abs(arr[a].second-arr[b].second);
        int l=1e17,m=1e17;
        forn(i,0,k+1){
            l=min(l,abs(arr[i].first-arr[a].first)+abs(arr[i].second-arr[a].second));
        }
        forn(i,0,k+1){
            m=min(m,abs(arr[i].first-arr[b].first)+abs(arr[i].second-arr[b].second));
        }
        res=min(res,l+m);
    }
    cout<<res<<endl;
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