/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-10-04 19:28 (GMT+5)

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
    vi arr(n); input(arr,n);
    vector<pii> count(n+1,{0,0});
    vi prefix(n+1,0);//kini dafa 00 ya 11 hen
    forn(i,0,n){
        count[i+1]=count[i];
        if(arr[i]==0)count[i+1].first++;
        else count[i+1].second++;
        if(i) prefix[i+1]=prefix[i]+(arr[i]==arr[i-1]);
    }
    while(q--){
        int x,y; cin>>x>>y;
        if((y-x+1)%3 || (count[y].f-count[x-1].f)%3){ cout<<-1<<endl; continue;}
        int res=(y-x+1)/3;
        //x-1 nahi hoga q ky first element apny sath pechy waly ko check ar ky 1 add kar sakta
        if(prefix[y]-prefix[x]==0){// agar sary 01010101.. hen to first py 2 lagy ga
            cout<<res+1<<endl;
        }
        else cout<<res<<endl;
    }
}
//00 0 1 0 1 0 1

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
