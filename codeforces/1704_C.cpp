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
    int n,m;
    cin>>n>>m;
    vi arr(m);
    input(arr,m);
    sort(all(arr));
    vi arr2(m);
    arr2[0]=arr[0]-1 + (n-arr.back());
    forn(i,1,m){
        arr2.push_back(arr[i]-arr[i-1]-1);
    }
    sort(allr(arr2));
    int res=0,curr=0;
    forn(i,0,m){
        if(arr2[i]==curr+1) {
            res++;
            break;
        }
        else if(arr2[i]>curr+1){
            res+= (arr2[i]-curr-1);
            curr+=4;
        }
        else break;
    }    
    cout<<n-res<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}