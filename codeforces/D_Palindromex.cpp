/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-07-05 23:23 (GMT+5)

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

void check(int l,int r,int n,vi &arr,int &res){
    set<int> st;
    while(l>=0 && r<=n-1 && arr[l]==arr[r]){
        st.insert(arr[l]);
        if(st.size()==*(--st.end())+1) res=st.size();
        l-- , r++;
    }
}

void solve() {
    int n; cin>>n; n*=2;
    vi arr(n); input(arr,n);
    int z1=n,z2=0;
    forn(i,0,n){
        if(arr[i]) continue;
        z1=min(z1,i);
        z2=i;
    }
    int res=1;
    int l=z1,r=z1;
    check(l,r,n,arr,res);
    l=z2,r=z2;
    check(l,r,n,arr,res);
    if((z2+z1)&1) l=(z1+z2)/2, r=(z1+z2)/2+1;
    else l=(z1+z2)/2, r=(z1+z2)/2;
    check(l,r,n,arr,res);
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