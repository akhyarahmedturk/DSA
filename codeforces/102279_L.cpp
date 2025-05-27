/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-27 21:27 (GMT+5)

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

void solve() {
    int n,l,r,c,start,end;
    cin>>n>>l>>r>>c>>start>>end;
    start--;
    end--;
    vi arr(n);
    map<int,vector<int>> mp;
    forn(i,0,n){
        cin>>arr[i];
        mp[arr[i]].push_back(i);
    }
    vi dist(n,LONG_LONG_MAX);
    dist[start]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        int idx=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(d>dist[idx]) continue;
        if(idx!=0 && dist[idx-1]>d+l){
            dist[idx-1]=d+l;
            pq.push({dist[idx-1],idx-1});
        }
        if(idx!=n-1 && dist[idx+1]>d+r){
            dist[idx+1]=d+r;
            pq.push({dist[idx+1],idx+1});
        }
        if(mp.find(arr[idx])==mp.end()) continue;
        for(auto it:mp[arr[idx]]){
            if(dist[it]>d+c){
                dist[it]=d+c;
                pq.push({d+c,it});
            }
        }
        mp.erase(arr[idx]);
    }
    cout<<dist[end]<<endl;
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