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
    input(arr,n);
    if(arr[n-2]>arr[n-1]){
        cout<<-1<<endl;
        return;
    }
    bool check=false;
    vector<vi> res;
    forr(i,n-3,0){
        if(arr[i]>arr[i+1]-arr.back()){
            arr[i]=arr[i+1]-arr.back();
            res.push_back({i+1,i+1+1,n-1+1});
        }
        if(arr[i]>arr[i+1]){
            check=true;
            break;
        }
    }
    if(check) cout<<-1<<endl;
    else{
        cout<<res.size()<<endl;
        forn(i,0,res.size()) cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<endl;
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