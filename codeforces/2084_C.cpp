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
    int n;
    cin>>n;
    vi a(n+1),a_idx(n+1),b(n+1),b_idx(n+1);
    forn(i,1,n+1){
        cin>>a[i];
        a_idx[a[i]]=i;
    }
    int barabar=-1,s=0;
    forn(i,1,n+1){
        cin>>b[i];
        b_idx[b[i]]=i;
        if(a[i]==b[i]){ barabar=i; s++;}
    }
    if(s==n || (n%2==0 && s) || (n&2 && s!=1)) { cout<<-1<<endl; return;}
    vector<pii> res;
    int mid_s=(n-s)/2+1;
    if(barabar!=mid_s){
        swap(a_idx[a[barabar]],a_idx[a[mid_s]]);
        swap(b_idx[b[barabar]],b_idx[b[mid_s]]);
        swap(a[barabar],a[mid_s]);
        swap(b[barabar],b[mid_s]);
        res.push_back({barabar,mid_s});
    }
    bool check=true;
    forn(i,1,(n-s)/2+1){
        int idx=b_idx[a[i]];
        if(b[i]!=a[idx]) {check=false; break;}
        if(n-i+1!=idx){
            swap(a_idx[a[idx]],a_idx[a[n+1-i]]);
            swap(b_idx[b[idx]],b_idx[b[n+1-i]]);
            swap(a[idx],a[n-i+1]);
            swap(b[idx],b[n-i+1]);
            res.push_back({idx,n-i+1});
        }
    }
    if(check==false) cout<<-1<<endl;
    else{
        cout<<res.size()<<endl;
        forn(i,0,res.size()) cout<<res[i].first<<" "<<res[i].second<<endl;
    }
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}