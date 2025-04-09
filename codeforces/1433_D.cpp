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
    vi arr(n);
    vector<pii> res;
    input(arr,n);
    forn(i,1,n){
        if(arr[i]!=arr[0]){
            res.push_back({1,i+1});
            arr[i]=-1;
        }
    }
    if(res.size()==0){
        yesno(false);
    }
    else{
        arr[0]=-1;
        yesno(true);
        forn(i,0,res.size()){
            cout<<res[i].first<<" "<<res[i].second<<endl;
        }
        forn(i,0,n){
            if(arr[i]!=-1){
                cout<<res[0].second<<" "<<i+1<<endl;
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