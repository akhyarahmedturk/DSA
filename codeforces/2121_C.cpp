/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-17 19:47 (GMT+5)

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
    int n,m,mx=0,a,b;
    cin>>n>>m;
    vector<vector<int>> arr(n,vi(m));
    forn(i,0,n){
        forn(j,0,m){
            cin>>arr[i][j];
            if(arr[i][j]>mx){
                mx=arr[i][j];
                a=i;
                b=j;
            }            
        }
    }
    forn(i,0,n){
        int c=0;
        forn(j,0,m){
            if(arr[i][j]==mx) c++;             
        }
        if(c>1){
            forn(k,0,m) arr[i][k]--;
            set<int> st;
            forn(l,0,n){
                forn(y,0,m){
                    if(arr[l][y]==mx) st.insert(y);
                    if(st.size()==2){ cout<<mx<<endl; return;}          
                }
            }
            cout<<mx-1<<endl;
            return;
        }
    }
    forn(i,0,m){
        int c=0;
        forn(j,0,n){
            if(arr[j][i]==mx) c++;             
        }
        if(c>1) b=i;
    }
    forn(i,0,n) arr[i][b]--;
    set<int> st;
    forn(i,0,n){
        forn(j,0,m){
            if(arr[i][j]==mx) st.insert(i);
            if(st.size()==2){ cout<<mx<<endl; return;}          
        }
    }
    cout<<mx-1<<endl;
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