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
    int n,q,prv,sum=0;
    cin>>n>>q;
    vi value,SUM;
    cin>>prv;
    sum+=prv;
    value.push_back(prv);
    SUM.push_back(sum);
    forn(i,1,n){
        int x;
        cin>>x;
        sum+=x;
        if(x<=prv) SUM[SUM.size()-1]=sum;
        else{
            prv=x;
            value.push_back(x);
            SUM.push_back(sum);
        }
    }
    forn(i,0,q){
        int x,res;
        cin>>x;
        if(x<value[0]) res=0;
        else if(x>value.back()) res=SUM.back();
        else res=SUM[upper_bound(all(value),x)-value.begin()-1];
        cout<<res<<" ";
    }
    cout<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}