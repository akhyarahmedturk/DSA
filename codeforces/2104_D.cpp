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

vector<int> primeNums(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 4; i <= n; i += 2) {
        isPrime[i] = false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int> primes;
    primes.reserve(n / 10); 
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}
vi primes;

void solve() {
    int n;
    cin>>n;
    vi arr(n);
    input(arr,n);
    sort(allr(arr));
    int count=0;
    forn(i,0,n){
        if(i==primes.size()){
            // cout<<n-primes.size()<<endl;
            // return;
            break;
        }
        if(arr[i]>primes[i]) count+=(arr[i]-primes[i]);
        else if(arr[i]+count>=primes[i]){
            count-=(primes[i]-arr[i]);
        }
        else{
            cout<<n-i<<endl;
            return;
        }
    }
    cout<<0<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    cin >> t;
    primes=primeNums(1e7);
    while (t--) {
        solve();
    }
    return 0;
}