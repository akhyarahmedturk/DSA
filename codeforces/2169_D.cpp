/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-14 20:46 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");

*    Those who can't remember the past are condemned to repeat it.
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
    int x,y,k; cin>>x>>y>>k;
    if(k<y) {cout<<k<<endl; return;}
    // else if((1e12-(y-1))<x*y) { cout<<-1<<endl; return;}
    //BS
    int l=1,r=1e12,mid,ans=-1;
    while(l<=r){
        mid=(l+r)/2;
        // cout<<mid<<endl;
        int curr=mid;
        forn(i,0,x){
            curr=curr-curr/y;
            if(curr<y) break;
        }
        if(curr<k) {l=mid+1;}
        else { ans=mid; r=mid-1;}
    }
    cout<<ans<<endl;
}


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1,x,y;
    cin >> t>>x>>y;
    // while (t--) {
    //     solve();
    // }
    forn(i,0,x){
        cout<<t/y<<endl;
        if(t<y) break;
        t-=t/y;
    }
    return 0;
}