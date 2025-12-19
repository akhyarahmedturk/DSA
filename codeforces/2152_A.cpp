/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-10-04 19:17 (GMT+5)

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
    int n,q; cin>>n>>q;
    map<int,int> mp;
    int curr=2;
    while(curr<1e9+10){ mp[curr+1]=1; curr*=2;}
    vi prefix(n+1,0);
    vi init(n+1,0);
    forn(i,0,n){
        int x; cin>>x;
        prefix[i+1]=prefix[i];
        init[i+1]=init[i];
        if(mp.find(x)!=mp.end()) init[i+1]++;
        while(x>1){
            if(mp.find(x)!=mp.end()) prefix[i+1]++;
            prefix[i+1]++; x/=2;
        }
    }
    while(q--){
        int x,y; cin>>x>>y;
        if(init[y]-init[x-1]==0) cout<<prefix[y]-prefix[x-1]<<endl;
        else if(init[y]-init[x-1]==1) cout<<prefix[y]-prefix[x-1]-1<<endl;
        else cout<<prefix[y]-prefix[x-1]-(init[y]-init[x-1])+1<<endl;
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
// 2 3 3 4 4 5 8 9 9
// 3->+1
// 5->+1
// 9->+1
// 17->
// 33
// ..