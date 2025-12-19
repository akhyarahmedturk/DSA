/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-20 19:39 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");

*    Those who can't remember the past are condemned to repeat it.
*                                                 -Dynamic Programming.
*/
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
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    int n; cin>>n;
    //aesy primes jin ka 2nd multiple bhi exist na karta ho bas un ko dekhna hy bas
    //un sab ky peechy or aagy 2 sahi waly hon
    vector<bool> is_prime(n + 1, true);
    vi ya;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            ya.pb(i);
            for (int j = i * i; j <= n; j += i) {
                if(is_prime[j]) ya.pb(j);
                is_prime[j] = false;
            }
            if(ya.back()!=i) {
                is_prime[i]=false;
            }
            else ya.pop_back();
        }
    }
    vi primes={1};
    for(int i=2;i<=n;i++){
        if(is_prime[i]) primes.pb(i);
    }
    int i=0,j=0;
    int nn=ya.size(),mm=primes.size();
    while(i<nn){
        if(j<mm){
            cout<<primes[j++]<<" ";
        }
        cout<<ya[i]<<" "; i++;
        if(i==nn) break;
        cout<<ya[i]<<" "; i++;
    }
    while(j<mm) cout<<primes[j++]<<" ";
    cout<<endl;
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