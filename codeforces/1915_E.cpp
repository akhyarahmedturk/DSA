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
    vi arr(n),prefix(n+2);
    input(arr,n);
    prefix[0]=prefix[1]=0;
    forn(i,0,n){
        prefix[i+2]=prefix[i]+arr[i];
    }
    bool check=false;
    set<int> st1,st2;
    st1.insert(0);
    st2.insert(0);
    forn(i,3,n+2){
        if(i%2!=0){
            if(st1.find(prefix[i]-prefix[i-1])!=st1.end() || st2.find(prefix[i-1]-prefix[i])!=st2.end()){
                check=true;
                break;
            }
        }
        else{
            if(st2.find(prefix[i]-prefix[i-1])!=st2.end() || st1.find(prefix[i-1]-prefix[i])!=st1.end()){
                check=true;
                break;
            }
        }
        if(i%2==0 ) st1.insert(prefix[i-1]-prefix[i-2]);
        else st2.insert(prefix[i-1]-prefix[i-2]);
    }
    yesno(check);
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}