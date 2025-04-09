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
    string a,b;
    int zeros=0,n;
    cin>>n;
    cin>>a>>b;
    int odd1=0,even1=0,odd2=0,even2=0;
    for(int i=0;i<n;i+=2){
        if(a[i]=='1') even1++;
        else zeros++;
        if(b[i]=='0') {
            even2++;
            zeros++;
        }
    }
    for(int i=1;i<n;i+=2){
        if(a[i]=='1') odd1++;
        else zeros++;
        if(b[i]=='0') {
            odd2++;
            zeros++;
        }
    }
    yesno(zeros>=n && even1<=odd2 && odd1<=even2);
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}