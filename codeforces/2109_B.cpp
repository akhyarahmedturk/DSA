/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-17 19:57 (GMT+5)

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
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
// #define mp make_pair
#define pb push_back
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
    int nn,mm,a,b;
    cin>>nn>>mm>>a>>b;
    // int count=1;
    vi arr(4,1);
    int n,m;
    n=nn-(a-1);
    m=mm;
    while(m>1 || n>1){
        arr[0]++;
        if((m/2)*n >= (n/2)*m) m=(m+1)/2;
        else n=(n+1)/2;
    }
    m=mm-(b-1);
    n=nn;
    while(m>1 || n>1){
        arr[1]++;
        if((m/2)*n >= (n/2)*m) m=(m+1)/2;
        else n=(n+1)/2;
    }
    m=mm-(mm-b);
    n=nn;
    while(m>1 || n>1){
        arr[2]++;
        if((m/2)*n >= (n/2)*m) m=(m+1)/2;
        else n=(n+1)/2;
    }
    m=mm;
    n=nn-(nn-a);
    while(m>1 || n>1){
        arr[3]++;
        if((m/2)*n >= (n/2)*m) m=(m+1)/2;
        else n=(n+1)/2;
    }
    sort(all(arr));
    cout<<arr[0]<<endl;
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