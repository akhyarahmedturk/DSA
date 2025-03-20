#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
using ppp=pair<int,pair<int,int>>;

void solve(){
    int n, coins, res = 0,temp;
    cin >> n >> coins;
    vector<ppp> all_m(n);
    forn(i, 0, n){
        cin >> temp;
        all_m[i]={min(i + 1, n - i)+temp,{temp,i}};//min value, actual value, index
    }
    sort(all(all_m));// sorting based on min value
    vector<int> prefix(n); // prefix sum for binary searching
    prefix[0]=all_m[0].first; 
    forn(i, 1, n) {
        prefix[i]=prefix[i-1]+all_m[i].first;
    }
    forn(i, 0, n){
        if(all_m[i].second.first + all_m[i].second.second+1>coins) continue;  // if starting value is greater that total coins
        int off=all_m[i].second.first + all_m[i].second.second+1-all_m[i].first,curr; //how much more coins required from min_value to convert to starting cost ( can be zero if it was already from start)
        curr=coins-off; // current coins
        if(coins<prefix[i]+off) curr-=all_m[i].first; // if it can't be in our binary search ( mean binary search will always give less than i)
        auto lb=upper_bound(prefix.begin(),prefix.end(),curr); // upper bound
        temp=lb - prefix.begin(); // total values
        if(temp<i) temp++; //including current
        res=max(res,temp);
    }
    cout << res << endl;
}

int32_t main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}