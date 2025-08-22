/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-01 00:10 (GMT+5)

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
    map<char,int> mp,mp2;
    mp['N']=0;
    mp['S']=0;
    mp['W']=0;
    mp['E']=0;
    mp2['N']=0;
    mp2['S']=0;
    mp2['W']=0;
    mp2['E']=0;
    string s;
    cin>>s;
    forn(i,0,n) mp[s[i]]++;
    int u=abs(mp['S']-mp['N']),l=abs(mp['W']-mp['E']);
    if(u%2 || l%2){ cout<<"NO"<<endl; return;}
    if(u==0 && l==0){
        if(n==2) { cout<<"NO"<<endl; return;}
        if(mp['S']) { mp2['S']=1; mp2['N']=1;}
        else { mp2['W']=1; mp2['E']=1;}
    }
    else{
        if(mp['S']>mp['N']) mp2['S']=u/2;
        else if(mp['S']<mp['N']) mp2['N']=u/2;
        if(mp['E']>mp['W']) mp2['E']=l/2;
        else if(mp['E']<mp['W']) mp2['W']=l/2;
    }
    // cout<<u<<l<<endl;
    forn(i,0,n){
        if(mp2[s[i]]){
            cout<<'R';
            mp2[s[i]]--;
        }
        else cout<<'H';
    }
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