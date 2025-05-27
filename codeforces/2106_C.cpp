#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
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
    int n,k;
    cin>>n>>k;
    vi arr1(n),arr2(n);
    input(arr1,n);
    input(arr2,n);
    int ch=-1,mm=INT_MAX,mx=0;
    forn(i,0,n){
        if(arr2[i]!=-1){
            if(ch==-1) ch=arr2[i]+arr1[i];
            else if(arr2[i]+arr1[i]!=ch) { cout<<0<<endl; return ;}
        }
        mm=min(mm,arr1[i]);
        mx=max(mx,arr1[i]);
    }
    if(ch!=-1 && (mm+k<ch || mx>ch)) cout<<0<<endl;
    else if(ch==-1) { cout<<max(0LL,mm+k-mx+1)<<endl;}
    else cout<<1<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}