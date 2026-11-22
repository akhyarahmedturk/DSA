/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-21 10:34 (GMT+5)

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
    int x,y; cin>>x>>y;
    int sum=x+y;
    // max number of moves -> (moves*(moves+1))/2<=sum
    int l=0,r=2e5+10,moves=1,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(mid*(mid+1)<=2*sum) moves=mid ,l=mid+1;
        else r=mid-1;
    }
    // now, we have [moves,moves-1,.....1]
    // give some to x, and rem to y
    //ternary search on how much sum to x
    int resx=0,mid1,mid2,total=(moves*(moves+1))/2;
    l=0; r=total;
    while(l<=r){
        mid1=l+(r-l)/3;
        mid2=r-(r-l)/3;
        int x1=mid1,y1=total-mid1;
        int x2=mid2,y2=total-mid2;
        // cout<<l<<" "<<r<<endl;
        // cout<<mid1<<" m1 "<<(x-x1)*(x-x1)+(y-y1)*(y-y1)<<endl;
        // cout<<mid2<<" m2 "<<(x-x2)*(x-x2)+(y-y2)*(y-y2)<<endl;
        if(y1>y) { l=mid1+1; continue;}//x ko zyada do
        if(x2>x) { r=mid2-1; continue;}
        if((x-x2)*(x-x2)+(y-y2)*(y-y2)<(x-x1)*(x-x1)+(y-y1)*(y-y1)){
            resx=x2;
            l=mid1+1;
        }
        else if((x-x2)*(x-x2)+(y-y2)*(y-y2)==(x-x1)*(x-x1)+(y-y1)*(y-y1)){
            resx=x2;
            l=mid1+1;
            r=mid2-1;
        }
        else{
            resx=x1;
            r=mid2-1;
        }
    }
    // cout<<moves<<"      ";
    // cout<<resx<<endl;
    string res="";
    forn(i,0,moves){
        if(resx>=moves-i) res.pb('X') ,resx-=moves-i;
        else res.pb('Y');
        total-=(moves-i);
    }
    cout<<res<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}