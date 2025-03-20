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
    vi a(n),b(n);
    int diff=-1;
    forn(i,0,n) cin>>a[i];
    forn(i,0,n) {
        cin>>b[i];
        if(b[i]!=a[i]) diff=i;
    }
    int l=diff,r=diff;
    while(l>0 && b[l]>=b[l-1]) l--;
    while(r<n-1 && b[r]<=b[r+1]) r++;
    cout<<l+1<<" "<<r+1<<endl;
}

int32_t main(){
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}