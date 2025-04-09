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
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    int n,k,x,groups=1,total=0;
    cin>>n>>k>>x;
    vi arr(n);
    input(arr,n);
    sort(all(arr));
    map<int,int> mp;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]>x) {
            total+=(arr[i]-arr[i-1]-1)/x;
            mp[(arr[i]-arr[i-1]-1)/x]++;
            groups++;
        }
    }
    if(k>=total) {
        cout<<1<<endl;
        return;
    }
    for(auto it:mp){
        if(k>it.first*it.second){
            groups-=it.second;
            k-=it.second*it.first;
        }
        else{
            groups-= k/it.first;
            break;
        }
    }
    cout<<max(1LL,groups);
 }

int32_t main(){
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}