/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-12 21:25 (GMT+5)

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

bool check(int mid,int k,vi arr){
    int n=arr.size();
    multiset<pii> st;
    forn(i,0,n) st.insert({arr[i],i});
    while(!st.empty()){
        int idx=(--st.end())->ss; st.erase(--st.end());
        if(arr[idx]==-1) continue;
        if(arr[(idx-1+n)%n]!=-1 && arr[idx]-arr[(idx-1+n)%n]>mid){
            k-=((arr[idx]-arr[(idx-1+n)%n])-mid);
            arr[(idx-1+n)%n]=arr[idx]-mid;
        }
        if(arr[(idx+1+n)%n]!=-1 && arr[idx]-arr[(idx+1+n)%n]>mid){
            k-=((arr[idx]-arr[(idx+1+n)%n])-mid);
            arr[(idx+1+n)%n]=arr[idx]-mid;
        }
        arr[idx]=-1;
        if(arr[(idx-1+n)%n]!=-1) st.insert({arr[(idx-1+n)%n],(idx-1+n)%n});
        if(arr[(idx+1+n)%n]!=-1) st.insert({arr[(idx+1+n)%n],(idx+1+n)%n});
    }
    return k>=0;
}

void solve() {
    int n,k; cin>>n>>k;
    vi arr(n); input(arr,n);
    int res=inf,l=0,r=*max_element(all(arr)),mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid,k,arr)) res=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<res<<endl;
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