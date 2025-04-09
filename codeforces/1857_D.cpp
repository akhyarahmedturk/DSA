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
    struct comp{
        bool operator()(pii &a,pii &b){
            return  (a.first==b.first) ? a.second<b.second: a.first>b.first;
        }
    };
    int n;
    cin>>n;
    vi arr1(n);
    vector<pii> ap(n);
    input(arr1,n);
    forn(i,0,n){
        int x;
        cin>>x;
        ap[i]={arr1[i]-x,i};
    }
    sort(all(ap),comp());
    int i=1;
    while(i<n && ap[i].first==ap[0].first) i++;
    cout<<i<<endl;
    forn(j,0,i) cout<<ap[j].second+1<<" ";
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