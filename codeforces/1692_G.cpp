/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-20 16:09 (GMT+5)

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

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    vi arr(n+1);
    forn(i,0,n) cin>>arr[i+1];
    int l=-1;
    forn(i,1,n+1){
        if(s[i-1]=='-') continue;
        int curr=arr[i];
        string ya;
        ya.pb(s[i-1]);
        s[i-1]='-'; 
        while(curr!=i){
            ya.pb(s[curr-1]);
            s[curr-1]='-';
            curr=arr[curr]; 
        }
        int c=0;
        string b=ya;
        while(c==0 || ya!=b) { rotate(b.begin(), b.begin() + 1, b.end()); c++;}
        if(l==-1) l=c;
        else l=lcm(l,c);
    }
    cout<<l<<endl;
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