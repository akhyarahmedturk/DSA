/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-03 19:59 (GMT+5)

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
#define yesno(b) cout << ((b) ? "Yes" : "No") << endl;
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

void dfs(int idx,int &curr,int d,string &s,vector<vi> &graph,vector<vi> &mp1,vector<vi> &mp2,vector<pii> &euler){
    d++;
    mp1[d].pb(idx);
    mp2[d].pb(curr);
    euler[idx].f=curr;
    curr++;
    for(auto it:graph[idx]) dfs(it,curr,d,s,graph,mp1,mp2,euler);
    euler[idx].ss=curr;
    curr++;
}

void solve() {
    int n,q; cin>>n>>q;
    vector<vi> graph(n+1);
    forn(i,2,n+1){
        int x; cin>>x;
        graph[x].pb(i);
    }
    string s; cin>>s;
    vector<vi> mp1(n+1),mp2(n+1);
    vector<pii> euler(n+1);
    int curr=1;
    dfs(1,curr,0,s,graph,mp1,mp2,euler);
    // vector<vector<vi>> prefix;
    vector<vi> prefix;
    for(auto it:mp1){
        vi ya={0};
        int c=0;
        for(auto itt:it){
            int cc=(s[itt-1]-'a');
            c=c^(1LL<<cc); 
            ya.pb(c);
        }
        prefix.pb(ya);
    }
    while(q--){
        int x,d; cin>>x>>d;
        if(d>n){ cout<<"Yes"<<endl; continue;}
        int start=lower_bound(all(mp2[d]),euler[x].f)-mp2[d].begin();
        int end=upper_bound(all(mp2[d]),euler[x].ss)-mp2[d].begin();
        // cout<<x<<" "<<start<<" "<<end<<" "<<prefix[d].size()<<endl;
        if(end==0) { cout<<"Yes"<<endl; continue;}
        // vi mp(26,0);
        // forn(i,0,26) mp[i]=prefix[d][end][i]-prefix[d][start][i];
        int c=prefix[d][end] ^ prefix[d][start];
        int cnt=__builtin_popcount(c);
        yesno(cnt<=1);
    }
}

// 1 2 3 4 9 45

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}