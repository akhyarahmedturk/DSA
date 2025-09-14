/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-07 22:09 (GMT+5)

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

vector<vi> arr;

bool check(int mid,int n){
    forn(i,0,arr.size()){
        int v=arr[i][0]*arr[i][1]+arr[i][2];
        int cc=(mid)/v;
        n-=cc*arr[i][1];
        int diff=mid-cc*v;
        int ya=diff/arr[i][0];
        n-=min(ya,arr[i][1]);
    }
    return n<=0;
}

void solve(int tt) {
    int k,x; cin>>k>>x;
    vi res;
    int a=x,b=(1LL<<(k+1));
    int t=b;
    b-=x;
    while(a!=b){
        if(a>b){
            res.pb(2);
            b*=2;
            a=t-b;
        }
        else{
            res.pb(1);
            a*=2;
            b=t-a;
        }
    }
    reverse(all(res));
    cout<<res.size()<<endl;
    forn(i,0,res.size()) cout<<res[i]<<" ";
    if(res.size()) cout<<endl;
}
//13 3,10 6, 4 12,8,8          7 11,14 2,12 4,8 8
// 7 9,14 2, 12 4,8 8

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin >> t;
    forn(i,0,t) {
        solve(i);
    }
    return 0;
}