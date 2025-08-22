/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-29 16:47 (GMT+5)

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

void DFS2(int idx, int par, int top, vector<vi>& graph, vi& marked){
    top++;
    marked[idx] = max(marked[idx], top);
    for (auto it : graph[idx]){
        if (it != par) DFS2(it, idx, top, graph, marked);
    }
}

int DFS(int idx, int par, int curr, vector<vi>& graph, vi& marked){// Not solved
    if (curr != -1) curr++;
    int a=-1, b=-1;
    if (graph[idx].size() == 1){
        a = marked[idx];
        marked[idx] = max(a, curr);
        return a;
    }
    else if (graph[idx].size() == 2){
        if (graph[idx][0] == par){
            a = DFS(graph[idx][1], idx, curr, graph, marked);
        }
        else a = DFS(graph[idx][0], idx, curr, graph, marked);
        if (a != -1) a++;
        marked[idx] = max(marked[idx], max(curr, a));
        return max(a, marked[idx]);
    }
    else{
        // cout<<" ya"<<endl;
        if (graph[idx][0] == par){
            int sent = max(curr, marked[idx]);
            a = DFS(graph[idx][1], idx, sent, graph, marked);
            if (a != -1) a++;
            sent = max(sent, a);
            b = DFS(graph[idx][2], idx, sent, graph, marked);
            if (b != -1) b++;
            if (b > curr){
                DFS2(graph[idx][1], idx, b, graph, marked);
            }
        }
        else if (graph[idx][1] == par){
            int sent = max(curr, marked[idx]);
            a = DFS(graph[idx][0], idx, sent, graph, marked);
            if (a != -1) a++;
            sent = max(sent, a);
            b = DFS(graph[idx][2], idx, sent, graph, marked);
            if (b != -1) b++;
            if (b > curr){
                DFS2(graph[idx][0], idx, b, graph, marked);
            }
        }
        else{
            int sent = max(curr, marked[idx]);
            a = DFS(graph[idx][0], idx, sent, graph, marked);
            if (a != -1) a++;
            sent = max(sent, a);
            b = DFS(graph[idx][1], idx, sent, graph, marked);
            if (b != -1) b++;
            if (b > curr){
                DFS2(graph[idx][0], idx, b, graph, marked);
            }
        }
    }
    marked[idx] = max(curr, max(a, b));
    return max(marked[idx], max(a, b));
}

void solve(){
    int n, k;
    cin >> n >> k;
    vi marked(n, -1);
    forn(i, 0, k){
        int a;
        cin >> a;
        a--;
        marked[a] = 0;
    }
    vector<vi> graph(n);
    forn(i, 0, n - 1){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    forn(i,0,n){
        if(graph[i].size()==1){
            if(marked[i]==0) marked[i]=max(marked[i],DFS(graph[i][0],i, 0, graph, marked));
            else marked[i]=DFS(graph[i][0],i, -1, graph, marked);
            break;
        }
    }
    int mm = INT_MAX;
    forn(i, 0, n){
        // cout << marked[i] << " ";
        mm = min(mm, marked[i]);
    }
    cout << mm << endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}