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

string res="",str;

void sol(int idx,int fours,string &curr){
    if(idx==curr.length()){
        if(curr>=str){
            if(res=="") res=curr;
            else if(curr<res) res=curr;
        }
    }
    else if(fours==curr.length()/2){
        curr[idx]='7';
        sol(idx+1,fours,curr);
    }
    else if((idx-fours)==curr.length()/2){
        curr[idx]='4';
        sol(idx+1,fours+1,curr);
    }
    else{
        curr[idx]='7';
        sol(idx+1,fours,curr);
        curr[idx]='4';
        sol(idx+1,fours+1,curr);
    }
}

void solve() {
    int n,len;
    cin>>n;
    str=to_string(n);
    len=str.length();
    if(len%2==0){
        string curr(len,' ');
        sol(0LL,0LL,curr);
    }
    if(res!="") cout<<res<<endl;
    else{
        for(int i=0;i<(len+2)/2;i++) cout<<'4';
        for(int i=0;i<(len+2)/2;i++) cout<<'7';
        cout<<endl;
    }
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