/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-17 13:53 (GMT+5)

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

bool check(int a,int b,int aa,int bb,int cc,int n){
    int ya=a*b;
    if(n>=ya && n%ya==0){
        int yaa=n/ya;
        if(cc%yaa==0 && (a*b*yaa)==n) {
            cout<<a-1<<" "<<b-1<<" "<<yaa-1<<endl;
            return true;
        }
    }
    return false;
}

void solve() {
    int a,b,c; cin>>a>>b>>c;
    int n; cin>>n;
    for(int i=1;i*i<=a;i++){
        if(a%i==0){
            for(int j=1;j*j<=b;j++){
                if(b%j==0){
                    if(check(i,j,a,b,c,n)) return;
                    if(check(a/i,j,a,b,c,n)) return;
                    if(check(a/i,b/j,a,b,c,n)) return;
                    if(check(i,b/j,a,b,c,n)) return;
                }
            }   
        }
    }
    cout<<-1<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}