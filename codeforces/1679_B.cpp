#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

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
    int n,q,sum=0;
    cin>>n>>q;
    set<int> st;
    vector<int> arr(n);
    forn(i,0,n){
        cin>>arr[i];
        sum+=arr[i];
    }
    int x,idx,val,last_changed=-1;
    while(q--){
        cin>>x;
        if(x==1){
            cin>>idx>>val;
            idx--;
            if(last_changed==-1 ||  st.find(idx)!=st.end()){
                sum+=(val-arr[idx]);
            }
            else{
                st.insert(idx);
                sum+=(val-last_changed);
            }
            arr[idx]=val;
        }
        else{
            cin>>last_changed;
            sum=n*last_changed;
            st= set<int>();
        }
        cout<<sum<<endl;
    }
}

int32_t main(){
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}