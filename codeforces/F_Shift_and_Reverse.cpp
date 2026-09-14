/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-02 22:30 (GMT+5)

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


int ya2(vector<int> &arr){
    int i=1;
    while(i<arr.size() && arr[i]<=arr[i-1]) i++;
    return arr.size()-i;
}

int ya1(vector<int> &arr){
    int i=1;
    while(i<arr.size() && arr[i]>=arr[i-1]) i++;
    return arr.size()-i;
}

// 3 2 1 5 4
// 4 5 1 2 3


void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n);
    int c1=0,c2=0;
    forn(i,1,n) c1+=(arr[i]<arr[i-1]);//asc
    forr(i,n-2,0) c2+=(arr[i]<arr[i+1]);
    c1+=(arr.back()>arr[0]) , c2+=(arr.back()<arr[0]);
    if(c1>1 && c2>1){ cout<<-1<<endl; return;}
    int res=n;
    if(c1==0 || c2==0) res=0;
    if(c1==1){
        res=min(res,ya1(arr));
        vi arr2=arr; reverse(all(arr2));
        res=min(res,ya2(arr2)+2);
    }
    if(c2==1){
        res=min(res,ya2(arr)+1);
        vi arr2=arr; reverse(all(arr2));
        res=min(res,ya1(arr2)+1);
    }
    cout<<res<<endl;
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