/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-09 11:51 (GMT+5)

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

pii ss(int n,int k){
    if(n<k) return {0,0};
    pii ya=ss(n/2,k);
    // cout<<"n "<<n<<" "<<ya.f<<" "<<ya.ss<<endl;
    int d=(n+1)/2;
    // sab ko right per 'd' sy shift karna ho ga
    if(n&1) return {ya.f*2 + d*ya.ss + d,ya.ss*2 + 1};
    else return {ya.f*2 + d*ya.ss,ya.ss*2};
}

void solve() {
    int n,k; cin>>n>>k;
    cout<<(ss(n,k).f)<<endl;
}
// 1-10
// 1-5,6-10
// 1-2,3,4-5,6-7,8,9-10

// 1-7
// 1-3,4,5-7
// 2 , 6

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