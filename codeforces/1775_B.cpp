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
    int n;
    cin>>n;
    map<int,int> mp;
    vector<vi> arr(n);
    forn(i,0,n){
        int a;
        cin>>a;
        vi temp(a);
        for(int j=0;j<a;j++){
            cin>>temp[j];
            mp[temp[j]]++;
        }
        arr[i]=temp;
    }
    forn(i,0,n){
        int j=0;
        for(;j<arr[i].size();j++){
            if(mp[arr[i][j]]==1) break;
        }
        if(j==arr[i].size()){
            yesno(true);
            return;
        }
    }
    yesno(false);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}