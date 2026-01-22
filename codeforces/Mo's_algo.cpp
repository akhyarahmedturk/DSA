/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-18 11:09 (GMT+5)

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

//Mo's Algo

struct Query {
    int l, r, idx; //0 based
};

vector<int> mo_solve(const vector<int> &arr, vector<Query> queries) {
    int n = arr.size();
    int q = queries.size();
    int block = max(1LL, (int) sqrt(n));

    sort(queries.begin(), queries.end(), [&](const Query &a, const Query &b) {
        int block_a = a.l / block;
        int block_b = b.l / block;
        if (block_a != block_b) return block_a < block_b;
        // odd-even optimization (aka Hilbert-like tweak)
        return  (a.r < b.r);
    });

    vector<int> ans(q);

    vector<int> freq(1e6+10, 0);  // example freq array for values up to 1e6
    int cur_answer = 0;              // example: count distinct numbers
    // multiset<int> st;

    auto add = [&](int idx) {
        int x = arr[idx];
        if (freq[x]==0) cur_answer++;
        freq[x]++;
    };

    auto remove = [&](int idx) {
        int x = arr[idx];
        freq[x]--;
        if(freq[x]==0) cur_answer--;
    };
    int L = 0, R = -1;
    for (auto &qr : queries) {
        while (L > qr.l) add(--L);
        while (R < qr.r) add(++R);
        while (L < qr.l) remove(L++);
        while (R > qr.r) remove(R--);

        ans[qr.idx] = cur_answer;
    }

    return ans;
}

void solve() {
    int n,q; cin>>n>>q;
    vi arr(n); input(arr,n);
    vi arr2=arr; sort(all(arr2));
    arr2.erase(unique(all(arr2)),arr2.end());
    forn(i,0,n) arr[i]=upper_bound(all(arr2),arr[i])-arr2.begin();
    vector<Query> queries(q);
    forn(i,0,q){
        int l,r; cin>>l>>r;
        queries[i].l=l-1;
        queries[i].r=r-1;
        queries[i].idx=i;
    }
    vi res=mo_solve(arr,queries);
    for(auto it:res) cout<<it<<endl;
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