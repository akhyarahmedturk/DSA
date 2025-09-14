/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-13 12:01 (GMT+5)

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
    int curr=1;
    while(1){
        int t=(n+curr)/(curr*2);
        if(k>t) k-=t;
        else{
            cout<<curr+(k-1)*(curr*2)<<endl;
            return;
        }
        curr*=2;
    }
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin >> t;
    // vi arr(2e5+10,0);
    // forn(i,1,arr.size()){
    //     arr[i]=arr[i-1];
    //     int c=0,ii=i;
    //     while(ii){ c+=ii%10; ii/=10;};
    //     arr[i]+=c;
    // }
    while (t--) {
        solve();
    }
    return 0;
}

// 1 3 5 7 9 11 13 15 17 19 diff=2
// 2 6 10 14 18 ////22 26 30 34 38 42... diff==4
// 4 12 20 28 36 44 diff==8 
// 8 24                         