/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-29 08:53 (GMT+5)

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
// #define mp make_pair
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

void solve(){
    int n;
    cin >> n;
    cin.ignore();
    vector<set<int>> graph(n);
    forn(i, 0, n){
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num) {
            graph[i].insert(num);
        }
    }
    vector<set<int>> graph2(n);
    forn(i, 0, n){
        for (auto it : graph[i]){
            for (int j = 0;j < n;j++){
                if (graph[j].find(it) != graph[j].end()){
                    graph2[i].insert(j);
                    graph2[j].insert(i);
                }
            }
        }
    }
    int src, dst;
    cin >> src >> dst;
    if(src==dst){ cout<<0<<endl; return;}
    queue<int> q;
    for (int i = 0;i < n;i++){
        if (graph[i].find(src) != graph[i].end()){
            q.push(i);
        }
    }
    int res = 0;
    vector<bool> vis(n, false);
    while (!q.empty()){
        int size = q.size();
        while (size--){
            int v = q.front();
            q.pop();
            if (vis[v]) continue;
            if(graph[v].find(dst)!=graph[v].end()){ cout<<res+1<<endl; return;}
            vis[v] = true;
            for(auto it:graph2[v]){
                if(!vis[it]) q.push(it);
            }
        }
        res++;
    }
    cout<<-1<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}