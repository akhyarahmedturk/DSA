/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-22 01:51 (GMT+5)

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
    vector<vi> arr;
    int total=0;
    map<int,int> diff;
    forn(i,0,n){
        int size; cin>>size;
        vi ya(size); input(ya,size); sort(all(ya));
        arr.pb(ya);
        map<int,int> mp;
        for(auto it:ya) mp[it]++;
        int original=0;
        int add=-1;
        int curr=0;
        while(1){
            if(mp[curr]) curr++;
            else if(add==-1){
                add=curr; 
                curr++;
            }
            else break;
            if(add==-1) original=curr;
        }
        total+=original;
        if(add==-1){
            add=curr;
            diff[add]++;
        }
        else diff[add]+=(curr-original);
    }
    int res=0;
    forn(i,0,n){
        int mex=0,curr=0;
        forn(j,0,arr[i].size()){
            if(arr[i][j]==mex-1) continue;
            else if(arr[i][j]==mex) mex++;
            else break;
        }
        int abhi_total=total-mex;
        // cout<<abhi_total<<" dd "<<mex<<endl;
        forn(j,0,arr[i].size()){
            if(arr[i][j]>mex){
                res+=abhi_total+mex+diff[arr[i][j]];
                cout<<" i "<<i<<" j "<<j<<" "<<diff[arr[i][j]]<<endl;
            }
            else{
                if((j && arr[i][j-1]==arr[i][j]) || (j<arr[i].size()-1 && arr[i][j+1]==arr[i][j])){
                    res+=abhi_total+mex+diff[arr[i][j]];
                }
                else{
                    cout<<" i "<<i<<" j "<<j<<" "<<diff[arr[i][j]]<<endl;
                    res+=abhi_total+arr[i][j]+diff[arr[i][j]];
                }
            }
        }
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