/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-01 21:13 (GMT+5)

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
// #define mp make_pair
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
    int n;
    cin>>n;
    map<int,int> mp;
    vector<int> count;
    forn(i,0,n){
        int a;
        cin>>a;
        mp[a]++;
    }
    int mx=-1LL,rem=n,zyada=0;
    for(auto it:mp){
        // cout<<it.first<<" ";
        if(it.first-mx!=1) break;
        zyada+=it.second-1;
        rem-=it.second;
        mx++;
        count.pb(it.second);
    }
    mx+=2;
    sort(all(count));
    cout<<1<<" ";
    forn(i,1,n){
        int gr=count.end()-(upper_bound(all(count),i));
        cout<<max(1LL,mx-(max(0LL,i-(rem+zyada)))-gr)<<" ";
    }
    cout<<1<<endl;
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