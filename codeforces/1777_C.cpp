/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-05 14:54 (GMT+5)

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
void ch(int val,int m,vi &mp,int &c,int add){
    for(int i=1;i*i<=val;i++){
        if(val%i==0){
            int a=i,b=val/i;
            if(a<=m ){ 
                if(add==-1 && mp[a]==1) c--;
                else if(add==1 && !mp[a]) c++;
                mp[a]+=add;
            }
            if(b<=m ){ 
                if(add==-1 && mp[b]==1) c--;
                else if(add==1 && !mp[b]) c++;
                mp[b]+=add;
            }
        }
    }
}

void solve() {
    int n,m; cin>>n>>m;
    vi arr(n); input(arr,n);
    if(m==1){ cout<<0<<endl; return;}
    sort(all(arr));
    int l=n-1,r=n-1,mid,res=inf;
    vi mp(m+1,0);
    mp[1]=1;
    int c=1;//1 to kisi sy bhi hosakta
    while(l>=0 ){
        while(c<m && l>=0){
            ch(arr[l],m,mp,c,1);
            l--;
        }
        while(c>=m){
            res=min(res,arr[r]-arr[l+1]);
            ch(arr[r],m,mp,c,-1);
            r--;
        }
        // cout<<"l "<<l<<" "<<r<<endl;
    }
    cout<<( res==inf ?-1:res )<<endl;
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