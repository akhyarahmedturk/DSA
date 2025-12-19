/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-13 19:33 (GMT+5)

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

void solve() {//not solved
    int n; 
    cin>>n;
    vector<vi> arr(n);
    forn(i,0,n){
        int k; cin>>k;
        arr[i].resize(k);
        forn(j,0,k){ cin>>arr[i][j]; }
    }
    sort(all(arr),[&](vi &a,vi&b){
        return a.size()<b.size();
    });
    int mx=arr.back().size();
    vector<pii> res(mx,{inf,-1});
    forn(i,0,n){
        bool ch=false;
        int nn=0;
        int size=arr[i].size();
        forn(j,0,size){
            if(nn==j){
                if(res[j].f>arr[i][j]) ch=true;
                else if(res[j].f<arr[i][j]) { nn=res[j].ss; }
                else{
                    bool ya=false;
                    int l=j,r=res[j].ss;
                    while(l<=r){
                        if(arr[i][l]==res[l].f){ l++; continue;}
                        else if(arr[i][l]<res[l].f){ ya=true;}
                        break;
                    }
                    if(ya) ch=true;
                    else nn=res[j].ss;
                }
            }
            if(ch) res[j]={arr[i][j],size};
            // cout<<"i "<<i<<" f "<<res[j].f<<" ss "<<res[j].ss<<endl;
        }
    }
    forn(i,0,mx) cout<<res[i].f<<" ";
    cout<<endl;
}
// 2 4 6 6 8 3 5 7
// 

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}