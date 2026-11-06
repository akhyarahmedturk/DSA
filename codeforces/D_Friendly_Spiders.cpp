/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-18 17:11 (GMT+5)

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
    vi arr(n); input(arr,n);
    vector<vi> ya(n);
    map<int,vi> mp;
    forn(i,0,n){
        if(arr[i]%2==0) mp[2].pb(i) , ya[i].pb(2);
        while(arr[i]%2==0) arr[i]/=2;
        for(int j=3;j*j<=arr[i];j+=2){
            if(arr[i]%j==0) mp[j].pb(i) , ya[i].pb(j);
            while(arr[i]%j==0) arr[i]/=j;
        }
        if(arr[i]>1) mp[arr[i]].pb(i) , ya[i].pb(arr[i]);
    }
    int s,t; cin>>s>>t; s-- , t--;
    if(s==t){ cout<<1<<nl<<s+1<<nl; return;}
    vi vis(n,0); vis[s]=1;
    map<int,int> primes; //visited
    queue<int> q; q.push(s);
    int res=1;
    while(!q.empty()){
        res++;
        int size=q.size();
        while(size--){
            int curr=q.front(); q.pop();
            for(auto it:ya[curr]){
                if(!primes[it]){
                    primes[it]=1;
                    for(auto itt:mp[it]){
                        if(!vis[itt]) vis[itt]=res , q.push(itt);
                    }
                }
            }
        }
        if(vis[t]) break;
    }
    if(!vis[t]){ cout<<-1<<endl; return; }
    vi ans;
    int curr=t;
    while(res){
        ans.pb(curr);
        int prv=-1;
        for(auto it:ya[curr]){
            for(auto itt:mp[it]){
                if(vis[itt]==vis[curr]-1) prv=itt;
            }
        }
        curr=prv;
        res--;
    }
    cout<<ans.size()<<endl;
    forr(i,ans.size()-1,0) cout<<ans[i]+1<<" ";
    cout<<nl;
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