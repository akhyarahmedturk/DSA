/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-24 19:56 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");
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

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

int aska(int c,int n){
    cout<<"? "<<c<<" "<<n<<" ";
    forn(i,0,n) cout<<i+1<<" ";
    cout<<endl;
    int x; cin>>x;
    return x;
}

int askb(set<int> &rr,int c){
    cout<<"? "<<c<<" "<<rr.size()<<" "<<c<<" ";
    for(auto it:rr) cout<<it+1<<" ";
    int x; cin>>x;
    return x;
}

void solve() {
    int n; cin>>n;
    set<int> rr;
    forn(i,0,n) rr.insert(i+1);
    map<int,vi> mp;
    forn(i,1,n+1){
        int aa=aska(i,n);
        mp[aa].pb(i);
    }
    vector<vi> yaa;
    for(auto it:mp) yaa.pb(it.ss);
    vi res;
    int prv=yaa.back()[0];
    res.pb(prv);
    forr(i,yaa.size()-2,0){
        for(auto it:yaa[i]){
            cout<<"? "<<prv<<" 2 "<<prv<<" "<<it<<endl;
            int a; cin>>a;
            if(a==2){
                prv=it;
                res.pb(prv);
                break;
            }
        }
    }
    cout<<"! ";
    forn(i,0,res.size()) cout<<res[i]<<" ";
    cout<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}