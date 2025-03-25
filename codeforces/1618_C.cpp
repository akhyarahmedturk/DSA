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

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void solve() {
    int n,gcd1,gcd2,res=0;
    cin>>n;
    vi arr(n);
    cin>>gcd1>>gcd2;
    arr[0]=gcd1;
    arr[1]=gcd2;
    forn(i,2,n){
        cin>>arr[i];
        if(i%2==0) gcd1=gcd(gcd1,arr[i]);
        else gcd2=gcd(gcd2,arr[i]);
    }
    // cout<<gcd1<<"sdv"<<gcd2<<endl;
    if(gcd1!=1 && gcd1!=gcd2){
        for(int i=1;i<n;i+=2){
            if(arr[i]%gcd1==0){
                // cout<<" w "<<i<<endl;
                gcd1=0;
                break;
            }
        }
        res=gcd1;
    }
    if(gcd2!=1 && gcd1!=gcd2){
        for(int i=0;i<n;i+=2){
            if(arr[i]%gcd2==0){
                // cout<<" f "<<i<<endl;
                gcd2=0;
                break;
            }
        }
        res=max(res,gcd2);
    }
    cout<<res<<endl;
}

int32_t main(){
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}