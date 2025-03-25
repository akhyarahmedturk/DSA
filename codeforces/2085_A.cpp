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
    int n,k;
    cin>>n>>k;
    string str,str2;
    cin>>str;
    str2=str;
    set<char> st;
    for(char it:str){
        st.insert(it);
    }
    reverse(all(str2));
    if(str<str2){
        yesno(true);
    }
    else if(st.size()==1 || k==0){
        yesno(false);
    }
    else{
        yesno(true);
    }
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}