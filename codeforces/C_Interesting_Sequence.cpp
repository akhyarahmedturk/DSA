
/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-16 21:07 (GMT+5)

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
    int n,x; cin>>n>>x;
    if(n==x) { cout<<n<<endl; return;}
    if(x==0){
        int v=64- __builtin_clzll(n);
        v=(1LL<<v);
        cout<<v<<endl; return;
    }
    if((n&x)<x) {cout<<-1<<endl; return;}
    vi a;
    vi b;
    while(n){ a.pb(n%2); n/=2; }
    while(x){ b.pb(x%2); x/=2; }
    if(a.size()!=b.size()){ cout<<-1<<endl; return;}
    bool ch=false;
    int res=0;
    forr(i,a.size()-1,0){
        if(a[i]){
            res=res*2+1;
            if(!b[i]){
                if(a[i+1]) { cout<<-1<<endl; return;}
                forr(j,i-1,0){
                    if(a[j]){
                        if(b[j]){ cout<<-1<<endl; return;}
                    }
                    res=res*2+1;
                }
                cout<<res+1<<endl;
                return;
            }
        }
        else res=res*2;
    }
    cout<<res<<endl;
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
//1010011
//1010001

//11 9
//1011
//1001