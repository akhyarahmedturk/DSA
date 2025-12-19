/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-10-17 20:35 (GMT+5)

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
    int n,k; cin>>n>>k;
    set<int> st;
    forn(i,0,n) st.insert(i+1);
    vi arr(n); input(arr,n);
    forn(i,0,n){
        if(st.find(arr[i])!=st.end()) st.erase(arr[i]);
    }
    vi res(3,0);
    int size=st.size();
    if(size==0){
        res={arr[0],arr[1],arr[2]};
    }
    else if(size==1){
        res[0]=*st.begin();
        if(arr[n-1]==n) {
            if(res[0]==n-1) res[1]=n-2;
            else res[1]=n-1;
        }
        else if(res[0]==n){
            if(arr[n-1]==n-1) res[1]=n-2;
            else res[1]=n-1;
        }
        else res[1]=n;
        res[2]=arr[n-1];
    }
    else {
        auto ya=st.end();
        ya--;
        int val=*ya;
        res={*st.begin(),val,arr[n-1]};
    }
    forn(i,0,k) cout<<res[i%3]<<" ";
    cout<<endl;
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