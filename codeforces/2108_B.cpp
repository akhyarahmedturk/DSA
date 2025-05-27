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
    int n,x,xx;
    cin>>n>>x;
    xx=x;
    if(x==0){ 
        if(n==1) cout<<-1<<endl;
        else if(n%2==0) cout<<n<<endl;
        else cout<<n-1+4<<endl;
        return;
    }
    else if(x==1){ 
        if(n==1) cout<<1<<endl;
        else if(n&1) cout<<n<<endl;
        else  cout<<n-1+4<<endl;
        return;
    }
    int bits=0LL;
    while(x){
        if(x&1) bits++;
        x=x>>1; 
    }
    // cout<<" b "<<bits<<endl;
    if(bits>=n){
        cout<<xx<<endl;
    }
    else{
        int diff=n-bits;
        if(diff%2==0) {
            cout<<xx+diff<<endl;
        }
        else{
            cout<<xx+diff+1<<endl;
        }
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