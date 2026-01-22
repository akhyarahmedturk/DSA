/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-13 15:53 (GMT+5)

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

struct comp{
    bool operator()(pii &a,pii &b){
        return a.f-a.ss < b.f-b.ss;
    }
};


void solve() {
    int n,a,b; cin>>n>>a>>b;
    vector<pii> arr(n);
    forn(i,0,n){
        int x; cin>>x;
        int a=0,b=0; //a=OO bnao  
        //b=EE bnao
        while(x%2==0){ a+=2; x/=2;}
        for(int i=3;i*i<=x;i+=2){
            while(x%i==0){
                x/=i; b+=i;
            }
        }
        if(x>1) b+=x;
        arr[i]={a,b};
    }
    sort(all(arr),comp());
    int res=0;
    forn(i,0,b){
        res+=arr[i].f;
    }
    vector<pii> arr2;
    forn(i,b,n){
        arr2.pb({arr[i].ss,arr[i].f});
    }
    sort(all(arr2),comp());
    forn(i,0,n-b){
        if(i<a) res+=arr2[i].f;
        else res+=min(arr2[i].f,arr2[i].ss);
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