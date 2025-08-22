/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-06 17:25 (GMT+5)

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

int binary_exp(int a, int b, int M){
    int ans = 1;
    while (b){
        if (b & 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}


void solve() {
    int n,m;
    cin>>n>>m;
    map<int,int> mp;
    forn(i,0,n){
        int a;
        cin>>a;
        mp[a]++;
    }
    vi v2(mp.size());
    int i=0;
    for(auto it:mp){
        v2[i]=it.first;
        i++;
    }
    int res=0,curr=1,count=1;
    if(m==1){
        count=1;
        res=mp[v2[0]];
    }
    vi p(v2.size());
    p[0]=mp[v2[0]];
    forn(i,1,v2.size()){
        p[i]=(p[i-1]*mp[v2[i]])%mod;
        if(v2[i]!=v2[i-1]+1) count=1; 
        else count++;
        if(count>=m){ 
            if(i==m-1) res=(res+p[i])%mod;
            else res = (res+(p[i]*binary_exp(p[i-m], mod - 2, mod)) % mod)%mod;// mod ky sath prfix multiplication ky liy
        }
    }
    cout<<res<<endl;
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