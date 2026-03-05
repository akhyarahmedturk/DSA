/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-02-16 22:49 (GMT+5)

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


pii ask(int mid){
    cout<<"? "<<mid<<endl;
    pii ya={-1,-1};
    int size;
    cin>>size;
    if(size==-1){ exit(1);}
    if(size==0) return ya;//path hi nahi hy
    cin>>ya.f;
    if(size>1){
        cin>>ya.ss;
        forn(i,0,size-2) {
            int x; cin>>x;
        }
    }
    return ya;
}


void solve() {
    int n; cin>>n;
    vector<vi> arr(n+1);
    int start=1,c=0;
    forn(i,1,n+1){
        start++;
        int l=start,r=1e9,end=start-1,mid;
        while(l<=r){
            mid=(l+r)/2;
            pii ya=ask(mid);
            if(ya.f==i) {
                end=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        while(start<=end){
            pii ya=ask(start);
            int last=ya.ss;
            arr[ya.f].pb(ya.ss);
            c++;
            start++;
            int l=start,r=end,mid,res=end+1;
            while(l<=r){
                mid=(l+r)/2;
                ya=ask(mid);
                if(ya.ss==last) l=mid+1;
                else {
                    res=mid; r=mid-1;
                }
            }
            start=res;
        }
    }
    cout<<"! "<<c<<endl;
    forn(i,1,n+1){
        for(auto it:arr[i]) cout<<i<<" "<<it<<endl;
    }
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