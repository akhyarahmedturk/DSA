/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-24 21:56 (GMT+5)

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
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

int ans=INT_MAX;

void DFS(int idx,int mm,int mx,vector<vector<pair<int,int>>> &graph,vi &arr){
    if(idx==graph.size()-1){
        ans=min(ans,mm);
        return;
    }
    mx+=arr[idx];
    forn(i,0,graph[idx].size()){
        int u=graph[idx][i].first,d=graph[idx][i].second;
        if(d<=mx){
            DFS(u,max(mm,d),mx,graph,arr);
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    vi arr(n);
    input(arr,n);
    // ans=INT_MAX;
    vi indeg(n,0);
    vector<vector<pair<int,int>>> graph(n);
    vector<vector<pair<int,int>>> graph2(n);
    forn(i,0,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    vi dp(n,-1);
    dp[0]=0;
    forn(i,0,n-1){
        if(dp[i]==-1) continue;
        dp[i]+=arr[i];
        forn(j,0,graph[i].size()){
            if(dp[i]>=graph[i][j].second){
                dp[graph[i][j].first]=max(dp[graph[i][j].first],dp[i]);
            }
        }
    }
    if(dp[n-1]==-1) { cout<<-1<<endl; return;}
    int start=0,end=dp[n-1],ans=0,mid;
    while(start<=end){
        int mid=(start+end)/2;
        vi dp(n,-1);
        dp[0]=0;
        forn(i,0,n-1){
            if(dp[i]==-1) continue;
            dp[i]=min(dp[i]+arr[i],mid);
            forn(j,0,graph[i].size()){
                if(dp[i]>=graph[i][j].second){
                    dp[graph[i][j].first]=max(dp[graph[i][j].first],dp[i]);
                }
            }
        }
        if(dp[n-1]!=-1){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    cout<<ans<<endl;
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