/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-08 21:44 (GMT+5)

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

bool check(int mid,vi &arr,int a,int b){
    int idx=mid-1;
    while(idx>=0){
        if(a<b) swap(a,b);
        if(arr[idx]<=b) b-=arr[idx];
        else if(arr[idx]<=a) a-=arr[idx];
        else return false;
        idx--;
    }
    return true;
}

void solve() {
    int n,k; cin>>n>>k;
    vector<vi> graph(n);
    forn(i,1,n){
        int a,b; cin>>a; a--;
        graph[a].pb(i);
    }
    vi ya;
    queue<int> q;
    q.push(0);
    while(1){
        int size=q.size();
        ya.pb(size);
        bool chh=false;
        while(size--){
            bool ch=false;
            int u=q.front();
            q.pop();
            for(auto it:graph[u]){
                ch=true; q.push(it);
            }
            if(!ch) chh=true;
        }
        if(chh) break;
    }
    int l=1,r=ya.size(),mid,res;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid,ya,k,n-k)){
            res=mid; l=mid+1;
        }
        else r=mid-1;
    }
    cout<<res<<endl;
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