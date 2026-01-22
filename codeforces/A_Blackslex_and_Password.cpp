/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-23 19:46 (GMT+5)

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
    int n,x,y; cin>>n>>x>>y;
    string s; cin>>s;
    vi arr(n); input(arr,n);
    int sum=accumulate(all(arr),0LL);
    if(sum>x+y){ cout<<"NO"<<endl; return;}
    int mm1=x,mm2=y;
    int countz=0;
    vector<pii> a,b;
    forn(i,0,n){
        if(s[i]=='0') {
            countz++;
            mm1-=(arr[i]+2)/2; mm2-=arr[i]-(arr[i]+2)/2;
            a.pb({(arr[i]+2)/2,arr[i]-(arr[i]+2)/2});
        }
        else{
            mm2-=(arr[i]+2)/2;  mm1-=arr[i]-(arr[i]+2)/2;
            b.pb({(arr[i]+2)/2,arr[i]-(arr[i]+2)/2});
        }
    }
    if(mm1+mm2<0) { cout<<"NO"<<endl; return;}
    if(mm1<0){
        for(auto &it:b){
            int v=min(it.ss,abs(mm1));
            it.ss-=v; it.f+=v; mm1+=v;
        }
        if(mm1<0){ cout<<"NO"<<endl; return;}
    }
    else if(mm2<0){
        for(auto &it:a){
            int v=min(it.ss,abs(mm2));
            it.ss-=v; it.f+=v; mm2+=v;
        }
        if(mm2<0){ cout<<"NO"<<endl; return;}
    }
    if(!a.empty()) { a[0].first+=mm1; mm1=0;}
    if(!b.empty()) { b[0].first+=mm2;   mm2=0;}
    if(mm1>0){
        for(auto it:b){
            int v=min(mm1,it.f-it.ss-1);
            mm1-=v;
        }
        if(mm1) { cout<<"NO"<<endl; return;}
    }
    if(mm2>0){
        for(auto it:a){
            int v=min(mm2,it.f-it.ss-1);
            mm2-=v;
        }
        if(mm2) { cout<<"NO"<<endl; return;}
    }
    cout<<"YES"<<endl;
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