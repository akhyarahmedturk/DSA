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
    int n=str.length();
    set<char> st;
    map<char,int> mp1,mp2;
    forn(i,0,n) mp1[str[i]]++;
    int i=0,j=0;
    bool ya=false;
    if(mp1.size()==1){
        yesno(true);
        return;
    }
    while(j<n){
        mp2[str[j]]++;
        if(mp2[str[j]]==2){
            bool ch=true;
            while(mp1.size()==mp2.size()){
                mp2[str[i]]--;
                if(mp2[str[i]]==0) break;
                if(str[i]==str[j]) {
                    ch=false;
                    i++;
                    break;
                }
                i++; 
            }
            if(ch){
                ya=true;
                break;
            }
        }
        j++;
    }
    yesno(!ya);
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}