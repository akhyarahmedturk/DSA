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
    int n,m,k;
    cin>>n>>m>>k;
    if(m*n==k){
        cout<<m<<endl;
        return;
    }
    if(m==1 || k<n){
        cout<<1<<endl;
        return;
    }
    if(k%n==0) k=k/n;
    else k=k/n+1;
    if(k==m){
        cout<<m<<endl;
        return;
    }
    if(k<=(m+1)/2){
        cout<<1<<endl;
        return;
    }
    int start=2,end=m-1;
    int ans=m-1;
    while(start<=end){
        int mid=(start+end)/2,enc;
        if((m+1)%(mid+1)==0) enc=((m+1)/(mid+1))*mid;
        else enc=((m+1)/(mid+1))*mid + ((m+1)%(mid+1)-1);
        if(k<=enc){
            // cout<<mid<<endl;
            ans=mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    cout<<ans<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}