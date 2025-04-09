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
    int n;
    cin>>n;
    map<char,int> mp{{'T',0},{'I',0},{'L',0}};
    string s;
    cin>>s;
    forn(i,0,n){
        mp[s[i]]++;
    }
    if(n==1) cout<<-1<<endl;
    if(mp['T']==mp['I']==mp['L']) cout<<0<<endl;
    else{
        vector<pair<int,char>> vp({{mp['T'],'T'},{mp['L'],'L'},{mp['I'],'I'}});
        int i=0,curr=0;
        vector<int> res;
        vp[0].first=vp[2].first-vp[0].first;
        vp[1].first=vp[2].first-vp[1].first;
        vp.pop_back();
        while(i<n-1 && !vp.empty()){
            sort(all(vp));
            if(vp.size()==2){
                if(vp[0].second==)
            }
        }
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