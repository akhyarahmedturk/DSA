/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-11 12:51 (GMT+5)

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

struct BIT {
    int n;
    vi bit;
    BIT(int nn) {
        n = nn;
        bit.assign(n + 2, 0);
    }
    // Point update: add 'val' to index 'i'
    void update(int i,int val) { //bit[i]+=x;
        while (i <= n) {
            bit[i]+=val;
            i += i & -i;
        }
    }
    // Prefix sum: sum[1...i]
    int query(int i) {
        int res=0;
        while (i > 0) {
            res+=bit[i];
            i -= i & -i;
        }
        return res;
    }
};

void solve() {
    int n,k; cin>>n>>k;
    vi arr(n); 
    set<int> st;
    vector<pair<char,pii>> ya(k);
    forn(i,0,n) {
        cin>>arr[i];
        st.insert(arr[i]);
    }
    forn(i,0,k){
        cin>>ya[i].f>>ya[i].ss.f>>ya[i].ss.ss;
        st.insert(ya[i].ss.ss);
    }
    vi mp(all(st));
    int nn=st.size()+2;
    BIT bit(nn);
    forn(i,0,n){
        int prv=(lower_bound(all(mp),arr[i]) - mp.begin()) + 1;
        bit.update(prv,1);
    }
    forn(i,0,k){
        if(ya[i].f=='!'){
            int prv=(lower_bound(all(mp),arr[ya[i].ss.f-1]) - mp.begin()) +1;
            int curr=(lower_bound(all(mp),ya[i].ss.ss) - mp.begin())+1;
            bit.update(prv,-1);
            bit.update(curr,1);
            arr[ya[i].ss.f-1] = ya[i].ss.ss;
        }
        else{
            int prv=(lower_bound(all(mp),ya[i].ss.f) - mp.begin()) + 1;
            int curr=(lower_bound(all(mp),ya[i].ss.ss) - mp.begin())+ 1;
            int res=bit.query(curr)-bit.query(prv-1);
            cout<<res<<endl;
        }
    }
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}