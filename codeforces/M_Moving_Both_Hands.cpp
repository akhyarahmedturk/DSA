/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-19 23:28 (GMT+5)

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
    vector<vector<pii>> in(n+1),out(n+1);
    forn(i,0,m){
        int a,b,c; cin>>a>>b>>c;
        out[a].pb({b,c});
        in[b].pb({a,c});
    }
    set<array<int,3>> q; q.insert({0,1,0}); // 0->seedha
    vi dp1(n+1,inf); dp1[1]=0; //in
    vi dp2(n+1,inf); dp2[1]=0; //out
    vi res(n+1,inf);
    while(!q.empty()){
        auto[dis,curr,dir]=*q.begin();
        q.erase(q.begin());
        res[curr]=min(dis,res[curr]);
        if(dir==0 && dp1[curr]<dis) continue;
        if(dir==1 && dp2[curr]<dis) continue;
        if(dir==0){
            for(auto it:out[curr]){
                if(dp1[it.f]>dp1[curr]+it.ss) dp1[it.f]=dp1[curr]+it.ss, q.insert({min(dp1[it.f],dp2[it.f]),it.f,0});
            }
        }
        for(auto it:in[curr]){
            if(dp2[it.f]>min(dp2[curr],dp1[curr])+it.ss) {
                dp2[it.f]=min(dp2[curr],dp1[curr])+it.ss, q.insert({min(dp2[curr],dp1[curr])+it.ss,it.f,1});
            }
        }
    }
    forn(i,2,n+1) cout<<(res[i]==inf?-1:res[i])<<" ";
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