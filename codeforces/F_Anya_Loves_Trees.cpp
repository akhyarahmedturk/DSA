/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-07-14 21:29 (GMT+5)

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
    int n; cin>>n;
    vector<vi> graph(n+1);
    forn(i,0,n-1){
        int x; cin>>x; 
        graph[x].pb(i+2);
    }
    vi arr(n); input(arr,n);
    deque<int> q; q.push_back(1);
    while(!q.empty()){
        int size=q.size();
        vector<vi> ya;
        while(size--){
            ya.pb({});
            int idx=q.front(); q.pop_front();
            for(auto it:graph[idx]) {
                ya.back().pb(arr[it-1]) , q.push_back(it);
            }
            if(ya.back().size()==0) ya.pop_back();
            else{
                vi yaa=ya.back(); sort(all(yaa));
                if(yaa!=ya.back()){
                    bool a=true;
                    forn(i,1,ya.back().size()-1){
                        if(ya.back()[i]<ya.back()[i-1]) a=false;
                    }
                    if(!a || ya.back()[0]<ya.back().back()) { cout<<"NO"<<endl; return;}
                }
                sort(all(ya.back()));
            }
        }
        if(ya.size()==0) break;
        if(ya.size()==1) continue;
        bool a=true;
        forn(i,1,ya.size()){
            if(ya[i-1].back()>ya[i][0]) { a=false; break; }
        }
        if(a) continue;
        a=true;
        forn(i,2,ya.size()){
            if(ya[i-1].back()>ya[i][0]) { a=false; break; }
        }
        if(a && ya[0][0]<ya.back().back()) {
            cout<<"NO"<<endl; return;
        }
        q.push_front(q.back());
        q.pop_back();
    }
    cout<<"YES"<<endl;
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