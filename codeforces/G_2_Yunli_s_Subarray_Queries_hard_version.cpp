/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-11 12:30 (GMT+5)

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

struct Query{
    int l, r, idx; //0 based
};

vector<int> mo_solve(const vector<int> &arr, vector<Query> queries){
    int n = arr.size();
    int q = queries.size();
    int block = max(1LL, (int)sqrt(n));

    sort(queries.begin(), queries.end(), [&](const Query& a, const Query& b){
        int block_a = a.l / block;
        int block_b = b.l / block;
        if (block_a != block_b) return block_a < block_b;
        // odd-even optimization (aka Hilbert-like tweak)
        return  (a.r < b.r);
    });

    vector<int> ans(q);

    vector<int> freq(1e6 + 10, 0);  // example freq array for values up to 1e6
    int cur_answer = 0;              // example: count distinct numbers
    // multiset<int> st;

    auto add = [&](int idx){
        int x = arr[idx];
        if (freq[x] == 0) cur_answer++;
        freq[x]++;
        };

    auto remove = [&](int idx){
        int x = arr[idx];
        freq[x]--;
        if (freq[x] == 0) cur_answer--;
        };
    int L = 0, R = -1;
    for (auto& qr : queries){
        while (L > qr.l) add(--L);
        while (R < qr.r) add(++R);
        while (L < qr.l) remove(L++);
        while (R > qr.r) remove(R--);

        ans[qr.idx] = cur_answer;
    }

    return ans;
}

void solve() {
    int n,k,q; cin>>n>>k>>q;
    vi arr(n); input(arr,n);
    vi res(n,n);
    map<int,int> val_cnt; // value ki frequency
    multiset<pii> cnt_val; // count to value
    forn(i,0,n){
        if(val_cnt[arr[i]-i]) cnt_val.erase({val_cnt[arr[i]-i],arr[i]-i});
        val_cnt[arr[i]-i]++;
        cnt_val.insert({val_cnt[arr[i]-i],arr[i]-i});
        if(i>=k-1){
            res[i-k+1]=k-(--cnt_val.end())->f;
            cnt_val.erase({val_cnt[arr[i-k+1]-(i-k+1)],arr[i-k+1]-(i-k+1)});
            val_cnt[arr[i-k+1]-(i-k+1)]--;
            if(val_cnt[arr[i-k+1]-(i-k+1)]) cnt_val.insert({val_cnt[arr[i-k+1]-(i-k+1)],arr[i-k+1]-(i-k+1)});
        }
    }
    SegmentTree st(res);
    while(q--){
        int x,y; cin>>x>>y;
        cout<<k-st.query(x-1,y-k)<<endl;
    }
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}