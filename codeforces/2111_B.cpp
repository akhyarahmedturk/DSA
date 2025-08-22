/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-03 19:58 (GMT+5)

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
    int n,m;
    cin>>n>>m;
    n+=2;
    vi fib(n,0),area(n);
    fib[2]=1;
    fib[3]=2;
    forn(i,4,n){
       fib[i]=fib[i-1]+fib[i-2]; 
    }
    // cout<<fib[n-1]<<endl;
    forn(i,0,m){
        int a,b,c;
        cin>>a>>b>>c;
        if(a<fib[n-1] || b<fib[n-1] || c<fib[n-1]){ cout<<0; continue;}
        else{
            c-=fib[n-1];
            a-=fib[n-1];
            b-=fib[n-1];
            
            if(c>=fib[n-2] || b>=fib[n-2] || a>=fib[n-2]){ cout<<1; continue;}
            else { cout<<0; continue;}
        }
    }
    cout<<endl;
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