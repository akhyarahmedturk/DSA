/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-10-31 09:18 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");

*    Those who can’t remember the past are condemned to repeat it.
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
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    int a,b; cin>>a>>b;
    int a1=a,b1=b;
    int aa=0,bb=0;
    while(a){
        aa++;
        a/=2;
    }
    while(b){
        bb++;
        b/=2;
    }
    // aa--; bb--;
    cout<<aa<<" "<<bb<<endl;
    int g1=1LL<<(aa-1);
    int g2=1LL<<(bb-1);
    // cout<<g1<<" "<<g2<<endl;
    if(g1!=a1) aa++; 
    if(g2!=b1) bb++; 
    cout<<aa<<" "<<bb<<endl;
    int cc=aa+bb;
    if(cc<=32){
        cout<<"32"<<endl <<"32"<<endl <<"32"<<endl;
    }
    else if(cc>64){
        if(aa<=32) cout<<"32"<<endl<<"128"<<endl<<"128"<<endl;
        else if(bb<=32) cout<<"128"<<endl<<"32"<<endl<<"128"<<endl;
        else cout<<"64"<<endl<<"128"<<endl<<"128"<<endl;
    }
    else {
        if(aa<=32) cout<<"32"<<endl<<"64"<<endl<<"64"<<endl;
        else if(bb<=32) cout<<"64"<<endl<<"32"<<endl<<"64"<<endl;
        else cout<<"64"<<endl<<"64"<<endl<<"64"<<endl;
    }
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}