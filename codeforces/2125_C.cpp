/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-22 20:03 (GMT+5)

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

int lcm(int a, int b) {
    return (a / __gcd(a, b)) * b;
}

void solve() {
    int l,r;
    cin>>l>>r;
    int res=0;
    // res+=(r/2)-((l-1)/2);
    // res+=(r/3)-((l-1)/3);
    // res+=(r/5)-((l-1)/5);
    // res+=(r/7)-((l-1)/7);
    // res-=(r/6)-((l-1)/6);
    // res-=(r/10)-((l-1)/10);
    // res-=(r/14)-((l-1)/14);
    // res-=(r/14)-((l-1)/14);
    // res-=(r/14)-((l-1)/14);
    // res-=(r/14)-((l-1)/14);

    // res+=(r/30)-((l-1)/30);  // multiple of 2,3,5
    // ..
    // 2*3*5*7=210
    vi arr={2,3,5,7};
    forn(i,0,4){
        res+=((r/arr[i])-((l-1)/arr[i]));// multiples of 2,3,5,7
    }
    forn(i,0,4){
        forn(j,i+1,4) res-=((r/(arr[i]*arr[j]))-((l-1)/(arr[i]*arr[j])));// that are multiple of any 2
    }
    forn(i,0,4){
        forn(j,i+1,4){
            forn(k,j+1,4) res+=((r/(arr[i]*arr[j]*arr[k]))-((l-1)/(arr[i]*arr[j]*arr[k])));// multiple of any three
        }
    }
    res-=((r/210)-((l-1)/210)); // multiple of any 4
    cout<<(r-l+1)-res<<endl;
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