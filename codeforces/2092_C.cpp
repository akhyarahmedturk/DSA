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
    int n,odd=0LL,even=0LL,even_sum=0LL,odd_sum=0LL,max_=0LL;
    cin>>n;
    forn(i,0,n){
        int a;
        cin>>a;
        max_=max(max_,a);
        if(a&1){
            odd++;
            odd_sum+=a;
        }
        else{
            even++;
            even_sum+=a;
        }
    }
    if(even==0 || odd==0) cout<<max_<<endl;
    else if(odd==1) cout<<odd_sum+even_sum<<endl;
    else cout<<odd_sum+even_sum-(odd-1LL)<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}