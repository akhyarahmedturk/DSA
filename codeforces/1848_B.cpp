#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)

void solve() {
    int n,k ,res=LLONG_MAX;
    cin>>n>>k;
    vi last_k(k,0);
    vector<priority_queue<int,vector<int>,greater<int>>> max_diff(k);
    forn(i,1,n+1){
        int x;
        cin>>x;
        x--;
        max_diff[x].push(i-last_k[x]-1);
        if(max_diff[x].size()>2) max_diff[x].pop();
        last_k[x]=i;
    }
    forn(i,0,k){
        max_diff[i].push(n+1-last_k[i]-1);
        if(max_diff[i].size()>2) max_diff[i].pop();
        int a=max_diff[i].top();
        max_diff[i].pop();
        if(!max_diff[i].empty()) res=min(res,max(a,max_diff[i].top()/2));
        else res=min(res,a);
    }
    cout<<res<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}