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
    int n,neg=0,mmin=LLONG_MAX,sum=0;
    cin>>n;
    forn(i,0,n){
        int x;
        cin>>x;
        if(x<0){
            neg++;
        }
        sum+= abs(x);
        mmin=min(mmin,abs(x));
    }
    if(neg%2!=0){
        sum-=2LL*mmin;
    }
    cout<<sum<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}