/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-07 13:26 (GMT+5)

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
    int n,m,prv=0;
    cin>>n;
    vector<vi> dist(n,vi(n,inf));
    forn(i,0,n){
        forn(j,0,n){
            cin>>dist[i][j];
            prv+=dist[i][j];
        }
    }
    prv/=2;
    int k;
    cin>>k;
    while(k--){
        int a,b,w;
        cin>>a>>b>>w;
        a--; b--;
        if(dist[a][b]<=w){ cout<<prv<<" "; continue;}
        dist[a][b]=w;
        dist[b][a]=w;
        forn(i,0,n){
            forn(j,0,n){
                dist[i][j]=min(dist[i][j],dist[i][a]+w+dist[b][j]);
                dist[i][j]=min(dist[i][j],dist[i][b]+w+dist[a][j]);
                // if(i==1 && j==2) cout<<dist[i][j]<<" dcv  ";
            }
        }
        prv=0;
        forn(i,0,n){
            forn(j,0,n){
                prv+=dist[i][j];

            }
        }
        prv/=2;
        cout<<prv<<" ";
    }
    cout<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}