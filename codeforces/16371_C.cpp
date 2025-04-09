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

void solve(){
    int n,x;
    cin >> n>>x;
    vi arr(n);
    input(arr, n);
    sort(all(arr));
    int sum=0;
    int i=0,res=0;
    while(sum+arr[i]<=x && i<n){
        sum+=arr[i];
        i++;
    }
    // cout<<" i "<<i<<" s "<<sum<<endl;
    forr(j,i-1,0){
        res+= (x-sum)/(j+1)+1;
        // cout<<" r"<<res<<endl;
        sum-=arr[j];
    }
    cout<<res<<endl;
}
int32_t main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
} 

// 1 2 2