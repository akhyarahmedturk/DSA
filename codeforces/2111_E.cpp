/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-04 09:30 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");
*/
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<set<int>> mp(22); 
    forn(i,0,q){
        char a,b;
        cin>>a>>b;
        if(a=='a') continue;
        else if(a=='b' && b=='a') mp[10].insert(i);
        else if(a=='b' && b=='c') mp[12].insert(i);
        else if(a=='c' && b=='a') mp[20].insert(i);
        else if(a=='c' && b=='b') mp[21].insert(i);
    }
    forn(i,0,n){
        if(s[i]=='a') continue;
        else if(s[i]=='b'){
            if(mp[10].size()){
                s[i]='a';
                mp[10].erase(*mp[10].begin());
            }
            else if(mp[12].size() && mp[20].size()){
                int idx=*mp[12].begin();
                auto it=lower_bound(all(mp[20]),idx);
                if(it!=mp[20].end()){
                    int ya=*it;
                    s[i]='a';
                    mp[12].erase(idx);
                    mp[20].erase(ya);
                }
            }
        }
        else{
            if(mp[20].size()!=0){
                s[i]='a';
                mp[20].erase(*mp[20].begin());
            }
            else if(mp[21].size()){
                int idx=*mp[21].begin();
                auto it=lower_bound(all(mp[10]),idx);
                if(it!=mp[10].end()){
                    int ya=*it;
                    s[i]='a';
                    mp[10].erase(ya);
                }
                else{
                    s[i]='b';
                }
                mp[21].erase(idx);
            }
        }
    }
    cout<<s<<endl;
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