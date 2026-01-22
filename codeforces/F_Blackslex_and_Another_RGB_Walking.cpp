/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-23 21:49 (GMT+5)

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
    int n,m; cin>>n>>m;
    vector<vi> graph(n);
    forn(i,0,m){
        int a,b; cin>>a>>b; a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    string s(n,'-');
    queue<int> q;
    string ya="gbr";
    int level=0;
    q.push(0);
    s[0]=ya[0];
    while(!q.empty()){
        int size=q.size();
        level++;
        while(size--){
            int idx=q.front(); q.pop();
            for(auto it:graph[idx]){
                if(s[it]=='-'){
                    s[it]=ya[level%3];
                    q.push(it);
                }
            }
        }
    }
    cout<<s<<endl;
}

void solve2() {
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        string s; cin>>s;
        int c1=-1,c2=-1,c3=-1;
        string ya="gbr";
        forn(i,0,n){
            if(s[i]=='g') c1=i;
            else if(s[i]=='b') c2=i;
            else c3=i;
        }
        if(c2==-1){// abhi b per ho / ya g per 
            if(c1!=-1) cout<<c1+1<<endl;// b per ho
            else cout<<c3+1<<endl;// g per ho
        }
        else if(c3==-1){//abhi r per ho  -> b per jao
            cout<<c2+1<<endl;
        }
        else{// g per ho
            cout<<c3+1<<endl;
        }
    }
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    string s; cin>>s;
    int t=1;
    cin >> t;
    while (t--) {
        if(s=="first") solve();
        else solve2();
    }
    return 0;
}