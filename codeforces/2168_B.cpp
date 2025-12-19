/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-10 18:50 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");

*    Those who can’t remember the past are condemned to repeat it.
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
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    int n; cin>>n;
    int a=0,b=0;
    forn(i,0,n){
        int x; cin>>x;
        if(x==1) a=i;
        else if(x==n) b=i;
    }
    cout<<(a<b?'1':'0')<<endl;
}

void s2(){
    int n,x; cin>>n>>x;
    int l=1,r=n-1,mid,start=0,end=n;
    while(l<=r){
        mid=(l+r)/2;
        cout<<"? "<<mid<<" "<<n<<endl;
        int ya; cin>>ya;
        if(ya==n-1) {
            start=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    l=start+1; r=n;
    while(l<=r){
        mid=(l+r)/2;
        cout<<"? "<<start<<" "<<mid<<endl;
        int ya; cin>>ya;
        if(ya==n-1) {
            end=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    if(!x) cout<<"! "<<start<<endl;
    else cout<<"! "<<end<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    string s; cin>>s;
    cin >> t;
    while (t--) {
        if(s=="first") solve();
        else s2();
    }
    return 0;
}