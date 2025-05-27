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

vector<int> primeNums( int n ) {
    vector<bool> isPrime( n + 1 , true ) ;
    isPrime[0] = isPrime[1] = false;
    for( int i = 2 ; i * i <= n ; i++ ) {
        if( isPrime[i] ) {
            for( int j = i * i ; j <= n ; j += i )
                isPrime[j] = false ;
        }
    }

    vector<int> primes;
    for( int i = 2 ; i <= n ; i++ )
        if( isPrime[i] ) {
            cout << i << " " ;
            primes.push_back( i ) ;
        }
        
    return primes ;
}
vi primes;

void solve() {
    int n;
    cin>>n;
    string a;
    cin>>a;
    if(n==2 || ((a[0]==a[n-1] || a[0]==a[n-2]) && a[0]=='B')){
        if(a[0]=='A') cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    else{
        int count=0;
        forn(i,0,n){
            if(a[i]=='A') count++;
        }
        if(a[n-1]=='A'){
            if(count>1) cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
        else{
            if(count<n-1) cout<<"Bob"<<endl;
            else cout<<"Alice"<<endl;
        }
    }
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    cin >> t;
    primes=primeNums(1e5);
    while (t--) {
        solve();
    }
    return 0;
}