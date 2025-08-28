/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-27 19:49 (GMT+5)

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

void solve() {// not complete
    int n,k; cin>>n>>k;
    vi arr(n); input(arr,n);
    if(k&1){
        forn(i,0,n){
            if(arr[i]&1) cout<<arr[i]+k<<" ";
            else cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    else{
        int start=3;
        //arr[i]+x*k then arr[i]%start==0  x=???? or 
        //(arr[i]+x*k)=start*y      

        // while(k%start==0) start+=2;
        start=k-1;
        forn(i,0,n){
            while(arr[i]%start) arr[i]+=k;
            cout<<arr[i]<<" ";
        }
        cout<<endl;
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