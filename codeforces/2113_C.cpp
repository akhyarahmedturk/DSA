/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-15 14:59 (GMT+5)

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
// #define mp make_pair
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
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> arr(n);
    vector<vector<int>> prefix(n+1,vector<int>(m+1,0));
    forn(i,0,n) cin>>arr[i];
    int total=0;
    forn(i,1,n+1){
        forn(j,1,m+1) {// 2d prefix sum bna liya
            if(arr[i-1][j-1]=='g') { total++; prefix[i][j]++;}
            prefix[i][j]+=(prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]);
        }
    }
    // 1st explosion me jo gold loss hua bas wohi loss hoga 
    // so har empty space py 1 explosion kar ky max nikal sakty
    int res=0;
    forn(i,1,n+1){
        forn(j,1,m+1) {
            if(arr[i-1][j-1]!='.') continue;
            int curr=prefix[min(i+k-1,n)][min(j+k-1,m)]-prefix[max(i-k,0LL)][min(j+k-1,m)]-prefix[min(i+k-1,n)][max(j-k,0LL)]+prefix[max(i-k,0LL)][max(j-k,0LL)];
            res=max(total-curr,res);// total me sy current rectangle waly gold kar diy
        }
    }
    cout<<res<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}