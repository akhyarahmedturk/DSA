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
    vector<pii> arr;
    forn(i,0,n){
        int a;
        cin>>a;
        if(a<i+1) arr.pb({a,i+1});//only valid ones
    }
    sort(all(arr));
    ordered_set<int> idx;
    int res=0,i=0,j;
    n=arr.size();
    while(i<n){
        j=i;
        while(j<n && arr[j].first==arr[i].first){
            res += idx.order_of_key(min(arr[j].first, arr[j].second)); // min because index as well as value both should be greater
            j++;
        }
        forn(k,i,j){// inserting at the end after precessing all with same value
            idx.insert(arr[k].second); // storing only index because values are alrrady in sorted order so no need
        }
        i=j;
    }
    cout<<res<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}