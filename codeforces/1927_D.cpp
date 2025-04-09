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
    int n,q;
    cin>>n;
    vi arr(n),pre_c(n);
    input(arr,n);
    int prv=-1,j=0,curr;
    while(j<n){
        curr=arr[j];
        while(j<n && arr[j]==curr){
            pre_c[j]=prv;
            j++;
        }
        prv=j-1;
    }
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        if(pre_c[r]<l) cout<<-1<<" "<<-1<<endl;
        else cout<<r+1<<" "<<pre_c[r]+1<<endl;
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