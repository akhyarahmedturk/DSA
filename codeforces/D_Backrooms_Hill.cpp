/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-25 20:03 (GMT+5)

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
    vi a,b;
    forn(i,0,n){
        int x; cin>>x;
        if(i&1) b.pb(x);
        else a.pb(x);
    }
    if(n==1){ cout<<"YES"<<endl; return;}
    sort(all(a)); sort(all(b));
    // vi arr(n);
    // forn(i,0,a.size()) arr[i*2]=a[i];
    // forn(i,0,b.size()) arr[i*2+1]=b[i];
    int base=0,x,y;
    if(a.back()<b.back()) base=1;
    else if(a.back()==b.back()){cout<<"NO"<<endl; return;}
    if(base) x=y=b.back() , b.pop_back();
    else x=y=a.back() , a.pop_back();
    while(1){
        if(base){
            if(a.empty()) break;
            if(a.back()>=x) { cout<<"NO"<<endl; return;}
            x=a.back(); a.pop_back();
            if(a.size()){
                if(a.back()>=y) { cout<<"NO"<<endl; return;}
                y=a.back(); a.pop_back();
            }
        }
        else{
            if(b.empty()) break;
            if(b.back()>=x) { cout<<"NO"<<endl; return;}
            x=b.back(); b.pop_back();
            if(b.size()){
                if(b.back()>=y) { cout<<"NO"<<endl; return;}
                y=b.back(); b.pop_back();
            }
        }
        base=!base;
    }
    cout<<"YES"<<endl;
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