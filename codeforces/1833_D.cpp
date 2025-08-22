/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-06 16:19 (GMT+5)

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

void solve(){
    int n;
    cin >> n;
    vi arr(n);
    int mm = 0, m2 = 0;
    forn(i, 0, n){
        cin >> arr[i];
        if (arr[i] == n) mm = i;
        if (arr[i] == n - 1) m2 = i;
    }
    if(n==1){ cout<<1<<endl; return;}
    if(n==2){ cout<<arr[1]<<" "<<arr[0]<<endl; return;}
    if (mm == 0){
        forn(i, m2, n) cout << arr[i] << " ";
        if (m2!=n-1){
            cout << arr[m2-1] << " ";
            m2--;
        }
        forn(i, 0, m2) cout << arr[i] << " ";
        cout << endl;
        return;
    }
    int nn = mm - 1;
    while (mm < n){
        cout << arr[mm] << " ";
        mm++;
    }
    if (nn >= 0 && nn != n - 2){
        cout << arr[nn] << " ";
        nn--;
    }
    while (nn >= 0 && arr[nn] >= arr[0]){
        cout << arr[nn] << " ";
        nn--;
    }
    if (nn == -1){ cout << endl; return; }
    forn(i, 0, nn + 1) cout << arr[i] << " ";
    cout << endl;

}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}