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
    int n;
    cin>>n;
    vi arr(n);
    input(arr,n);
    sort(allr(arr));
    int res=1;
    set<int> st;
    st.insert(arr[0]);
    forn(i,1,n){
        if(arr[i]>=*st.rbegin()){
            st.insert(arr[i]);
            res++;
        }
        else{
            auto it=st.upper_bound(arr[i]);
            int diff=*it-arr[i]+1;
            st.erase(it);
            st.insert(arr[i]);
            st.insert(diff);
        }
    }
    cout<<res<<endl;
}

int32_t main(){
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}