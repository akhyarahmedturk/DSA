/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-27 21:11 (GMT+5)

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
    int n,m; cin>>n>>m;
    vector<pii> res;
    if(m==0){
        vector<pii> arr(n);
        forn(i,0,n){
            cin>>arr[i].f; arr[i].ss=i;
        }
        sort(all(arr));
        int sum=0;
        forn(i,0,n-2) sum+=arr[i].f;
        if(sum<(arr[n-1].f-arr[n-2].f)){ cout<<-1<<endl; return;}
        int i=0;
        while(arr[n-2].f<arr[n-1].f){
            res.pb({arr[i].ss,arr[n-1].ss});
            arr[n-1].f-=arr[i].f;
            i++;
        }
        while(i<n-2){
            res.pb({arr[i].ss,arr[i+1].ss});
            i++;
        }
        res.pb({arr[n-1].ss,arr[n-2].ss});
    }
    else{
        set<pii> st; 
        forn(i,0,n) { int x; cin>>x; st.insert({x,i});}
        if(m>n/2){ cout<<-1<<endl; return;}
        while(st.size()>m*2){
            pii it=*st.begin(); st.erase(st.begin());
            pii itt=*st.begin();
            res.pb({it.ss,itt.ss});
        }
        while(st.size()>0){
            pii it=*st.begin(); st.erase(st.begin());
            pii itt=*st.begin(); st.erase(st.begin());
            res.pb({itt.ss,it.ss});
        }
    }
    cout<<res.size()<<endl;
    for(auto it:res) cout<<it.f+1<<" "<<it.ss+1<<endl;
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