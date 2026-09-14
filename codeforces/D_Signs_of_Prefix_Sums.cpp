/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-09 22:09 (GMT+5)

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
    string s; cin>>s;
    int res=1;
    if(s[0]=='0') {cout<<-1<<endl; return;}
    forn(i,0,n-1){
        if(s[i]=='0' && s[i+1]=='0') {cout<<-1<<endl; return;}
        if((s[i]=='-' && s[i+1]=='+') || (s[i]=='+' && s[i+1]=='-')) res=2;
    }
    int last=-1;
    forn(i,2,n){//0++0 , 0--0  , 0++++0 start me zero he
        if(s[i]=='0' && (i-last)&1) {res=2 ,  last=i;}
    }
    forn(i,0,n-3){//+--+ , -++-
        string ya=s.substr(i,4);
        if(ya=="+--+" || ya=="-++-") res=3;
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

// +----+