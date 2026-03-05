/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-03-01 21:05 (GMT+5)

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
    // monotonic stack
    vi ya1(n,1),ya2(n,1);
    stack<pii> st1; st1.push({arr[n-1],1});
    stack<pii> st2; st2.push({arr[0],1});
    forr(i,n-2,0){
        while(!st1.empty() && st1.top().f<arr[i]) st1.pop();
        int ya=0;
        if(!st1.empty()) ya=st1.top().ss;
        ya1[i]=ya+1;
        st1.push({arr[i],ya1[i]});
    }
    forn(i,1,n){
        while(!st2.empty() && st2.top().f<arr[i]) st2.pop();
        int ya=0;
        if(!st2.empty()) ya=st2.top().ss;
        ya2[i]=ya+1;
        st2.push({arr[i],ya2[i]});
    }
    int res=2;
    forn(i,1,n-1){
        // dono side bary hy to dono taraf extend karsakty
        if(arr[i]<arr[i-1] && arr[i]<arr[i+1]) res=max(res,ya1[i]+ya2[i]-1);
    }
    if(arr[2]>arr[1]) res=max(res,ya1[1]+1);
    if(arr[n-3]>arr[n-2]) res=max(res,ya2[n-2]+1);
    cout<<n-res<<endl;
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