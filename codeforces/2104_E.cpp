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
    string s;
    cin>>s;
    vector<vi> arr(k);
    vi dp(n+1);
    dp[n]=0;
    dp[n-1]=1;
    forn(i,0,s.length()){
        arr[(s[i]-'a')].push_back(i);
    }
    forr(i,s.length()-2,0){
        int mm=i+1;
        forn(j,0,k){
            if(arr[j].size()==0 || arr[j].back()<=i) {mm=n; break;}
            mm=max(mm,*lower_bound(all(arr[j]),i+1));
        }
        dp[i]=1+dp[mm];
        // cout<<dp[i]<<" ";
    }
    int q;
    cin>>q;
    while(q--){
        string a;
        cin>>a;
        if(a.length()>n) {cout<<0<<endl; continue;}
        if(k==1) {cout<<n-a.length()+1<<endl; continue;}
        int curr=-1;
        bool ch=false;
        forn(i,0,a.length()){
            if(arr[(a[i]-'a')].size()==0 || curr>=arr[(a[i]-'a')].back()) {ch=true; break;}
            curr=*lower_bound(all(arr[(a[i]-'a')]),curr+1);
        }
        if(ch) cout<<0<<endl;
        else cout<<dp[curr]<<endl;
    }
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}