/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-02 10:16 (GMT+5)

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
#define f first
#define ss second
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

vector<int> largestProperDivisors(int n) {
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n / 2; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            ans[j] = i;  // i is a divisor of j, and j increases => i gets larger
        }
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<int> res(n+1,-1);
    res[1]=1;
    for(int i=3;i<=n;i+=2){
        if(res[i]!=-1) continue;
        int prv=i;
        for(int j=3;i*j<=n;j+=2){
            if(res[i*j]==-1){
                res[prv]=j*i;
                prv=j*i;
            }
        }
        if(prv!=i || i*2>n) res[prv]=i;
        else{
            res[i*2]=i;
            res[i]=2*i;
        }
    }
   int prv=2;
    for(int j=4;j<=n;j+=2){
        if(res[j]==-1){
            res[prv]=j;
            prv=j;
        }
    }
    res[prv]=2;
    forn(i,1,n+1) cout<<res[i]<<" ";
    cout<<endl;
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