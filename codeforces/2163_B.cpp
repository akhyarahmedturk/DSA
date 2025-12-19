/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-10 21:01 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");

*    Those who can’t remember the past are condemned to repeat it.
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
    int n; cin>>n;
    vector<vi> arr(2LL,vi(n));
    input(arr[0],n);
    input(arr[1],n);
    vi mm1(n),mm2(n),mx1(n),mx2(n);
    mm1[0]=arr[0][0]; mx1[0]=arr[0][0];
    forn(i,1,n) { 
        mm1[i]=min(mm1[i-1],arr[0][i]);
        mx1[i]=max(mx1[i-1],arr[0][i]);
    }
    mm2[n-1]=arr[1][n-1]; mx2[n-1]=arr[1][n-1];
    forr(i,n-2,0) { 
        mm2[i]=min(mm2[i+1],arr[1][i]);
        mx2[i]=max(mx2[i+1],arr[1][i]);
    }
    int res=0;
    forn(i,1,min(mm1[0],mm2.back())+1){
        //pehli dafa kis r py chaly ga us ky bad saary chaly gy
        int l=i,r=2*n,ans=2*n+1,mid;
        // i as min ly ky kitna aagy jaa sakty 1st waly array me
        //ulta sorted hoga to upper_bound bhi ulta lagy ga
        int end1=upper_bound(all(mm1),i,greater<int>())-mm1.begin()-1;
        while(l<=r){
            mid=(l+r)/2;
            int ya=upper_bound(all(mx1),mid)-mx1.begin()-1;
            int end11=min(end1,ya);
            if(mx2[end11]<=mid && mm2[end11]>=i){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        res+=(2*n+1-ans);
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