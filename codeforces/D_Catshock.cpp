/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-22 17:18 (GMT+5)

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

void dfs(int idx,int p,int curr,vector<set<int>> &graph,vi &odd,vi &eve){
    for(auto it:graph[idx]){
        if(it==p) continue;
        dfs(it,idx,curr+1,graph,odd,eve);
    }
    if(idx!=graph.size()-1 && graph[idx].size()==1){
        if(curr&1) odd.pb(idx);
        else eve.pb(idx);
    }
}

void solve() {
    int n; cin>>n;
    vector<set<int>> graph(n);
    forn(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    //At any time hum sirf leaf ko destroy kar sakty
    // even time py odd ko,and odd time py even ko
    vi odd,eve;
    dfs(0,-1,0,graph,odd,eve);
    vector<pii> res;
    int curr=0,rem=n;
    while(rem>1){
        if(curr&1){
            if(eve.size()!=0){
                rem--;
                int c=eve.back(); eve.pop_back();
                res.pb({2,c+1});
                int next=*graph[c].begin();
                graph[next].erase(c);
                if(graph[next].size()==1 && next!=n-1) odd.pb(next);//current even tha to ngbr odd hoga
            }
        }
        else{
            if(odd.size()!=0){
                rem--;
                int c=odd.back(); odd.pop_back();
                res.pb({2,c+1});
                int next=*graph[c].begin();
                graph[next].erase(c);
                if(graph[next].size()==1 && next!=n-1) eve.pb(next);
            }
        }
        res.pb({1,1});
        curr=(curr+1)%2;
    }
    cout<<res.size()<<endl;
    for(auto it:res){
        if(it.f==1) cout<<1<<endl;
        else cout<<2<<" "<<it.ss<<endl;
    }
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