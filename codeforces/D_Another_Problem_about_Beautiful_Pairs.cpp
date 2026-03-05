//   Bismillah
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
#define vb vector<bool>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX
#define nl "\n"

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n);
    int res=0,ya=sqrt(n)+1;//sqrt root decomposition
    forn(i,0,n){
        if(arr[i]>=ya){
            int d=1;
            while(d*arr[i]+i<=n-1 || i-d*arr[i]>=0){
                int prv=i-d*arr[i],next=d*arr[i]+i; 
                if(next<=n-1){
                    if(arr[next]*arr[i]==next-i) res++;
                }
                if(prv>=0){
                    if(arr[prv]*arr[i]==i-prv) res++;
                }
                d++;
            }
        }
        else{
            int d=1;
            while(d*arr[i]+i<=n-1 && d<ya){
                int next=d*arr[i]+i; 
                if(next<=n-1){
                    if(arr[next]*arr[i]==next-i)  res++; 
                }
                d++;
            }
        }
    }
    cout<<res<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}