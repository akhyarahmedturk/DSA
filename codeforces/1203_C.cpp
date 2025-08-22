/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-30 18:13 (GMT+5)

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

void DFS(int curr, int par, string& s, vi& used, vector<set<int>>& mp){
    s.push_back('a' + curr);
    used[curr] = 1;
    while (!mp[curr].empty()){
        int front = *mp[curr].begin();
        mp[curr].erase(front);
        if (front == par) continue;
        else DFS(front, curr, s, used, mp);
    }
}

void solve(){
    string s;
    cin >> s;
    vector<set<int>> mp(26);
    for (int i = 1;i < s.length();i++){
        mp[s[i] - 'a'].insert(s[i - 1] - 'a');
        mp[s[i - 1] - 'a'].insert(s[i] - 'a');
        if (mp[s[i] - 'a'].size() == 3 || mp[s[i - 1] - 'a'].size() == 3){ yesno(false); return; }
    }
    vi used(26, 0);
    string res = "";
    forn(i, 0, 26){
        if (!used[i]){
            if (mp[i].size() == 0) res.push_back('a' + i);
            else if (mp[i].size() == 1){
                DFS(i,-1,res,used,mp);
            }
        }
    }
    if(res.length()==26){
        yesno(true);
        cout<<res<<endl;
        return;
    }
    yesno(false);
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}