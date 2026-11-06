/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-10-25 12:26 (GMT+5)

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

// BIT Fenwick Tree

struct BIT{
    int n;
    vi bit;
    BIT(int nn){
        n = nn;
        bit.assign(n + 2, 0);
    }
    // Point update: add 'val' to index 'i'
    void update(int i, int val){ //bit[i]+=x;
        while (i <= n){
            bit[i] += val;
            i += i & -i;
        }
    }
    // Prefix sum: sum[1...i]
    int query(int i){
        int res = 0;
        while (i > 0){
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
};


void solve() {
    int n,q; cin>>n>>q;
    vi arr(n);
    input(arr,n);
    vi aage(n+10,n);
    stack<int>  st;
    forr(i,n-1,0){
        while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
        if(!st.empty()) aage[i]=st.top();
        st.push(i);
    }
    vector<vi> graph(n+10);
    forn(i,0,n) graph[aage[i]].pb(i);
    BIT bit(n+12);
    forn(i,1,n+1) bit.update(i,1);
    vector<vector<int>> qq(q,vi(3));
    forn(i,0,q){
        int a,b; cin>>a>>b;
        qq[i]={b,a,i};
    }
    sort(all(qq));
    int curr=1;
    vi res(n+10,0);
    forn(i,0,q){
        while(curr<qq[i][0]){
            for(auto itt:graph[curr]){
                bit.update(itt+1,-1LL);
            }
            curr++;
        }
        res[qq[i][2]]=bit.query(qq[i][0]);
        if(qq[i][1]) res[qq[i][2]]-=bit.query(qq[i][1]-1);
    }
    forn(i,0,q) cout<<res[i]<<endl;
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