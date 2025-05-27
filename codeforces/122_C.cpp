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

void sol(string a,int n,vector<int> &st,int &idx){
    int num=stoll(a);
    st[idx]=num;
    // st.push_back(num);
    idx++;
    if(num>n) return;
    a+='4';
    sol(a,n,st,idx);
    a[a.size()-1]='7';
    sol(a,n,st,idx);
}

void solve() {
    int n=1e10;
    vector<int> st(4094);
    int idx=0;
    sol("4",n,st,idx);
    sol("7",n,st,idx);
    sort(all(st));
    int l,r;
    cin>>l>>r;
    int i=0,res=0,prv=l-1;
    while(st[i]<l) i++;
    while(1){
        if(st[i]<=r) {
            res+=(st[i]*(st[i]-prv));
            i++;
        }
        else{
            res+=(st[i]*(r-prv));
            break;
        }
        prv=st[i-1];
    } 
    cout<<res<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}