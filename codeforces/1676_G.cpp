#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
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
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    int n,res=0;
    cin>>n;
    vi arr(n-1);
    input(arr,n-1);
    string str;
    cin>>str;
    vector<pii> mp(n+1,{0,0});
    if(str[0]=='W') mp[1].first++;
    else mp[1].second++;
    forr(i,n-2,0){
        if(str[i+1]=='W') mp[i+2].first++;
        else mp[i+2].second++;
        mp[arr[i]].first+=mp[i+2].first;
        mp[arr[i]].second+=mp[i+2].second;
    }
    forn(i,1,n+1){
        if(mp[i].first==mp[i].second) res++;
    }
    cout<<res<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}