/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-16 20:57 (GMT+5)

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
    int n,khali; cin>>n>>khali;
    set<vi> st;
    vector<vi> arr(n,vi(3)); 
    forn(i,0,n) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    int prv=0;
    forn(i,0,n){
        int start=max(prv,arr[i][0]);
        while(khali<arr[i][2]){
            khali+=(*st.begin())[2];
            start=max(start,(*st.begin())[0]);
            st.erase(st.begin());
        }
        cout<<start<<endl;
        st.insert({start+arr[i][1],start,arr[i][2]});
        khali-=arr[i][2];
        prv=start;
    }
    cout<<endl;
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