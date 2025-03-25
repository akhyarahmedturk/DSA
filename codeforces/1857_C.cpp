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
    map<int,int> mp;
    forn(i,0,(n*(n-1))/2){
        int x;
        cin>>x;
        mp[x]++;
    }
    int i=0,last;
    for(auto it:mp){
        int size=it.second;
        last=it.first;
        while(size){
            cout<<it.first<<" ";
            size-=(n-i-1);
            i++;
        }
    }
    cout<<last<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}