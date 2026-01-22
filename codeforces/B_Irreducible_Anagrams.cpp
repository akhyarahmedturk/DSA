/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-07 22:43 (GMT+5)

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

// const int ALPHA = 26;

// struct TrieNode{
//     map<int, map<int, TrieNode*>> childs;
//     int val, ch;
//     set<int> end;
//     TrieNode(int v = -1, int c = -1){
//         val = v; ch = c;
//     }
// };

// struct Trie{
//     TrieNode* root;
//     Trie(){ root = new TrieNode(); }
//     void insert(vi mp, int idx){
//         int mm = 0;
//         for (auto it : mp){
//             if(it){
//                 if(mm==0) mm=it;
//                 else mm=min(mm,it);
//             }
//         }
//         for (auto& it : mp) {
//             if(it) it -= mm;
//         }
//         TrieNode* curr = root;
//         forn(i, 0, 26){
//             if (curr->childs.find(i) == curr->childs.end() || curr->childs[i].find(mp[i]) == curr->childs[i].end()){
//                 curr->childs[i][mp[i]] = new TrieNode(i, mp[i]);
//             }
//             curr = curr->childs[i][mp[i]];
//         }
//         curr->end.insert(idx);
//     }
//     bool check(vi mp, int l, int r){
//         TrieNode* curr = root;
//         int mm = 0;
//         for (auto it : mp){
//             if(it){
//                 if(mm==0) mm=it;
//                 else mm=min(mm,it);
//             }
//         }
//         for (auto& it : mp) {
//             if(it) it -= mm;
//         }
//         forn(i, 0, 26){
//             if (curr->childs.find(i) == curr->childs.end() || curr->childs[i].find(mp[i]) == curr->childs[i].end()) return false;
//             curr = curr->childs[i][mp[i]];
//         }
//         auto ya = curr->end.lower_bound(l);
//         if (ya == curr->end.end() || *ya >= r) return false;
//         return true;
//     }
// };

// shit! i thought reducable find karna hy


void solve(){
    string s; cin >> s;
    int n = s.length();
    vector<vi> mp(n+1,vi(26,0));
    forn(i,0,n){
        mp[i+1]=mp[i];
        mp[i+1][s[i]-'a']++;
    }
    int m; cin>>m;
    while(m--){
        int l,r; cin>>l>>r;
        if(l==r) cout<<"Yes"<<endl;
        else{
            vi mp1=mp[r];
            int count=0;
            forn(i,0,26) {
                mp1[i]-=mp[l-1][i];
                if(mp1[i]) count++;
            }
            if(count==1) cout<<"No"<<endl;
            else if(count==2 && s[l-1]==s[r-1]) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
