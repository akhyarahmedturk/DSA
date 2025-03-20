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
#define all(a) a.begin(), a.end()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)


int binary_exp(int a,int b,int M){
    int ans=1;
    while(b){
        if(b&1) ans=(ans*a)%M;
        a = (a*a)%M;
        b>>=1;
    }
    return ans;
}


void solve() {
    int a,b;
    cin>>a>>b;
    cout<<a<<"^"<<b<<" = "<<binary_exp(a,b,mod)<<endl;
}

int32_t main(){
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}