/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-06-19 11:02 (GMT+5)

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

// 2 3 1 4
// {1.4} ,{2,2} ,{3,1},{4,1}

int dfs(int idx,int curr,vector<vi> &divs,vector<map<int,int>> &dp){
    if(idx==divs.size()) return 1;
    if(dp[idx].find(curr)!=dp[idx].end()) return dp[idx][curr];
    int res=dfs(idx+1,curr,divs,dp);
    for(auto it:divs[idx]){
        if(curr%it==0) res+=dfs(idx+1,curr*)
    }
}

void solve() {
    int n; cin>>n;
    vector<vi> divs(n);
    forn(j,0,n){
        int x; cin>>x;
        if(x%2==0) divs[j].pb(2);
        while(x%2==0) x/=2;
        for(int i=3;i*i<=x;i+=2){
            if(x%i==0) divs[j].pb(i);
            while(x%i==0) x/=i;
        }
        if(x>1) divs[j].pb(x);
    }
    vector<map<int,int>> dp(n);
    cout<<dfs(0,1,divs,dp)<<endl;
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