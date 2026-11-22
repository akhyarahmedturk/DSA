/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-06 20:49 (GMT+5)

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

vi primes;

void seive(){
    int N=2e5+10;
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++){
        if (is_prime[i]){
            for (int j = i * i; j <= N; j += i){
                is_prime[j] = false;
            }
        }
    }
    forn(i,2,N+4) {
        if(is_prime[i]) primes.pb(i);
    }
}

int dfs(int curr,int idx,int mx,vi &arr){
    if(idx==arr.size() || curr>mx) return 0;
    int res=curr;
    forn(i,idx,arr.size()){
        res=max(res,dfs(curr*arr[idx],i,mx,arr));
    }
    return res;
}

void solve() {
    vi res;
    int a,b; cin>>a>>b;
    int dd=(b-a)/a;
    if(dd) res.pb(dd*a-1) , a+=dd*a-1;
    while(a<b){
        int d=(b-a);
        if(d==1) {res.pb(1); break;}
        vi ya;
        for(auto it:primes){
            if(a%it!=0 && it%a!=0) ya.pb(it);
            if(ya.size()==10) break;
        }
        int v=dfs(1,0,d,ya);
        a+=v;
        res.pb(v);
    }
    cout<<res.size()<<endl;
    for(auto it:res) cout<<it<<" ";
    if(res.size()) cout<<endl;
}


// 500 , 900


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    cin >> t;
    seive();
    while (t--) {
        solve();
    }
    return 0;
}