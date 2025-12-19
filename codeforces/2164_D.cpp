/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-06 21:48 (GMT+5)

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

bool check(int k,string &a,string &b,vector<vi> &mp,vi &arr){
    int start=0,n=a.size();
    arr.assign(n,-1);
    forn(i,0,n){
        start=max(start,i-k);// jo pehly liya hy us sy pechy nahi jaa sakty us ky aagy hi lyna hoga
        if(mp[b[i]].size()==0 || mp[b[i]].back()<start){ return false;}
        else {
            start=(*lower_bound(all(mp[b[i]]),start));
            if(start>i) { return false;}
        }
        arr[start]=i;//start sy max yha tak ly ky aana hy
    }
    return true;
}

void solve() {
    int n,k; cin>>n>>k;
    string a,b; cin>>a>>b;
    int mx=0;
    vector<vi> mp(200);
    forn(i,0,n) mp[a[i]].pb(i);
    vi arr(n,-1),ya(n,-1);
    int ans=k+1,l=0,r=k,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid,a,b,mp,ya)){
            ans=mid; r=mid-1;
            arr=ya;
        }
        else l=mid+1;
    }
    if(ans>k){ cout<<"-1\n"; return;}
    vector<string> res;
    vi arr2(n);
    forn(i,0,n) arr2[i]=i;//abhi kaha hy
    forn(i,0,k){
        if(a==b) break;//ans time hi chaly ga wesy to
        forr(j,n-1,0){
            if(arr[j]>arr2[j]){//jab tak pechy ho shift karo
                a[arr2[j]+1]=a[arr2[j]];
                arr2[j]++;
            }
        }
        res.pb(a);
    }
    cout<<res.size()<<'\n';
    for(auto it:res){
        cout<<it<<'\n';
    }
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