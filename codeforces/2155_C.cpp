/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-10-05 22:10 (GMT+5)

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
    int n; cin>>n;
    vi arr(n); input(arr,n);
    if(n&1){
        bool ch=true;
        forn(i,0,n){
            if(arr[i]!=arr[i]/2+1) ch=false;
        }
        if(ch) { cout<<2<<endl; return;}
    }
    
    cout<<0<<endl;
}

void ss(int idx,vector<char> &ya,map<string,int> &mp){
    if(idx==ya.size()){
        int c=0;
        forn(i,0,ya.size()){
            if(ya[i]=='>'){ c++;}
            cout<<ya[i]<<" ";
        }
        cout<<endl;
        int pechy=0;
        string res="";
        forn(i,0,ya.size()){
            if(ya[i]=='>') c--;
            cout<<pechy+1+c<<" ";
            res+=to_string(pechy+1+c);
            if(ya[i]=='<') pechy++;
        }
        mp[res]++;
        cout<<endl;
    }
    else{
        ya[idx]='>';
        ss(idx+1,ya,mp);
        ya[idx]='<';
        ss(idx+1,ya,mp);
    }
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    // forn(i,1,8){
    //     map<string,int> mp;
    //     cout<<"i "<<i<<endl;
    //     vector<char> ya(i);
    //     ss(0,ya,mp);
    //     for(auto it:mp){
    //         if(it.second>1){ cout<<"------"<<it.first<<" "<<it.second<<endl;}
    //     }
    //     cout<<mp.size()<<endl;
    //     cout<<" ii "<<endl;
    // }
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}