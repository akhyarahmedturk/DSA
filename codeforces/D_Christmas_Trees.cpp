/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-07 22:17 (GMT+5)

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

void solve() {
    int n,m; cin>>n>>m;
    set<pii> left,right;
    set<int> vis;
    forn(i,0,n){
        int x; cin>>x;
        vis.insert(x);
        left.insert({1,x-1});
        right.insert({1,x+1});
    }
    vi res;
    int sum=0;
    while(res.size()<m){
        pii ya1=*left.begin();
        pii ya2=*right.begin();
        if(vis.find(ya1.ss)!=vis.end()){  left.erase(left.begin()); continue; }
        if(vis.find(ya2.ss)!=vis.end()){  right.erase(right.begin()); continue; }
        if(ya1.f<=ya2.f){
            res.pb(ya1.ss); sum+=ya1.f;
            vis.insert(ya1.ss);
            left.erase(left.begin());
            left.insert({ya1.f+1,ya1.ss-1});
        }
        else {
            res.pb(ya2.ss); sum+=ya2.f;
            vis.insert(ya2.ss);
            right.erase(right.begin());
            right.insert({ya2.f+1,ya2.ss+1});
        }
    }
    cout<<sum<<endl;
    for(auto it:res) cout<<it<<" ";
    cout<<endl;
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