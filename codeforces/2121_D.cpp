/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-17 20:36 (GMT+5)

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
    int n;
    cin>>n;
    vector<pair<int,int>> idx(2*n+1),res;
    vi a(n),b(n);
    forn(i,0,n){
        cin>>a[i];
        idx[a[i]]={1,i};
    }
    forn(i,0,n){
        cin>>b[i];
        idx[b[i]]={2,i};
    }
    forn(i,1,n+1){
        if(idx[i].first==1){
            int m=idx[i].second-1;
            forr(j,m,i-1){
                idx[a[j+1]]={1,j};
                idx[a[j]]={1,j+1};
                swap(a[j],a[j+1]);
                res.pb({1,j+1});
            }
        }
        else{
            if(idx[i].second>=i-1){
                int m=idx[i].second-1;
                forr(j,m,i-1){
                    idx[b[j+1]]={2,j};
                    idx[b[j]]={2,j+1};
                    swap(b[j],b[j+1]);
                    res.pb({2,j+1});
                }
            }
            else{
                int m=idx[i].second;
                forn(j,m,i-1){
                    idx[b[j+1]]={2,j};
                    idx[b[j]]={2,j+1};
                    swap(b[j],b[j+1]);
                    res.pb({2,j+1});
                }
            }
            idx[b[i-1]].first=1;
            idx[a[i-1]].first=2;
            swap(a[i-1],b[i-1]);
            res.pb({3,i});
        }
    }
    forn(i,n+1,2*n+1){
        int m=idx[i].second-1;
        // if(i==3) cout<<" c "<<m<<endl;
        forr(j,m,i-n-1){
            idx[b[j+1]]={2,j};
            idx[b[j]]={2,j+1};
            swap(b[j],b[j+1]);
            res.pb({2,j+1});
        }
    }
    cout<<res.size()<<endl;
    forn(i,0,res.size()){
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
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