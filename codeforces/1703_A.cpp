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
    vector<vector<int>> grid(n,vector<int>(n));
    forn(i,0,n){
        forn(j,0,n){
            char ch;
            cin>>ch;
            grid[i][j]=ch-'0';
        }
    }
    int res=0;
    forn(i,0,n/2){
        // cout<<"i "<<i<<endl;
        forn(j,0,n-2*i-1){
            int curr=grid[i][i+j]+grid[i+j][n-i-1]+grid[n-i-1][n-i-j-1]+grid[n-i-j-1][i];
            // cout<<" j "<<j<<" curr "<<curr<<endl;
            res+=min(curr,4-curr);
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