/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-08 12:08 (GMT+5)

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
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    forn(i,0,n){
        int x; cin>>x; mp[x]++;
    }
    vector<pii> arr;
    for(auto it:mp){
        arr.pb(it);
    }
    int l=0,r=arr.size()-1;
    while(l<r){
        if(arr[l].ss<=arr[r].ss){
            int d=arr[l+1].f-arr[l].f;
            if(k>=d*arr[l].ss){
                arr[l+1].ss+=arr[l].ss;
                k-=d*arr[l].ss;
                l++;
            }
            else{
                int res=arr[r].f-arr[l].f;
                int ya=k/arr[l].ss;
                cout<<res-ya<<endl;
                return;
            }
        }
        else{
            int d=arr[r].f-arr[r-1].f;
            if(k>=d*arr[r].ss){
                arr[r-1].ss+=arr[r].ss;
                k-=d*arr[r].ss;
                r--;
            }
            else{
                int res=arr[r].f-arr[l].f;
                int ya=k/arr[r].ss;
                cout<<res-ya<<endl;
                return;
            }
        }
    }
    cout<<0<<endl;
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