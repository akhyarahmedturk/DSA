/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-04 14:02 (GMT+5)

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
#define vb vector<bool>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX
#define nl "\n"

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

// BIT Fenwick Tree

struct BIT{
    int n;
    vi bit;
    BIT(int nn){
        n = nn;
        bit.assign(n + 2, 0);
    }
    // Point update: add 'val' to index 'i'
    void update(int i, int val){ //bit[i]+=x;
        while (i <= n){
            bit[i] += val;
            i += i & -i;
        }
    }
    // Prefix sum: sum[1...i]
    int query(int i){
        int res = 0;
        while (i > 0){
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
};


void solve() {
    int n; cin>>n;
    vector<tuple<int,int,int,int>> mp; // x ,0/1/2  , y1,y2
    // 0-> verticle line x py
    // 1-> x sy horizental start
    // 2-> x py end
    BIT bit((1e6)*2+10);
    forn(i,0,n){
        int a,b,x,y; cin>>a>>b>>x>>y;
        x+=1e6+1; y+=1e6+1; a+=1e6+1; b+=1e6+1;
        if(a==x) {
            mp.pb({a,0,b,y});
        }
        else{
            mp.pb({a,1,b,y});
            mp.pb({x,2,b,y});
        }
    }
    sort(all(mp));
    int res=0,i=0;
    for(auto [x,t,y1,y2]:mp){
        if(t==0){
            res+=bit.query(y2)-bit.query(y1);
        }
        else if(t==1) bit.update(y1,1); 
        else bit.update(y1,-1);
    }
    cout<<res<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}