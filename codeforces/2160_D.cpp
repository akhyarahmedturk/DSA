/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-10-12 20:53 (GMT+5)

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

void solve(){
    int n; cin >> n;
    vi arr(2 * n);
    forn(i, 0, 2 * n) arr[i] = i + 1;
    vi res(2 * n, 1);
    // set<int> st;
    // forn(i,0,n) st.insert(i+1);
    int curr = n;
    while (curr > 1){
        // BS do dfa pehly start find karo phir end
        // 1st ky liy start sy size-1 tak ho sakta 
        int first = 1, sec = arr.size();
        int st = 2, end = arr.size() - 1, mid;
        while (st <= end){
            mid = (st + end) / 2;
            cout << "? " << sec - mid + 1 << " ";
            forn(i, mid, sec + 1) cout << arr[i - 1] << " ";
            cout << endl;
            int x; cin >> x;
            if (x == curr){
                first = mid;
                st = mid + 1;
            }
            else end = mid - 1;
            // cout << " sts " << st << " " << end << endl;
        }
        // cout << " first " << first << endl;
        // ab first+1 sy size tak second find karo
        st = first + 1; end = arr.size() - 1;
        while (st <= end && st != arr.size()){
            mid = (st + end) / 2;
            cout << "? " << mid - first + 1 << " ";
            forn(i, first, mid + 1) cout << arr[i - 1] << " ";
            cout << endl;
            int x; cin >> x;
            if (x == curr){
                sec = mid;
                end = mid - 1;
            }
            else st = mid + 1;
        }
        // cout<<" sec "<<sec<<endl;
        int v1 = arr[first - 1], v2 = arr[sec - 1];
        res[v1 - 1] = curr; res[v2 - 1] = curr;
        arr.erase(arr.begin() + first - 1);
        arr.erase(arr.begin() + sec - 2);
        curr--;
    }
    cout << "! ";
    forn(i, 0, 2 * n) cout << res[i] << " ";
    cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}