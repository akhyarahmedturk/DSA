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
    int n;
    cin>>n;
    vector<vi> arr(n,vi(2));
    forn(i,0,n ) input(arr[i],2);
    int ans,mid,start=0,end=1e9+10;
    while(start<=end){
        bool ch=true;
        int mm=0,mx=0;
        mid=(start+end)/2;
        forn(i,0,n){
            if(arr[i][1]<mm-mid || arr[i][0]>mx+mid){
                ch=false;
                break;
            }
            mm=max(arr[i][0],mm-mid);
            mx=min(arr[i][1],mx+mid);
            // cout<<mm<<" "<<mx<<" " <<mid<<endl;
        }
        if(ch){
            ans=mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    cout<<ans<<endl;
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