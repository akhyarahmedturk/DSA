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

void solve() {
    int n;
    cin>>n;
    vector<pii> arr(n);
    forn(i,0,n) cin>>arr[i].first>>arr[i].second;
    sort(all(arr));
    int curr_max=1000;
    forn(i,0,n){
        if(arr[i].first>=curr_max) break;
        else{
            curr_max=min(curr_max,arr[i].first + (arr[i].second-1)/2);
        }
    }
    cout<<curr_max<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}