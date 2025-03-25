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

int n,m;
bool check_row(int r,int c,vector<vector<char>> &arr){
    forn(i,0,c){
        if(arr[r][i]=='0') return false;
    }
    return true;
}
bool check_col(int r,int c,vector<vector<char>> &arr){
    forn(i,0,r){
        if(arr[i][c]=='0') return false;
    }
    return true;
}

void solve() {
    cin>>n>>m;
    vector<vector<char>> arr(n,vector<char> (m));
    forn(i,0,n){
        forn(j,0,m){
            cin>>arr[i][j];
        }
    }
    bool check=true;
    forn(i,0,n){
        forn(j,0,m){
            if(arr[i][j]=='1'){
                // if(i!=0 && j!=0 && arr[i-1][j]=='0' && arr[i][j-1]=='0'){
                //     check=false;
                //     break;
                // }
                if(!check_row(i,j,arr) && !check_col(i,j,arr)){
                    check=false;
                    break;
                }
            }
            if(!check) break;
        }
        if(!check) break;
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