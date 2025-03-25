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
    int n,x,res=0;
    cin>>n>>x;
    vi arr(n);
    input(arr,n);
    sort(arr.rbegin(),arr.rend());
    int start=0;
    while(start<n){
        int a=1;
        while(start+a<=n && a*arr[start+a-1]<x) a++;
        if(start+a<=n && a*arr[start+a-1]>=x) res++;
        start+=(a);
    }
    cout<<res<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}