/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-06 13:44 (GMT+5)

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

int dfs(int x,int y,vector<string> &graph){
    graph[x][y]='.';
    int res=1;
    if(x!=0 && graph[x-1][y]=='#')  res+=dfs(x-1,y,graph);
    if(y!=0 && graph[x][y-1]=='#') res+=dfs(x,y-1,graph);
    if(x!=graph.size()-1 && graph[x+1][y]=='#') res+=dfs(x+1,y,graph);
    if(y!=graph[0].size()-1 && graph[x][y+1]=='#') res+=dfs(x,y+1,graph);
    return res;
}

int ss(vector<string> &graph){
    forn(i,0,graph.size()){
        forn(j,0,graph[0].size()){
            if(graph[i][j]=='#') return dfs(i,j,graph);
        }
    }
    return 0;
}

void solve() {
    int n,m; cin>>n>>m;
    vector<string> arr(n); input(arr,n);
    int t=0;
    forn(i,0,n){
        forn(j,0,m) t+=(arr[i][j]=='#');
    }
    if(t<=2){ cout<<-1<<endl; return;}
    if(t>=3){
        forn(i,0,n){
            forn(j,0,m){
                if(arr[i][j]=='.') continue;
                vector<string> arr2=arr;
                arr2[i][j]='.';
                if(ss(arr2)!=t-1){ cout<<1<<endl; return; }
            }
        }
        cout<<2<<endl;  
    }
}

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