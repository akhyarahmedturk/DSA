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
double log_base(double a, double b) {
    return log(a) / log(b);
}
void solve() {
    int n;
    cin>>n;
    int i=2,res=0;
    while(1+i+i*i<=n){
        double m = log_base(n * (i - 1) + 1, i);
        m=round(m)+1;
        if(pow(i,m-1)==n*(i-1)+1){
            res=i;
            break;
        }
        i++;
    }
    yesno(res!=0);
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}