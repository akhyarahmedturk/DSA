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
    int n,q;
    cin>>n>>q;
    vector<int> mp(51,-1);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(mp[temp]==-1) mp[temp]=i+1;
    }
    while(q--){
        int temp;
        cin>>temp;
        int ttemp=mp[temp];
        for(int i=0;i<51;i++){
            if(mp[i]<ttemp) mp[i]++;
        }
        mp[temp]=1;
        cout<<ttemp<<" ";
    }
    cout<<endl;
}

int32_t main(){
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}