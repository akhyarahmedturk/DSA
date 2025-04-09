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

const int N = 1e6;

vector<bool> seive(){
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (long long i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (long long j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

void solve(vector<bool> &is_prime) {
    int n,k;
    cin>>n>>k;
    if(n==1LL && k>1){
        string str=to_string(n),res="";
        while(k--){
            res+=str;
        }
        n=stoll(res);
    }
    // cout<<" n "<<n<<endl;
    if(k>1) {yesno(false);} 
    else if(n<100000) {yesno(is_prime[n]);}
    else{
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                yesno(false);
                return;
            } 
        }
        yesno(true);
    }
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    cin >> t;
    vector<bool> is_prime=seive();
    while (t--) {
        solve(is_prime);
    }
    return 0;
}