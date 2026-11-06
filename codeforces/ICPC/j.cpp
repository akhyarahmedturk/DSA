/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-10-25 13:18 (GMT+5)

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
    vi arr(26); input(arr,26);
    // vector<vector<vi>> graph(26,vector<vi>(26,vi(26,0)));
    map<int,map<int,map<int,int>>> graph;
    int m; cin>>m;
    forn(i,0,m){
        char a,b,c; cin>>a>>b>>c;
        graph[b-'a'][c-'a'][a-'a']=1;
        graph[c-'a'][b-'a'][a-'a']=1;
    }
    string s; cin>>s;
    vector<int> vals(26,inf);
    set<pii> st;
    forn(i,0,26){
        if(arr[i]!=-1) st.insert({arr[i],i}) , vals[i]=arr[i];
    }
    while(!st.empty()){
        int v=st.begin()->f,ch=st.begin()->ss;
        st.erase(st.begin());
        if(vals[ch]<v) continue;
        for(auto it:graph[ch]){
            if(vals[it.f]==inf) continue;
            for(auto itt:it.ss){
                if(itt.ss){
                    if(vals[itt.f]>v+vals[it.f]) vals[itt.f]=v+vals[it.f] , st.insert({v+vals[it.f],itt.f});
                }
            }
        }
    }
    int res=0;
    for(auto it:s){
        if(vals[it-'a']==inf) { cout<<-1<<endl; return;}
        res+=vals[it-'a'];
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