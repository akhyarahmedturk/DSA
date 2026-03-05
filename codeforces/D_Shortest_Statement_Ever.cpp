/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-02-25 14:20 (GMT+5)

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

pii dfs(int curr,int idx,int &val,int &val2){
    if(idx==-1) return {val-curr,curr};
    else if((1LL<<idx)&val2) return dfs(curr,idx-1,val,val2);// dosry me y bit on hy to yhan nahi le sakty
    else if(curr+(1LL<<idx)<=val){ // agar y bit lene ky bad bhi val sy kam hy to multiple option hen
        int next=curr+(1LL<<(idx+1))-1;
        next-=(val2&next);
        // agar aagy wali saari bits on kar ky bhi < val ho to direct on kardo sabko
        if(next>val){
            // ab dono option try karny hongy
            pii ya=dfs(curr,idx-1,val,val2);
            pii ya2=dfs(curr+(1LL<<idx),idx-1,val,val2);
            if(ya.f<ya2.f) return ya;
            else return ya2;
        }
        else return {val-next,next};
    }
    else{
        // as absolute diff hy thora uper jaa ky bhi dekh sakty
        pii ya=dfs(curr,idx-1,val,val2);
        if(ya.f<curr+(1LL<<idx)-val) return ya;
        else return {curr+(1LL<<idx)-val,curr+(1LL<<idx)};
    }
}

void solve() {
    int a,b; cin>>a>>b;
    if(a&b==0) { cout<<a<<" "<<b<<endl; return;}
    //aik ko same rakho dosry ki liy diff values py try karo
    int p=a;
    pii ya=dfs(0,30,b,p);
    int qq=b;
    pii ya2=dfs(0,30,a,qq);
    if(ya2.f<ya.f) cout<<ya2.ss<<" "<<qq<<endl;
    else cout<<p<<" "<<ya.ss<<endl;
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