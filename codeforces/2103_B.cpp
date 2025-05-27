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
// #define mp make_pair
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
    int n;
    cin>>n;
    string a;
    cin>>a;
    int st=0,end=n-1,i=0,cost=0;
    bool ch=true;
    forn(i,0,n){
        if(a[i]=='0'){
            if(ch) cost++;
            else{
                cost+=2;
                ch=!ch;
            }
        }
        else{
            if(!ch) cost++;
            else{
                cost+=2;
                ch=!ch;
            }
        }
    }
    while(st<n && a[st]!='1') st++;
    if(st>=n-1){ cout<<cost<<endl; return;}
    int next=st+1;
    bool zero=false;
    while(next<n && !(a[next-1]=='0' && a[next]=='1')) {
        if(a[next]=='0') zero=true;
        next++;
    }
    if(!zero){ cout<<cost<<endl; return;}
    if(next==n){ cout<<cost-1<<endl; return;}
    cout<<cost-2<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}