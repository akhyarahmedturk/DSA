/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-11 19:45 (GMT+5)

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

//Trie

const int ALPHA = 26;
// const int MAXN = 2000000;   // total characters

struct TrieNode{
    TrieNode* child[ALPHA];
    int cnt;

    TrieNode(){
        cnt = 0;
        for (int i = 0; i < 26; i++) child[i] = nullptr;
    }
};

struct Trie{
    TrieNode* root;
    Trie() : root(new TrieNode()) {}
    void insert(const string& s){
        TrieNode* cur = root;
        for (char c : s){
            int id = c - 'a';
            if (cur->child[id] == nullptr) cur->child[id] = new TrieNode();
            cur = cur->child[id];
            cur->cnt++;
        }
    }
    int process(string &s){
        int res=0;
        TrieNode* cur = root;
        for (char c : s){
            int id = c - 'a';
            if (cur->child[id] == nullptr) return res;
            cur = cur->child[id];
            res+=cur->cnt*2;
        }
        return res;
    }
};

void solve() {
    int n; cin>>n;
    vector<string> arr(n); input(arr,n);
    int res=0;
    Trie trie=Trie();
    for(auto it:arr){
        res+=it.length()*n*2;
        trie.insert(it);
    }
    for(auto it:arr){
        reverse(all(it));
        res-=trie.process(it);
    }
    cout<<res<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}