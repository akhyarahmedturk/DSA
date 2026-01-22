/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-22 00:55 (GMT+5)

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
    vi arr(n); input(arr,n);
    sort(all(arr)); 
    set<int> st;
    forn(i,0,m){
        int x; cin>>x; st.insert(x);
    }
    map<int,set<int>> mp;
    int j=0;
    vector<pii> arr3(n);
    forn(i,0,n){
        auto it=st.upper_bound(arr[i]);
        if(it==st.end()){
            arr3[i].ss=inf;
        }
        else {
            arr3[i].ss=*it-arr[i];
            mp[*it-arr[i]].insert(i);
        }
        if(it==st.begin()){
            arr3[i].f=inf;
        }
        else {
            it--;
            arr3[i].f=*it-arr[i];
            mp[*it-arr[i]].insert(i);
        }
    }
    int res=n,dis=0;
    map<int,int> vis; 
    string s; cin>>s;
    for(auto ch:s){
        if(ch=='L') dis--;
        else dis++;
        if(vis[dis]) { cout<<res<<" "; continue;}
        vis[dis]=1;
        if(mp.find(dis)==mp.end()) { cout<<res<<" "; continue;}
        // cout<<ch<<endl;
        res-=mp[dis].size();
        set<int> ya=mp[dis];
        for(auto it:ya){
            int idx=it;
            if(dis>0){
                if(arr3[idx].f!=inf) mp[arr3[idx].f].erase(idx);
            }
            else{
                if(arr3[idx].ss!=inf) mp[arr3[idx].ss].erase(idx);
            }
        }
        cout<<res<<" ";
    }
    cout<<endl;
}

// 0       1
// inf,2  inf,1

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