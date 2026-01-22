/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-26 23:04 (GMT+5)

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

void dfs1(int idx,int p,vector<vi> &graph,vector<vi> &dp){//down dp
    for(auto it:graph[idx]){
        if(it==p) continue;
        dfs1(it,idx,graph,dp);
        dp[idx][0]+=(1+dp[it][0]+dp[it][1]+dp[it][2]*2); 
        dp[idx][1]+=1+dp[it][1]+dp[it][2]*2; 
        dp[idx][2]+=dp[it][2]+1; 
    }
}

void dfs2(int idx,int p,vi curr,vector<vi> &graph,vector<vi> &dp,vi &res){
    //curr is jo uper sy aa rha
    if(p!=-1){
        curr[0]=(1+curr[0]+curr[1]+curr[2]*2); 
        curr[1]=1+curr[1]+curr[2]*2; 
        curr[2]=curr[2]+1;
    }
    // cout<<" idx "<<idx<<" "<<curr[0]<<" "<<curr[1]<<" "<<curr[2]<<" "<<endl; 
    res[idx]=curr[0]+dp[idx][0];
    for(auto it:graph[idx]){
        if(it==p) continue;
        curr[0]+=(1+dp[it][0]+dp[it][1]+dp[it][2]*2); 
        curr[1]+=1+dp[it][1]+dp[it][2]*2; 
        curr[2]+=dp[it][2]+1; 
    }
    for(auto it:graph[idx]){
        if(it==p) continue;
        //y wali branch ka exclude karo
        curr[0]-=(1+dp[it][0]+dp[it][1]+dp[it][2]*2); 
        curr[1]-=1+dp[it][1]+dp[it][2]*2;
        curr[2]-=dp[it][2]+1;
        dfs2(it,idx,curr,graph,dp,res);
        curr[0]+=(1+dp[it][0]+dp[it][1]+dp[it][2]*2); 
        curr[1]+=1+dp[it][1]+dp[it][2]*2;
        curr[2]+=dp[it][2]+1;
    }
}

void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n);
    vector<vi> graph(n);
    forn(i,0,n-1){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vector<vi> dp(n,{0,0,0});//subtree sum, diff,count
    vi curr={0,0,0};
    dfs1(0,-1,graph,dp);
    vi res(n);
    dfs2(0,-1,curr,graph,dp,res);
    int sum=0;
    for(auto it:arr) sum+=it*it;
    // for(auto it:dp){
    //     for(auto itt:it) cout<<itt<<" ";
    //     cout<<endl;
    // }
    cout<<sum-*max_element(all(res))<<endl;
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