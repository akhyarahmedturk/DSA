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
    int n,zeros=0;
    cin>>n;
    string str1,str2;
    cin>>str1>>str2;
    bool same=true,res=true;
    if(str1[0]!=str2[0]) same=false;
    if(str1[0]=='0') zeros++;
    forn(i,1,n){
        if(str1[i]==str2[i]){
            if(!same){
                if(2*zeros!=i){
                    res=false;
                    break;
                }
                same=!same;
            }
        }
        else{
            if(same){
                if(2*zeros!=i){
                    res=false;
                    break;
                }
                same=!same;
            }
        }
        if(str1[i]=='0') zeros++;
    }
    if(!same && 2*zeros!=n){
        res=false;
    }
    yesno(res);
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}