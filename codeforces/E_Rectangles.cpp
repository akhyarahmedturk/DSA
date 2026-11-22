/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-20 10:39 (GMT+5)

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
    int n; cin>>n;
    vector<vi> a1(n),a2(n);
    forn(i,0,n){
        int a,b,x,y; cin>>a>>b>>x>>y;
        a1[i]={a,b,x,y,i+1};
        a2[i]={b,a,x,y,i+1};
    }
    sort(all(a1)) , sort(all(a2));
    set<pii> st;
    int sum=(n*(n+1))/2;
    forn(i,0,n){
        while(!st.empty() && st.begin()->f<a1[i][0]){
            sum+=st.begin()->ss;
            st.erase(st.begin());
        }
        sum-=a1[i][4];
        st.insert({a1[i][2],a1[i][4]});
        if(st.size()>=n-1){
            set<pii> sty;
            forn(j,0,n){
                while(!sty.empty() && sty.begin()->f<a2[j][0]){
                    sty.erase(sty.begin());
                }
                if(a2[j][4]!=sum) sty.insert({a2[j][3],a2[j][4]});
                if(sty.size()>=n-1){
                    cout<<a1[i][0]<<" "<<a2[j][0]<<endl;
                    return;
                }
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
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// 0 3 6 9 12
// 3 0 3 6 9