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

void solve(){
    int res=0,p=0,r=0;
    string a;
    cin>>a;
    forn(i,0,a.length()){
        if(a[i]=='g'){
            if(p<r){
                p++;
                res++;
            }
            else r++;
        }
        else{
            if(p<r){
                p++;
            }
            else {
                res--;
                r++;
            }
        }
    }
    cout<<res<<endl;
}

int32_t main(){
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}