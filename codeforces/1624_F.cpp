/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-27 09:44 (GMT+5)

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

void solve() {
    int h,d; cin>>h>>d;
    int l=0,rr=d+10,mid,res=2*d;//worse
    while(l<=rr){
        mid=(l+rr)/2;
        int hh=h+mid;
        int r=mid+1;
        int a=d%r,b=r-d%r;
        int v1=d/r,v2=d/r+1;
        hh-=((v1*(v1+1))/2) * b ; 
        hh-=((v2*(v2+1))/2) * a ; 
        if(hh>0){ res=mid; rr=mid-1;}
        else l=mid+1;
    }
    cout<<res+d<<endl;
}
// 8 5 
// 1

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
// 10 7
//  0->3 rem=4+1=>5 4
//  3->5 rem=2+1=>3 3
// 
// 30
// 2-> 3-1 per t -> 30/2 15-> 15*(3+1) 60->30  
// 3-> 6-1 per t -> 30/5 6-> 6*(6+1) 42-> 18 ->