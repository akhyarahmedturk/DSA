/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-09 10:44 (GMT+5)

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
    int n,q; cin>>n>>q;
    vi arr(n); input(arr,n);
    int res=1;
    int prv=1;
    forn(i,1,n){
        if(arr[i]==arr[i-1]) prv++;
        else prv=prv+i+1;
        res+=prv;
    }
    while(q--){
        int x,i; cin>>i>>x; i--;
        if(arr[i]==x){ cout<<res<<endl; continue;}
        if(i==0){ //1 1 2 , 1 2 3
            if(n==1) res--;
            else if(arr[i+1]!=arr[i]) {
                if(arr[i+1]==x){
                    res-=(n-1);
                }
            }
            else res+=(n+1);
        }
        else if(i==n-1){// 1 2 2  ,  1 2 3
            if(arr[i-1]!=arr[i]) {
                if(arr[i-1]==x) res-=(n-1);
            }
            else res+=(n-1);
        }
        else{
            if(arr[i-1]==arr[i] && arr[i+1]==arr[i]){
                res+=(i);
                res+=(n-i-1)*(i*2+1);
            }
            else if(arr[i-1]==arr[i]){
                if(arr[i+1]==x){
                    res+=(i);
                    res-=(n-i-1);
                }
                else{
                    res+=(i);
                    res+=(n-i-1)*(i);
                }
            }
            else if(arr[i+1]==arr[i]){
                if(arr[i-1]==x){
                    res+=(n-i-1);
                    res-=(i);
                }
                else res+=(n-i)*(i+1);
            }
            else{
                if(arr[i+1]==x && arr[i-1]==x){
                    res-=(i);
                    res-=(n-i-1)*(i*2+1);
                }
                else if(arr[i+1]==x) {
                    res-=(n-i-1)*(i+1);
                }
                else if(arr[i-1]==x) {
                    res-=(n-i)*(i);
                }
            }
        }
        cout<<res<<endl;
        arr[i]=x;
    }
}
//1 2 2 4 5 6
//1 3 4 8 13 19 -> 47

//1 2 4 4 5 6
//1 3 6 7 12 18 -> 47

//1 2 3 4 5 6
//1 3 6 10 15 21 -> 56

//1 2 2 2 5 6
//1 3 4 5 10 16 -> 39


//1 1 1 2 5
//1 2 3 7 12

// 1 2 3 4 5
// 1 3 6 10 15

// 1 2 3 4 4
// 1 3 6 10 11

// 1 1 2 3 4
// 1 2 5 9 14 


int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}