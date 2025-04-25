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

const int N = 200;
int  fact[N + 10];
int  inv_fact[N + 10];

int binary_exp(int a, int b, int M){
    int ans = 1;
    while (b){
        if (b & 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

void precompute(){
    fact[0] = inv_fact[0] = 1;
    for (int i = 1;i < N;i++){
        fact[i] = (i * fact[i - 1]) % mod;
        inv_fact[i] = binary_exp(fact[i], mod - 2, mod) % mod;
    }
}

int NCR(int n, int r){
    if (r > n) return 0;
    return (((fact[n] * inv_fact[n - r]) % mod) * inv_fact[r]) % mod;
}

int n,m,h,sum=0LL;
int sol_(int idx,int sum,int req,vector<int> &arr,vector<vi> &dp){
    // cout<<idx<<" sum "<<sum<<" "<<req<<endl;
    if(req==0LL) return 1LL;
    if(dp[idx][req]!=-1) return dp[idx][req];
    int count=0LL;
    int l=max(0LL,req-(sum-arr[idx])),h=min(arr[idx],req);
    for(int i=l;i<=h;i++){
        count+=sol_(idx+1,sum-arr[idx],req-i,arr,dp)*NCR(arr[idx],i);
    }
    cout<<" dp "<<idx<<" sum "<<sum<<" req "<<req<<" = "<<count<<endl;
    return dp[idx][req]=count;
}

void solve() {//Not solved yet
    cin>>n>>m>>h;
    vi arr(m);
    forn(i,1,h){
        cin>>arr[i];
        sum+=arr[i];
    }
    cin>>arr[0];
    arr[0]--;
    sum+=arr[0];
    n--;
    forn(i,h,m){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum<n){ cout<<-1<<endl; return; }
    vector<vi> dp(m+1,vi(n+1,-1));
    int total=0LL,sub=0LL;
    if(sum-arr[0]>=n) total+=sol_(1,sum-arr[0],n,arr,dp);
    // if(sum-arr[0]>=n-1) total+=sol_(1,sum-arr[0],n-1,arr,dp)*NCR(arr[0],1);
    int l=max(1LL,n-(sum-arr[0])),h=min(arr[0],n);
    for(int i=l;i<=h;i++){
        sub+=sol_(1,sum-arr[0],n-i,arr,dp)*NCR(arr[0],i);
    }
    cout<<sub<<endl;
    cout<<total<<endl;
    total+=sub;
    cout<<setprecision(6);
    cout<<((sub*1.0)/(total*1.0))<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    precompute();
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}