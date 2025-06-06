/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-25 17:38 (GMT+5)

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
    int n,k;
    cin>>n>>k;
    vi res(n,0);
    map<int,vector<int>> mp;
    forn(i,0,n){
        int a;
        cin>>a;
        mp[a].pb(i);
    }
    set<pii> st;
    for(auto it:mp){
        st.insert({it.second.size(),it.first});
    }
    int left=n;
    for(auto it=st.rbegin();it!=st.rend();it++){
        if(it->first<k) break;
        left-=it->first;
        int a=1;
        // cout<<" ya"<<" "<<it->first;
        for(auto it1:mp[it->second]){
            res[it1]=a;
            a++;
            // cout<<a<<" ";
            if(a==k+1) break;
        }
        // cout<<endl;
        mp.erase(it->second);
    }
    int count=1;
    if(left<k){
        forn(i,0,n) cout<<res[i]<<" ";
        cout<<endl;
        return;
    }
    for(auto it:mp){
        for(int itt:it.second){
            res[itt]=count;
            count++;
            left--;
            if(count==k+1) {
                if(left<k) {
                    count=0;
                    break;
                }
                count=1;
            }
        }
        if(count==0) break;
    }
    forn(i,0,n) cout<<res[i]<<" ";
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