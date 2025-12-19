/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-06 19:50 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");

*    Those who can’t remember the past are condemned to repeat it.
*                                                 -Dynamic Programming.
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
#define INT_MAX LLONG_MAX

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    int n; cin>>n;
    vi arr(n);
    vi eve;
    forn(i,0,n){ cin>>arr[i]; if(arr[i]%2==0) eve.pb(arr[i]);}
    if(eve.size()>1){ cout<<eve[0]<<" "<<eve[1]<<endl;}
    else if(arr[0]==1){ cout<<1<<" "<<arr[1]<<endl;}
    else{
        //worst case 2,3,7,15,31,....growing by 2
        //so, max we need 64
        n=min(n,66LL);
        forn(i,0,n){
            forn(j,0,i){
                if((arr[i]%arr[j])%2==0) { cout<<arr[j]<<" "<<arr[i]<<endl; return;}
            }   
        }
        cout<<-1<<endl;
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