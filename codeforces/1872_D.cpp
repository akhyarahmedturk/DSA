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
#define input(vec, n) for(int i = 0; i < (n); i++) cin >> vec[i];
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)

int gcd(int a,int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve(){
    int x,y,n;
    cin>>n>>x>>y;
    int lc=(x / gcd(x, y)) * y;//lcm
    int pos= n/x - n/lc;
    int neg= n/y - n/lc;
    int res= (n*(n+1))/2 - ((n-pos)*(n-pos+1))/2 - (neg*(neg+1))/2;
    cout<<res<<endl;
}

int32_t main(){
    int t = 1;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}