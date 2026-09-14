/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-04-15 08:21 (GMT+5)

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

int ask(vector<int> &arr){
    cout<<"? "<<arr.size()<<" ";
    for(auto it:arr) cout<<it<<" ";
    cout<<endl;
    int x; cin>>x; 
    return x;
}

void solve() {
    int n; cin>>n;
    n=2*n+1;
    int x,y,z;
    int l=1,r=n,mid;
    vi arr;
    forn(i,1,n+1) arr.pb(i);
    while(l<r){
        mid=(l+r)/2;
        vector<int> a,b;
        forn(i,1,mid+1) a.pb(arr[i-1]);
        forn(i,mid+1,n+1) b.pb(arr[i-1]);
        int aa=ask(a),bb=ask(b);
        if(aa==bb){
            if(mid>=3 && (mid-3-aa)%2==0) r=mid;
            else l=mid+1;
        }
        else if(aa>bb) r=mid;
        else l=mid+1;
    }
    x=l;
    arr={};
    forn(i,1,n+1) {
        if(i!=x) arr.pb(i);
    }
    l=1,r=n-1;
    while(l<r){
        mid=(l+r)/2;
        vector<int> a;
        forn(i,1,mid+1) a.pb(arr[i-1]);
        int aa=ask(a);
        a.pb(x);
        int bb=ask(a);
        if(aa==bb || aa==bb+1){
            r=mid;
        }
        else l=mid+1;
    }
    y=arr[l-1];
    arr={};
    forn(i,1,n+1) {
        if(i!=x && i!=y) arr.pb(i);
    }
    l=1,r=n-2;
    while(l<r){
        mid=(l+r)/2;
        vector<int> a;
        forn(i,1,mid+1) a.pb(arr[i-1]);
        int aa=ask(a);
        a.pb(x);
        int bb=ask(a);
        if(aa>bb){
            r=mid;
        }
        else l=mid+1;
    }
    z=arr[l-1];
    cout<<"! "<<x<<" "<<y<<" "<<z<<endl;
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

// 1 1 1 2 2

// 3 2 > L

// 1 1 1 3 2 2 3 4 4

// 4 5 -> 

// 1 1 2 1 2