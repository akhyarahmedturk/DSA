/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-10-06 20:19 (GMT+5)

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
    vi arr(n);
    forn(i,0,n) arr[i]=i+1;
    if(k==0){
        forn(i,0,n) cout<<i+1<<" ";
        cout<<endl;
        return;
    }
    // if(k<n-1){ cout<<0<<endl; return;}
    forn(i,2,n+1){
        for(int j=0; j+i<=(n-j)+1;j++){
            int curr=0;
            forn(k,0,j+i-1){
                curr+=max(0LL,n-max(k+1,j+1));
            }
            // cout<<"i "<<i<<" curr "<<curr<<endl;
            if(curr==k){
                int ya=j+1;
                forn(k,0,i) {arr[j+i-k-1]=ya;  ya++;}
                forn(k,0,n) cout<<arr[k]<<" ";
                cout<<endl; return;
            }
        } 
    }
    cout<<0<<endl;
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