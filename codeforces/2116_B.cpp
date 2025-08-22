/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-31 20:20 (GMT+5)

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

void solve(vi pp) {
    int n;
    cin>>n;
    vi arr1(n),arr2(n),d1(n),d2(n);
    input(arr1,n);
    input(arr2,n);
    forn(i,0,n){
        d1[arr1[i]]=i;
        d2[arr2[i]]=i;
    }
    cout<<(pp[arr1[0]]+pp[arr2[0]])%mod2<<" ";
    int m1=arr1[0],m2=arr2[0];
    forn(i,1,n){
        m1=max(m1,arr1[i]);
        m2=max(m2,arr2[i]);
        if(m1==m2){
            if(arr2[i-d1[m1]]>=arr1[(i-d2[m2])]){
                cout<<(pp[m1]+pp[arr2[i-d1[m1]]])%mod2<<" ";
            }
            else cout<<(pp[m2]+pp[arr1[i-d2[m2]]])%mod2<<" ";
        }
        else if(m1>m2) cout<<(pp[m1]+pp[arr2[i-d1[m1]]])%mod2<<" ";
        else cout<<(pp[m2]+pp[arr1[i-d2[m2]]])%mod2<<" ";
    }
    cout<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    cin >> t;
    vi pp(1e5+10,0);
    pp[0]=1;
    forn(i,1,1e5+9){
        pp[i]=(pp[i-1]*2LL)%mod2;
    }
    while (t--) {
        solve(pp);
    }
    return 0;
}