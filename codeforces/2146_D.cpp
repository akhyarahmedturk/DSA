/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-21 20:39 (GMT+5)

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

void solve() {
    int l,r; cin>>l>>r;
    ordered_set<int> st;
    forn(i,l,r+1) st.insert(i);
    int res=0;
    vi ya(r-l+1,-1);
    while(st.size()>1){
        int a=*(--st.end());
        st.erase(--st.end());
        vi mp(20,0);
        int t=a,i=0,b=0;
        while(t){
            if(t&1) mp[i]=0;
            else {mp[i]=1; b+=(1LL<<i);}
            i++; t/=2;
        }
        int vv=-1;
        forn(i,0,20){
            int idx=st.order_of_key(b);
            if(idx!=-1){
                vv=*st.find_by_order(idx);
                break;
            }
            if(!mp[i]){ b+=(1LL<<i);}   
        }
        ya[a-l]=vv; ya[vv-l]=a;
        res+=(a+vv-(a&vv))*2;
        st.erase(vv);
    }
    if(st.size()){ res+=(*st.begin());}
    cout<<res<<endl;
    forn(i,0,r-l+1){
        if(ya[i]==-1) cout<<l+i<<" ";
        else cout<<ya[i]<<" ";
    }
    cout<<endl;
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