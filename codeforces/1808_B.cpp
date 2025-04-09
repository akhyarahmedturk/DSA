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
const int inf = 1e17 + 1; // 1 3 7 8

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    int n,m,res=0;
    cin>>n>>m;
    vector<vector<int>> arr(m,vector<int> (n));
    forn(i,0,n){
        forn(j,0,m){
            cin>>arr[j][i];
        }
    }
    if(n==1){
        cout<<0<<endl;
        return;
    }
    forn(j,0,m){
        sort(all(arr[j]));
        int curr=arr[j][1]-arr[j][0];
        res+=curr;
        forn(i,2,n){
            curr+= (arr[j][i]-arr[j][i-1])*i;
            res+=curr;
        }
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