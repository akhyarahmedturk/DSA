/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-25 10:25 (GMT+5)

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
    vi arr(n); input(arr,n);
    string s; cin>>s;
    vi ya(n+1,0);
    int one=0,zero=0;
    forn(i,0,n){
        if(s[i]=='1') one^=arr[i];
        else zero^=arr[i];
        ya[i+1]=ya[i]^arr[i];
    }
    int q; cin>>q;
    while(q--){
        int a; cin>>a;
        if(a==1){
            // string sy farq nahi parta
            // range me agar odd no of bits hongi to ans^=bit hoga
            // like range me 2->1 ki thi 3->0 ki
            // to inv sy pehly 1->me impact 0 hoga, 0 me impact 1 hoga
            int l,r; cin>>l>>r;
            int yaa=ya[r]^ya[l-1];
            one^=yaa; zero^=yaa;
        }
        else{
            int x; cin>>x;
            if(x==1) cout<<one<<" ";
            else cout<<zero<<" ";
        }
    }
    cout<<endl;
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