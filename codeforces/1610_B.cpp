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

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    forn(i,0,n) cin>>arr[i];
    int start=0,end=n-1;
    bool check=true;
    while(start<end && arr[start]==arr[end]){ start++;  end--;}
    if(start>=end){
        yesno(true);
        return;
    }
    int r_start=start,r_end=end;
    r_start++;
    while(r_start<r_end ){ 
        if(arr[r_start]!=arr[r_end]){
            if(arr[r_start]==arr[start]) r_start++;
            else if(arr[r_end]==arr[start]) r_end--;
            else break;
        }
        else{
            r_start++;  
            r_end--;
        }    
    }
    if(r_start>=r_end){
        yesno(true);
        return;
    }
    r_start=start;
    r_end=end-1;
    while(r_start<r_end ){ 
        if(arr[r_start]!=arr[r_end]){
            if(arr[r_start]==arr[end]) r_start++;
            else if(arr[r_end]==arr[end]) r_end--;
            else break;
        }
        else{
            r_start++;  
            r_end--;
        }    
    }
    if(r_start>=r_end){
        yesno(true);
        return;
    }
    yesno(false);
}

int32_t main(){
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}