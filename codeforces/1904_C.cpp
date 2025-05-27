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
// #define mp make_pair
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
    vi arr(n);
    input(arr,n);
    if(k>=3) { cout<<0<<endl; return;}
    sort(all(arr));
    int mm=arr[0];
    forn(i,1,n){
        mm=min(mm,arr[i]-arr[i-1]);
    }
    if(k==1) cout<<mm<<endl;
    else{
        forn(i,0,n){
            forn(j,i+1,n){
                int a=abs(arr[i]-arr[j]);
                if(a<=arr[0]) mm=min(mm,abs(a-arr[0]));
                else if(a>=arr.back()) mm=min(mm,abs(a-arr.back()));
                else{
                    int idx=upper_bound(all(arr),a)-arr.begin();
                    mm=min(mm,min(abs(a-arr[idx]),abs(a-arr[idx-1])));
                }
                if(a>arr.back()) break;
            }
        }
        cout<<mm<<endl;
    }
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