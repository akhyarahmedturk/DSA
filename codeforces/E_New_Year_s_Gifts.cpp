/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-30 12:10 (GMT+5)

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
    int n,m,k; cin>>n>>m>>k;
    map<int,int> mp;
    forn(j,0,m){ int x; cin>>x; mp[x]++; }
    vector<pii> arr(n);
    forn(i,0,n){
        int a,b,c; cin>>a>>b>>c;
        arr[i]={a,c-b}; //ya to a wala box ya c-b more coins
        k-=b;
    }
    sort(all(arr));
    if(k<0){ cout<<0<<endl; return;}
    vi vis(n,0);
    set<pii> st;
    int j=0;
    for(auto it:mp){
        int v=it.f,c=it.ss;
        while(j<n && arr[j].f<=v) { st.insert({arr[j].ss,j}); j++; }// vth box sy <= waly saary add karo
        //phir um me sy expensive waly pehly use karlo 
        while(!st.empty() && c){
            c--;
            vis[(--st.end())->ss]=1;
            st.erase((--st.end()));
        }
    }
    int res=0;
    multiset<int> st2;
    forn(i,0,n){
        if(vis[i]) res++;
        else st2.insert(arr[i].ss);
    }
    for(auto it:st2){
        if(k<it) break;
        res++; k-=it;
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