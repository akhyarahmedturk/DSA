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
    string str;
    cin>>str;
    str+=str.substr(0,str.length()-1);
    int ones=0,max_ones=0;//max consective ones
    for(int i=0;i<str.length();i++){
        if(str[i]=='0'){
            max_ones=max(max_ones,ones);
            ones=0;
        }
        else ones++;
    }
    max_ones=max(max_ones,ones)+1;
    cout<<((max_ones)/2) * (max_ones-(max_ones)/2)<<endl;
}

int32_t main(){
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}