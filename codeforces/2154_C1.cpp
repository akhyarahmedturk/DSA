/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-19 20:44 (GMT+5)

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
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void add(int x,vi &mp,int cost){
    if(x%2==0) mp[2]+=cost;
    while(x%2==0){ x/=2;}
    for(int j=3;j*j<=x;j+=2){
        if(x%j==0){
            mp[j]+=cost;
            while(x%j==0) x/=j;
        }
    }
    if(x>1) mp[x]+=cost;
}

void solve(){
    int n; cin>>n;
    vi a(n),b(n); input(a,n); input(b,n);
    vi mp(2e5+10,0),mp2(2e5+10,0);
    vi mp(2e5)
    int res=inf;
    forn(i,0,n) add(a[i],mp,1);
    for(auto it:mp){ 
        if(it>=2){ cout<<0<<endl; return;}
    }
    forn(i,0,n){
        add(a[i],mp,-1);//isko nikalo

    }
    cout<<res<<endl;
}

//cost[x]=min( (x-a[1])*b[1] ,(x-a[2]*b[2]) .....)
//cost[x+1]=min( (x+1-a[1])*b[1] ,(x+1-a[2]*b[2]) .....)

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