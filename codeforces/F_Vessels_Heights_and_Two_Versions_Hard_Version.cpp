/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-21 12:31 (GMT+5)

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
    int mx=0;
    // left boundary pe max height wale ko rakh do
    forn(i,0,n) mx=(arr[i]>arr[mx])?i:mx;
    vi arr2;
    forn(i,0,n) arr2.pb(arr[(i+mx)%n]);
    swap(arr,arr2);
    // ab right left ke containers me kitna hoga? calculate kar sakte
    vi res_r(n+1,0);
    stack<pii> st; st.push({inf,n});
    forr(i,n-1,1){
        while(st.top().f<arr[i]) st.pop();
        res_r[i]=(st.top().ss-i)*arr[i]+res_r[st.top().ss];
        st.push({arr[i],i});
    }
    vi res_l(n+1,0);
    stack<pii> st2; st2.push({arr[0],0});
    forn(i,1,n-1){
        while(st2.top().f<arr[i]) st2.pop();
        res_l[i+1]=(i-st2.top().ss)*arr[i]+res_l[st2.top().ss+1];
        st2.push({arr[i],i});
    }
    // i=0 pe right ke lie extra case
    int mxx=0;
    forr(i,n-1,1) mxx=max(arr[i],mxx) , res_r[0]+=mxx;
    forn(i,0,n) cout<<res_r[(i-mx+n)%n]+res_l[(i-mx+n)%n]<<" ";
    cout<<endl;
}

// 4 1 2 3

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