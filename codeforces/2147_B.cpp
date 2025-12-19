/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-20 20:01 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");
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
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    int n; cin>>n;
    vi res(n*2+1,-1);
    int curr=(n/2)*2;
    for(int i=1;curr>=2;curr-=2,i++) { res[i]=curr; res[i+curr]=curr; }
    if(n&1) curr=n;
    else curr=n-1;
    int ya=(n/2)+1;
    // if(n==2) cout<<res[3]<<"vsw"<<curr;
    if(curr>2) {res[ya]=curr; res[ya+curr]=curr;}
    // if(n==2) cout<<res[3]<<"vsw"<<curr;
    curr-=2;
    for(int i=1;curr>1 && i<=2*n;i++) {
        if(res[i]==-1 && res[i+curr]==-1){ res[i]=curr; res[i+curr]=curr; curr-=2;}
    }
    forn(i,1,2*n+1){
        cout<<((res[i]==-1)?1:res[i])<<" ";
    }
    cout<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}