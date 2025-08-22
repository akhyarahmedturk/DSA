/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-14 23:12 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
// idx.find_by_order(n); to get the nth value by order
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
#define pb push_back
#define f first
#define ss second
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
    int n; cin>>n;
    int l=0,r=1e9+10,res,vall;
    vector<pii> arr(n);
    forn(i,0,n) cin>>arr[i].f;
    forn(i,0,n) { cin>>arr[i].ss; l=max(l,arr[i].ss); }
    sort(all(arr));
    while(l<=r){
        int mid=(l+r)/2;
        pii val={arr[0].f-(mid-arr[0].ss), arr[0].f+(mid-arr[0].ss)};
        bool ch=true;
        forn(i,0,n){
            if(((arr[i].f-arr[i].ss<val.ss && arr[i].f-arr[i].ss)<val.ss ) &&
             ((arr[i].f+(mid-arr[i].ss)<val.f && arr[i].f+(mid-arr[i].ss)<val.f))) {
                if(arr[i].f>=val.ss) {ch=false; break;}
            }
        }
        if(ch) { res=mid; vall=val.f; r=mid-1; }
        else l=mid+1;
    }
    bool ch1=false,ch2=false;
    forn(i,0,n){
        if(arr[i].f<=vall && arr[i].ss+abs(arr[i].f-vall)==res) ch1=true;
        if(arr[i].f>=vall && arr[i].ss+abs(arr[i].f-vall)==res) ch2=true;
    }
    ld valll=vall;
    if(ch1 && ch2) cout<<vall<<endl;
    else if(ch1) cout<<(vall-0.5)<<endl;
    else cout<<(vall+0.5)<<endl;
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