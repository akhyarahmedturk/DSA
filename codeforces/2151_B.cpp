/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-24 21:22 (GMT+5)

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

void solve() {
    int n,m; cin>>n>>m;
    string s; cin>>s;
    ordered_set<int> st;
    forn(i,0,m){ int x; cin>>x; st.insert(x);}
    vi res;
    if(*st.begin()==1) { res={1}; st.erase(st.begin()); }
    char prv='A';
    int last=1;
    for(auto it:s){
        if(prv=='A'){
            if(it=='A'){
                last++;
                if(!st.empty() && *st.begin()==last){st.erase(st.begin());}
            }
            else{
                last++;
                while(!st.empty() && *st.begin()==last){ st.erase(st.begin()); res.pb(last); last++;}
            }
        }
        else{
            if(it=='A'){
                last++;
                while(!st.empty() && *st.begin()==last){ st.erase(st.begin()); res.pb(last); last++;}
                last++;
                if(!st.empty() && *st.begin()==last){st.erase(st.begin());}
            }
            else{
                last++;
                while(!st.empty() && *st.begin()==last){ st.erase(st.begin()); res.pb(last); last++;}
                last++;
                while(!st.empty() && *st.begin()==last){ st.erase(st.begin()); res.pb(last); last++;}
            }
        }
        prv=it;
        res.pb(last);
    }
    for(auto it:st) res.pb(it);
    cout<<res.size()<<endl;
    for(auto it:res) cout<<it<<" ";
    if(res.size()) cout<<endl;
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