//Bismillah
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f(i, a, n) for (int i = a; i < n; i++)
#define pr(vec) {for(auto &value: vec) cout<<value<<" ";} nl;
#define iv(vec) for(auto &value: vec) cin>>value;
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uset unordered_set
#define mset unordered_multiset
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pair<int,int>>
#define ld long double
#define nl cout<<"\n";
#define ned ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);int tt = 1;
#define yes cout << "YES\n"
#define no cout << "NO\n"

/*
    Hazrat_Legacy!
    On my way to ---------> ICPC 
*/

// Sieve of Eratosthenes
const int N = 1e6 + 5;   // limit
vector<int> primes;
vector<bool> isPrime(N, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) primes.push_back(i);
    }
}

void solve(){
    int n,m,h;cin>>n>>m>>h;
    vi a(n);iv(a);
    vi orig=a;
    vi b=a;
    while(m--){
        int x,y;cin>>x>>y;
        a[x-1]+=y;
        if(a[x-1]>h){
            a=orig;
        }
    }
    pr(a);
}


signed main(){
    ned;
    // freopen("moocast.in", "r", stdin);
    // freopen("moocast.out", "w", stdout);
    cin>>tt;
    sieve();
    while(tt--)
    {
        solve();
    }
    return 0;
}