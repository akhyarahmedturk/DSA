
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
// #define mp make_pair
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void med(multiset<int> &pq_min,multiset<int> &pq_max,int add){
    if(pq_min.size()==0) pq_min.insert(add);
    else if(add>*(pq_min.rbegin())) pq_max.insert(add);
    else pq_min.insert(add);
    if(pq_min.size()>pq_max.size()+1){
        pq_max.insert(*(pq_min.rbegin()));
        pq_min.erase(prev(pq_min.end()));
    }
    else if(pq_min.size()<pq_max.size()){
        pq_min.insert(*(pq_max.begin()));
        pq_max.erase(pq_max.begin());
    }
}

void solve() {
    int n,k;
    cin>>n>>k;
    vi arr(n);
    input(arr,n);
    int prv=-1;
    multiset<int> pq_min,pq_max;
    forn(i,0,n-1){
        med(pq_min,pq_max,arr[i]);
        if(*(pq_min.rbegin())<=k){
            prv=i+1;
            break;
        }
    }
    // cout<<" vx";
    int ans=-1;
    if(prv!=-1) ans=prv-1;
    if(prv==-1) prv=n;
    while(prv<n-1){
        if(arr[prv]<=k) {yesno(true); return;}
        med(pq_min,pq_max,arr[prv]);
        if(*(pq_min.rbegin())>k){
            break;
        }
        prv++;
    }
    // cout<<" ya1 "<<prv<<endl;
    multiset<int> pq1_min,pq1_max;
    while(prv<n-1){
        if(arr[prv]<=k) {yesno(true); return;}
        med(pq1_min,pq1_max,arr[prv]);
        if(*(pq1_min.rbegin())<=k) {yesno(true); return;}
        prv++;
    }
    multiset<int> pq2_min,pq2_max;
    prv=-1;
    // cout<<" ya "<<prv<<endl;
    forr(i,n-1,1){
        med(pq2_min,pq2_max,arr[i]);
        if(*(pq2_min.rbegin())<=k){
            prv=i-1;
            break;
        }
    }
    if(ans<prv && ans!=-1) {yesno(true); return;}
    if(prv==-1) prv=0;
    while(prv>=1){
        if(arr[prv]<=k) {yesno(true); return;}
        med(pq2_min,pq2_max,arr[prv]);
        if(*(pq2_min.rbegin())>k){
            break;
        }
        prv--;
    }
    multiset<int> pq3_min,pq3_max;
    while(prv>=1){
        if(arr[prv]<=k) {yesno(true); return;}
        med(pq3_min,pq3_max,arr[prv]);
        if(*(pq3_min.rbegin())<=k) {yesno(true); return;}
        prv--;
    }
    yesno(false);
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}