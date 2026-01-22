/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-20 20:59 (GMT+5)

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
    // int n=s.length();
    // vi dp(n+1,0); dp[n]=1;
    // forr(i,n-1,0){
    //     if(s[i]=='0') dp[i]=0;
    //     else if(s[i]=='1' && i!=n-1){
    //         dp[i]=dp[i+1]+dp[i+2];
    //     }
    //     else if(s[i]=='2' && i!=n-1 && s[i+1]<='6'){
    //         dp[i]=dp[i+1]+dp[i+2];
    //     }
    //     else{
    //         dp[i]=dp[i+1];
    //     }
    // }
    // cout<<dp[0]<<endl;
    int n; cin>>n;
    string s; cin>>s;
    bool check=false;
    cout<<"1 ";
    forn(i,1,n-1){
        if(s[i]!=s[0]) check=true;
        if(check) cout<<i+1<<" ";
        else cout<<"1 ";
    }
    cout<<endl;
}

// 001

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    // string s; cin>>s;
    // while(s!="0"){
    //     solve(s);
    //     cin>>s;
    // }
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}