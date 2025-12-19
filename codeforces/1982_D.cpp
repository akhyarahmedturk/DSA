/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-11 09:27 (GMT+5)

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

void solve() {
    int n,m,k; cin>>n>>m>>k;
    vector<vi> arr(n,vi(m));
    forn(i,0,n) input(arr[i],m);
    vector<string> arr2(n);
    vector<vi> prefix(n+1,vi(m+1,0));
    int sum=0,sum2=0;
    forn(i,0,n){
        cin>>arr2[i];
        forn(j,0,m){
            if(arr2[i][j]=='1') sum+=arr[i][j];
            else sum2+=arr[i][j];
            prefix[i+1][j+1]=prefix[i][j+1]+prefix[i+1][j]-prefix[i][j]+(arr2[i][j]=='1');
        }
    }
    if(sum==sum2){ cout<<"YES"<<endl; return;}
    int diff=(abs(sum-sum2));
    int g=0;
    forn(i,k,n+1){
        forn(j,k,m+1){
            int b=k*k;
            int a=prefix[i][j]-prefix[i-k][j]-prefix[i][j-k]+prefix[i-k][j-k];
            b-=a;
            if(a==b) continue;
            g=__gcd(g,abs(a-b));
        }
    }
    if(!g){ cout<<"NO"<<endl; return;}
    yesno(diff%g==0);
}
//2 4
//10 8 => 12 12
// 9+x=37+3x  => 2x=28=> x=14  
//7 11 3
//4 2 3
//0 1 15

//7 11 3
//-10 -12 3
//-14 -13 15

// 5x=-35 + x
// 4x=35 not possible

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