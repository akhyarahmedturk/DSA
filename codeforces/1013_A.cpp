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
#define input(vec, n) for(int i = 0; i < (n); i++) cin >> vec[i];

void solve() {
    int n;
    cin>>n;
    map<int,int> mp1,mp2;
    mp1[0]=3;
    mp1[1]=1;
    mp1[3]=1;
    mp1[2]=2;
    mp1[5]=1;
    mp2[0]=0;
    mp2[1]=0;
    mp2[3]=0;
    mp2[2]=0;
    mp2[5]=0;
    int check=0;
    forn(i,0,n){
        int x;
        cin>>x;
        mp2[x]++;
        if(check==0){
            bool ch=false;
            for(auto it:mp1){
                if(mp2[it.first]<it.second){
                     ch=true;
                }
            }
            if(!ch) check=i+1;
        }
    }
    cout<<check<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}