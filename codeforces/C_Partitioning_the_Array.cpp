/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-02 19:33 (GMT+5)

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
    vi arr(n); input(arr,n);
    int res=0;
    for(int i=1;i*i<=n;i++){
        if(n%i) continue;
        int a=i,b=n/i,g=-1;
        int one=0;
        forn(j,0,a){
            int gg=-1;
            one+=(arr[j*b]==1);
            forn(k,1,b){
                cout<<j*b+k<<" ";
                one+=(arr[j*b+k]==1);
                if(abs(arr[j*b+k]-arr[j*b+k-1])==0) continue;
                if(gg==-1) gg=abs(arr[j*b+k]-arr[j*b+k-1]);
                gg=__gcd(gg,abs(arr[j*b+k]-arr[j*b+k-1]));
            }
            cout<<endl;
            if(gg!=-1) {
                if(g==-1) g=gg;
                else g=__gcd(g,gg);
            }
        }
        if(g==-1 || g>1 || one==n) res++;
        a=n/i,b=i,g=-1;
        forn(j,0,a){
            int gg=-1;
            forn(k,1,b){
                one+=(arr[j*b+k]==1);
                if(abs(arr[j*b+k]-arr[j*b+k-1])==0) continue;
                if(gg==-1) gg=abs(arr[j*b+k]-arr[j*b+k-1]);
                gg=__gcd(gg,abs(arr[j*b+k]-arr[j*b+k-1]));
            }
            if(gg!=-1) {
                if(g==-1) g=gg;
                else g=__gcd(g,gg);
            }
        }
        if(g>1 || one==n) res++;
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