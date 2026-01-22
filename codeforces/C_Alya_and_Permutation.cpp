/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-23 13:48 (GMT+5)

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
    //odd py 1 3 phir last 2
    // even py 1 3 phir msb bit waly last 3
    if(n==1) cout<<"0"<<endl<<"1"<<endl;
    else if(n==2) cout<<"2"<<endl<<"1 2"<<endl;
    else if(n==3) cout<<"2"<<endl<<"1 2 3"<<endl;
    else if(n==4) cout<<"5"<<endl<<"2 1 3 4"<<endl;
    else if(n==6) cout<<"7"<<endl<<"6 1 5 2 3 4"<<endl;
    else if(n&1){
        cout<<n<<endl;
        cout<<"2 ";
        forn(i,4,n-1) cout<<i<<" ";
        cout<<"1 3 ";
        cout<<n-1<<" "<<n<<endl;
    }
    else{
        int v=64- __builtin_clzll(n);
        int ans=(1LL<<v)-1;
        int end=(1LL<<(v-1));
        cout<<ans<<endl;
        cout<<"2 ";
        forn(i,4,n+1){
            if(i!=end && i!=end-1 && i!=end-2) cout<<i<<" ";
        }
        cout<<"1 3 ";
        cout<<end-2<<" "<<end-1<<" "<<end<<endl;
    }
}
// 4
// 2 1 3 4
//8
// 2 4 5 1 3 6 7 8
//6
// 1 2 3 4

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