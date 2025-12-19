/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-01 15:59 (GMT+5)

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
    int n,x; cin>>n>>x;
    vi arr(n);
    vi used(n,0);
    input(arr,n);
    vector<pii> res;
    int l=1,r=n+1;
    int idx=0;
    forn(i,0,n) idx=(arr[i]==x)?i:idx;
    bool ya=false;
    while(r-l!=1){
        int mid=(l+r)/2;
        if(mid-1==idx && !ya){
            int yy=r-2;
            forn(i,mid-1,r-1){
                if(arr[i]>x) yy=i;
            }
            swap(arr[yy],arr[idx]);
            res.pb({idx+1,yy+1});
            ya=true;
            idx=yy;
        }
        if(arr[mid-1]>x) r=mid;
        else l=mid;
        arr[mid-1]=0;
    }
    if(l-1!=idx){
        res.pb({l,idx+1});
    }
    cout<<res.size()<<endl;
    for(auto it:res) cout<<it.f<<" "<<it.ss<<endl;
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