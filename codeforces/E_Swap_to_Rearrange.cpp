/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-03-03 13:57 (GMT+5)

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
    int n; cin>>n;
    vi a(n),b(n); input(a,n); input(b,n);
    vector<set<int>> g1(n+1),g2(n+1);
    vi mp(n+1,0);
    vi vis(n,0);
    forn(i,0,n){
        if(a[i]==b[i]) {
            vis[i]=1;
            continue;
        }
        mp[a[i]]++;
        mp[b[i]]++;
        g1[a[i]].insert(i);
        g2[b[i]].insert(i);
    }
    forn(i,1,n+1){
        // euler cycle
        if(mp[i]%2){ cout<<-1<<endl; return;}
    }
    vi res;
    forn(i,0,n){
        if(vis[i]) continue;
        int curr=i;
        g1[a[curr]].erase(curr);
        g2[b[curr]].erase(curr);
        vis[curr]=1;
        // run karo jab tak circle complete na ho
        // agar a me nahi milta to reverse karo
        while(b[curr]!=a[i]){
            bool ya=false;
            if(!g1[b[curr]].empty())  curr=*g1[b[curr]].begin();
            else if(!g2[b[curr]].empty()){
                ya=true;
                curr=*g2[b[curr]].begin();
            }
            else {cout<<-1<<endl; return;}
            g1[a[curr]].erase(curr);
            g2[b[curr]].erase(curr);
            vis[curr]=1;
            if(ya){ res.pb(curr+1); swap(a[curr],b[curr]);}
            // cout<<curr<<" ";
        }
    }
    sort(all(res));
    cout<<res.size()<<endl;
    for(auto it:res) cout<<it<<" ";
    cout<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}