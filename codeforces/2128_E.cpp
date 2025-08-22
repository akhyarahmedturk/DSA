/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-27 21:10 (GMT+5)

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

pii check(int k,int mid,vi &arr){
    int n=arr.size();
    vi b(n,-1);
    forn(i,0,n){ 
        if(arr[i]>=mid) b[i]=1;
    }
    int curr=0;
    vi sum(n);
    int mm=0,m_idx=0;
    forn(i,0,n){
        curr+=b[i];
        sum[i]=curr;
        if(i==k-1 && curr>=0) return {m_idx+1,i+1};
        else if(i>=k){
            if(mm>sum[i-k]){
                mm=sum[i-k];
                m_idx=i-k+1;
            }
            if(curr-mm>=0) return {m_idx+1,i+1};
        }
    }
    return {-1,-1};
}

void solve() {
    int n,k;
    cin>>n>>k;
    vi arr(n); input(arr,n);
    int l=1,r=n,mid,res=0;
    pii val={-1,-1};
    while(l<=r){
        mid=(l+r)/2;
        pii ya=check(k,mid,arr);
        if(ya.first!=-1){ 
            res=mid; 
            l=mid+1;
            val=ya;
        }
        else r=mid-1;
    }
    cout<<res<<" "<<val.first<<" "<<val.second<<endl;
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