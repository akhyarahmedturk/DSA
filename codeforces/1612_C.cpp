#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
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
    int k,x,res=0;
    cin>>k>>x;
    if(x>=(k*(k+1))/2 + (k*(k-1))/2) res=2*k-1;
    else if(x<=(k*(k+1))/2){
        int start=1,end=k,mid,ans=1;
        while(start<=end){
            mid=(start+end)/2;
            if(x==(mid*(2+mid-1))/2){
                ans=mid;
                break;
            }
            else if(x>(mid*(2+mid-1))/2){
                ans=mid+1;
                start=mid+1;
            }
            else end=mid-1;
        }
        res=ans;
    }
    else{
        res=k;
        x-=(k*(k+1))/2;
        int start=1,end=k-1,mid,ans=1;
        while(start<=end){
            mid=(start+end)/2;
            if(x==(mid*(2*(k-1)-mid+1))/2){
                ans=mid;
                break;
            }
            else if(x>(mid*(2*(k-1)-mid+1))/2){
                ans=mid+1;
                start=mid+1;
            }
            else end=mid-1;
        }
        res+=ans;
    }
    cout<<res<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}