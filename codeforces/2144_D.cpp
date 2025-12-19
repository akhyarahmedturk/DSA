/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-16 17:21 (GMT+5)

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

void solve() {
    int n,k; cin>>n>>k;
    vi arr(n); input(arr,n);
    int mx=*max_element(all(arr)); 
    vi mp(mx+2,0);
    forn(i,0,n) mp[arr[i]]++;;
    vi prefix(mx+2,0);
    forn(i,1,mx+1) prefix[i]=prefix[i-1]+mp[i];
    int res=-inf;
    forn(j,2,mx+2){// for every possible x
        int ya=0,vv=1;
        int extra=n;
        int total=0;
        while(1){
            int start=(vv-1)*j+1;// range of vv*j // range of these values that will give ans as "vv" when divide by j
            int end=vv*j;
            if(start>mx) break; 
            int count=prefix[min(end,mx)]-prefix[start-1]; // no of elements i range
            total+=(count*vv); // new const for those
            // if(mp[vv]){ cout<<start<<" "<<end<<" c "<<count<<endl;}
            extra-=min(count,mp[vv]); // how many of indices with value 'vv' in initial aaray and how much we can reuse
            vv++; 
        }
        // cout<<j<<" "<<total<<" extra "<<extra<<endl;
        res=max(res,total-extra*k);
    }
    cout<<res<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}