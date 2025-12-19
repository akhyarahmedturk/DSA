/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-30 12:08 (GMT+5)

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

// pehly a ko zero bnao
// phir zero ko b bnao( b ko zero bnao)
// 101 ,010  ->zero nahi bna sakty???? length hi >=4 hy to hamesha bna sakty na!!!
// koi bhi 2 1/0 aik sath chahy un ko phir left/right expend karo
// 110011 , 000000 2 steps me
// 101011 , 010011,010000,011111,000000 
// 10101, 01010/10010, 2nd waly me 2 zero 1 sakt ab bna sakty 

vector<pii> ss(string s){
    int l=-1,r,n=s.length();
    vector<pii> res;
    forn(i,1,n){
        if(s[i]==s[i-1]){
            l=i-1; r=i;
            break;
        }
    }
    if(l==-1){// 1010101 / 010101   first 3 ko ulta karo
        res.pb({1,3});
        s[0]=(s[0]=='1'?'0':'1');
        s[1]=(s[1]=='1'?'0':'1');
        s[2]=(s[2]=='1'?'0':'1');
        l=2; r=3;
    }
    bool ya=(s[l]=='1');
    while(l>0){
        if((ya && s[l-1]=='1') || (!ya && s[l-1]=='0')) l--;
        else{
            res.pb({l+1,r+1});
            ya=!ya;
            l--;
        }
    }
    while(r<n-1){
        if((ya && s[r+1]=='1') || (!ya && s[r+1]=='0')) r++;
        else{
            res.pb({l+1,r+1});
            ya=!ya;
            r++;
        }
    }
    if(ya) res.pb({1,n});//agar end me 1 hogai to poory ko zero bhi karo
    return res;
}

void solve() {
    int n; cin>>n;
    string a,b; cin>>a>>b;
    vector<pii> ya1=ss(a);
    vector<pii> ya2=ss(b);
    reverse(all(ya2));
    cout<<ya1.size()+ya2.size()<<endl;
    for(auto it:ya1) cout<<it.f<<" "<<it.ss<<endl;
    for(auto it:ya2) cout<<it.f<<" "<<it.ss<<endl;
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