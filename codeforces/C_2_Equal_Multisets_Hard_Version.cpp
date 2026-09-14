/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-03-30 18:08 (GMT+5)

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
    int n,k; cin>>n>>k;
    vi a(n+1),b(n+1);
    forn(i,1,n+1) cin>>a[i];
    forn(i,1,n+1) cin>>b[i];
    map<int,int> mp1,mp2;
    set<int> st; // -1 indices
    multiset<int> st2;
    int d=0;
    forn(i,1,n+1){
        if(mp1[a[i]]>=mp2[a[i]]) { d++; st2.insert(a[i]); }
        else { d--; }
        mp1[a[i]]++;

        if(b[i]==-1) st.insert(i);
        else if(mp2[b[i]]>=mp1[b[i]]) d++;
        else { d--; st2.erase(st2.find(b[i])); }
        if(b[i]!=-1) mp2[b[i]]++;
        if(i>=k){
            if(st2.size()>st.size()){ cout<<"NO"<<endl; return;}
            else {
                
            } 
        }
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