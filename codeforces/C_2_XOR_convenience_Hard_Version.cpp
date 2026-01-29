/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-24 11:07 (GMT+5)

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
    int n; cin>>n;
    int ya=__builtin_popcount(n);
    if(ya==1){ cout<<-1<<endl; return;}
    vi res(n+1);
    if(n&1){
        res[n]=1; res[n-1]=n; res[1]=n-1;
        int i=n-2;
        while(i>1) { res[i]=i-1; res[i-1]=i; i-=2;}
    }
    else{
        res[n]=n-2; res[n-1]=1; res[n-2]=n-1;
        int i=n-3;
        while(i>1) { res[i]=i-1; res[i-1]=i; i-=2;}
        int c=1;
        while(!(n&(1LL<<c))) c++;
        res[1]=res[(1LL<<c) +1 ];
        res[(1LL<<c) +1 ]=n;
    }
    forn(i,1,n+1) cout<<res[i]<<" ";
    cout<<endl;
}
// 5 => 4 3 2 5 1
// 6 => 3 6 2 5 1 4 
// 7 => 6 3 2 6 5 4 7 1    
// 9 => 8 3 2 5 4 7 6 9 1  
// 10=> 3 10 2 5 4 7 6 9 1 8

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