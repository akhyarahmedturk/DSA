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
    int a,b;
    cin>>a>>b;
    if(a<b) swap(a,b);
    // cout<<"dc "<<a%b<<endl;
    if(a==b) cout<<0<<endl;
    else if(a%b!=0 ) cout<<-1<<endl;
    else{
        a/=b;
        int bits=0,cnt=0;
        while(a>1){
            bits+=(a&1);
            cnt++;
            a/=2;
        }
        if(bits!=0){
            cout<<-1<<endl;
            return;
        }
        int res=cnt/3;
        if(cnt%3) res++;
        cout<<res<<endl;
    }
}

int32_t main(){
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}