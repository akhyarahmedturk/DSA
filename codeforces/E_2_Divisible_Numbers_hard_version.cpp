/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-10 22:52 (GMT+5)

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

int a,b,c,d,res; 

bool dfs(int idx,int val,vector<set<int>> &dp,vi &ya){
    if(idx==-1){
        int val2=res/val;
        int d1=(a+1+val-1)/val,d2=(b+1+val2-1)/val2;
        d1*=val; d2*=val2;
        if(d1>a && d1<=c && d2>b && d2<=d) { cout<<d1<<" "<<d2<<endl; return true;}
        d1=(a+1+val2-1)/val2,d2=(b+1+val-1)/val;
        d1*=val2; d2*=val;
        if(d1>a && d1<=c && d2>b && d2<=d) { cout<<d1<<" "<<d2<<endl; return true;}
        return false;
    }
    if(dp[idx].find(val)!=dp[idx].end()) return false;
    dp[idx].insert(val);
    return dfs(idx-1,val,dp,ya) || dfs(idx-1,val*ya[idx],dp,ya);
}

void solve() {
    cin>>a>>b>>c>>d;
    res=a*b;
    vi ya;
    int temp=a;
    while(temp%2==0) ya.pb(2) , temp/=2;
    for(int i=3;i*i<=temp;i+=2){
        while(temp%i==0) ya.pb(i) , temp/=i;
    }
    if(temp>1) ya.pb(temp);
    temp=b;
    while(temp%2==0) ya.pb(2) , temp/=2;
    for(int i=3;i*i<=temp;i+=2){
        while(temp%i==0) ya.pb(i) , temp/=i;
    }
    if(temp>1) ya.pb(temp);
    int n=ya.size();
    vector<set<int>> dp(n+1);
    if(!dfs(n-1,1,dp,ya)){ cout<<"-1 -1"<<endl;}
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