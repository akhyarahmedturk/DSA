/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-27 21:26 (GMT+5)

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

vi GEL(int n,vi &arr){// >= on left  (index)
    vi res(n);
    stack<pii> st; st.push({inf,-1});
    forn(i,0,n){
        while(!st.empty() && st.top().f<arr[i]) st.pop();
        res[i]=st.top().ss;
        st.push({arr[i],i});
    }
    return res;
}

vi GER(int n,vi &arr){// > on right  (index)
    vi res(n);
    stack<pii> st; st.push({inf,n});
    forr(i,n-1,0){
        while(!st.empty() && st.top().f<=arr[i]) st.pop();
        res[i]=st.top().ss;
        st.push({arr[i],i});
    }
    return res;
}

void solve() {
    int n; cin>>n;
    vi a(n),b(n); input(a,n); input(b,n);
    vi al=GEL(n,a),ar=GER(n,a);
    vi bl=GEL(n,b),br=GER(n,b);
    map<int,int> mpa,mpb;
    forn(i,0,n){
        mpa[a[i]]+=(ar[i]-i)*(i-al[i]);
        mpb[b[i]]+=(br[i]-i)*(i-bl[i]);
    }
    int res=0;
    for(auto it:mpa) {
        cout<<it.f<<" "<<it.ss<<endl;
        res+=it.ss*mpb[it.f];
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