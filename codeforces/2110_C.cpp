/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-24 19:53 (GMT+5)

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
    int n;
    cin>>n;
    vi arr(n);
    vector<pii> r(n);
    vector<pii> pr(n+1,{0,0});
    input(arr,n);
    forn(i,0,n){
        cin>>r[i].first>>r[i].second;
    }
    forn(i,1,n+1){
        pr[i]=pr[i-1];
        if(arr[i-1]==1) {pr[i].first++; pr[i].second++;}
        if(arr[i-1]==-1) pr[i].second++;
        pr[i].first=max(pr[i].first,r[i-1].first);
        pr[i].second=min(pr[i].second,r[i-1].second);
        if(pr[i].first>pr[i].second) {cout<<-1<<endl; return;}
    }
    int pos=pr[n].second;
    forr(i,n-1,1){
        if(arr[i]==-1){
            if(pos<=pr[i].second) arr[i]=0;
            else {arr[i]=1; pos--;}
        }
        else pos-=arr[i];
    }
    if(arr[0]==-1){
        if(pos>0) arr[0]=1;
        else arr[0]=0;
    }
    forn(i,0,n) cout<<arr[i]<<" ";
    cout<<endl;
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