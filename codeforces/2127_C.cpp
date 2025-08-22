/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-07 22:44 (GMT+5)

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

struct comp {
    bool operator()(const pii &a, const pii &b) const {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};


void solve() {
    int n,k; cin>>n>>k;
    vector<pii> vec(n);
    forn(i,0,n) cin>>vec[i].first;
    forn(i,0,n) { cin >> vec[i].second; if(vec[i].first>vec[i].second) swap(vec[i].first,vec[i].second); }
    sort(vec.begin(),vec.end(),comp());
    int res=LONG_LONG_MAX;
    int ans=0;
    bool overlap=false;
    forn(i,0,n){
        ans+=vec[i].second-vec[i].first; 
        if(i>0 && vec[i].first<=vec[i-1].second ) overlap=true;
    }
    if(overlap) {
        cout << ans << endl;
        return;
    }
    forn(i,1,n){
        res=min(res, ans+2*(vec[i].first-vec[i-1].second));
    }
    cout << res << endl;
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