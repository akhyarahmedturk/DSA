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
#define input(vec, n) for(int i = 0; i < (n); i++) cin >> vec[i];

void solve(){
    int n;
    cin >> n;
    vector<bool> mp(n, false);
    vector<int> res(n + 1, -1);
    bool check = true;
    res[0] = 1;
    mp[1] = true;
    forn(i, 2, n + 1){
        if (i + i - 1 == n){
            if (mp[n]){
                check = false;
                break;
            }
            else{
                res[i - 1] = n;
                mp[n] = true;
            }
        }
        else if (mp[(i + i - 1) % n]){
            check = false;
            break;
        }
        else{
            res[i-1] =(i + i - 1) % n;
            mp[(i + i - 1) % n] = true;
        }
    }
    if(check){
        forn(i,0,n) cout<<res[i]<<" ";
        cout<<endl;
    }
    else cout<<-1<<endl;
}

int32_t main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}