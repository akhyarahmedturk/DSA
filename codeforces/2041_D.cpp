/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-17 20:36 (GMT+5)

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
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    int start=0,end=999;
    int res=999;
    forn(i,0,7){
        int mid1=min(999LL,start+(end-start)/3);
        int mid2=min(999LL,start+((end-start)*2)/3);
        mid1=max(mid1,1LL);
        mid2=max(mid2,1LL);
        cout<<"? "<<mid1<<" "<<mid2<<endl;
        int x; cin>>x;
        if(x==(mid1+1)*(mid2+1)){
            res=mid1;
            end=mid1-1;
        }
        else if(x==mid1*(mid2+1)){
            res=mid2;
            end=mid2-1;
            start=mid1+1;
        }
        else{
            start=mid2+1;
        }
    }
    cout<<"! "<<res<<endl;
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