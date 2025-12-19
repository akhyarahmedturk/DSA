/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-18 20:08 (GMT+5)

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
    map<int,int> mp;
    forn(i,0,n) mp[arr[i]]++;
    int res=0;
    for(auto it:mp){
        int curr=it.f;
        int c=it.ss;
        //CP3
        res+=(c*(c-1)*(c-2));
        if(it.first==1) continue;
        for(int i=1;i*i<=curr;i++){
            if(curr%i==0){
                if(mp.find(i)!=mp.end() && mp.find((curr*curr)/i)!=mp.end()){
                    int c1=mp[i],c2=mp[(curr*curr)/i];
                    res+=(c*c1*c2);
                }
                if(i*i!=curr && i!=1 && mp.find(curr/i)!=mp.end() && mp.find(curr*i)!=mp.end()){
                    int c1=mp[curr/i],c2=mp[curr*i];
                    res+=(c*c1*c2);
                }
            }
        }
        // cout<<res<<" ";
    }
    cout<<res<<endl;
}
//1 2 3 4

//6*6
//1*36 2*18 3*12 4*9

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