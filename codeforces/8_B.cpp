#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    string s;
    cin>>s;
    int x=0,y=0,n=s.length();
    map<pii,int> mp;
    mp[{x,y}]=-1;
    bool ch=true;
    forn(i,0,n){
        if(s[i]=='R') x++;
        else if(s[i]=='L') x--;
        else if(s[i]=='U') y++;
        else y--;
        if((mp.find({x,y})!=mp.end())) ch=false;
        else if((mp.find({x-1,y})!=mp.end()) && mp[{x-1,y}]!=i-1) ch=false;
        else if((mp.find({x+1,y})!=mp.end()) && mp[{x+1,y}]!=i-1) ch=false;
        else if((mp.find({x,y-1})!=mp.end()) && mp[{x,y-1}]!=i-1) ch=false;
        else if((mp.find({x,y+1})!=mp.end()) && mp[{x,y+1}]!=i-1) ch=false;
        mp[{x,y}]=i;
    }
    // int min_path=abs(y)+abs(x);
    // if(x!=0 && y!=0) min_path--;
    // cout<<min_path<<endl;
    if(ch) cout<<"OK"<<endl;
    else cout<<"BUG"<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}