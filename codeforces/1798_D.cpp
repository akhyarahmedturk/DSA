/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-14 18:56 (GMT+5)

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
    int n;
    cin>>n;
    multiset<int> st1,st2;
    forn(i,0,n){
        int a;
        cin>>a;
        if(a>0) st1.insert(a);
        else if(a<0) st2.insert(a);
    }
    if(st1.empty()){ cout<<"NO"<<endl; return;}
    int mm=0,mx=0,curr=0,diff=*(--st1.end())-*(st2.begin());
    vi res;
    while(!st1.empty() || !st2.empty()){
        int pos=curr-mm;
        int neg=curr-mx;
        if(!st1.empty() && *(st1.begin())<diff-pos){
            auto it=st1.lower_bound(diff-pos);
            it--;
            curr+=*(it);
            res.push_back(*it);
            mx=max(mx,curr);
            st1.erase(it);
        }
        else if(!st2.empty() && *(--st2.end())>(diff*-1)-neg){
            auto it=st2.upper_bound((diff*-1)-neg);
            curr+=(*it);
            res.push_back(*it);
            mm=min(mm,curr);
            st2.erase(it);
        }
        else{ cout<<"NO"<<endl; return;}
    }
    cout<<"Yes"<<endl;
    forn(i,0,n-res.size()) cout<<"0 ";
    forn(i,0,res.size()) cout<<res[i]<<" ";
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