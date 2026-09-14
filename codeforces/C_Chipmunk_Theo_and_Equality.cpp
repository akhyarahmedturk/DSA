/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-05-23 11:39 (GMT+5)

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

void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n);
    map<int,int> sum1;
    if(arr[0]==1) sum1[2]=1;
    int c=0;
    while(arr[0]>=2){
        sum1[arr[0]]+=c;
        if(arr[0]&1) arr[0]++;
        else arr[0]/=2;
        c++;
    }
    sum1[1]+=c;
    forn(i,1,n){
        map<int,int> sum2;
        if(arr[i]==1) sum2[2]=1 + sum1[2];
        int c=0;
        while(arr[i]>=2){
            if(sum1.find(arr[i])!=sum1.end()) {
                // cout<<arr[i]<<" ";
                sum2[arr[i]]=c + sum1[arr[i]];
            }
            if(arr[i]&1) arr[i]++;
            else arr[i]/=2;
            c++;
        }
        sum2[1]=c + sum1[1];
        swap(sum1,sum2);
        // cout<<endl;
    }
    int res=inf;
    for(auto it:sum1) res=min(res,it.ss);
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