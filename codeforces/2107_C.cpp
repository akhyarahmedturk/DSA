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

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi arr(n);
    input(arr, n);
    int sum = 0;
    int zer = -1,mx=0;
    forn(i, 0, n){
        if (s[i] == '0'){
            if (zer == -1) zer = i;
            sum = 0;
            continue;
        }
        else{
            sum += arr[i];
            mx=max(mx,sum);
            if (mx > k){ yesno(false); return; }
            if (sum < 0) sum = 0;
        }
    }
    if(zer==-1 && mx==k) {
        yesno(true); 
        forn(i,0,n) {
            if(s[i]=='0') cout << -1000000000000000 << " ";
            else cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(zer==-1){ yesno(false); return; }
    yesno(true);
    int prv = 0, prv_m = 0, next = 0, next_m = 0;
    int j = zer - 1;
    while (j >= 0 && s[j] != '0'){
        prv += arr[j];
        prv_m = max(prv_m, prv);
        j--;
    }
    j = zer + 1;
    while (j < n && s[j] != '0'){
        next += arr[j];
        next_m = max(next_m, next);
        j++;
    }
    forn(i,0,zer) cout<<arr[i]<<" ";
    cout << k - (prv_m + next_m) << " ";
    forn(k, zer + 1, n){
        if (s[k] == '0') cout << -1000000000000000 << " ";
        else cout << arr[k] << " ";
    }
    cout << endl;
    return;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}