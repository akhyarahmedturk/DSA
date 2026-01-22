/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-29 22:30 (GMT+5)

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
// #define int long long
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

void solve() {
    int a,b,c; cin>>a>>b>>c;
    if(c==1){
        yesno((a%b==0 || b%a==0 ) && a!=b);
        return;
    }
    int mx1=0,mx2=0;
    while(a%2==0){ a/=2; mx1++;}
    for(int i=3;i*i<=a;i+=2){
        while(a%i==0){
            mx1++;
            a/=i;
        }
    }
    if(a>1) mx1++;
    while(b%2==0){ b/=2; mx2++;}
    for(int i=3;i*i<=b;i+=2){
        while(b%i==0){
            mx2++;
            b/=i;
        }
    }
    if(b>1) mx2++;
    yesno(c<=mx1+mx2);
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