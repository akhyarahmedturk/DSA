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
    int n,count=0;
    char ch,curr;
    cin>>n>>ch;
    string str(n,'-');
    forn(i,0,n){
        cin>>curr;
        if(curr!=ch) count++;
        str[i]=curr;
    }
    if(count==0){
        cout<<0<<endl;
    }
    else if(count==1 || str.back()==ch){
        cout<<1<<endl;
        if(str.back()!=ch) cout<<n-1<<endl;
        else cout<<n<<endl;
    }
    else{
        int end=n;
        while(end>0 && str[end-1]!=ch) end--;
        if(end*2<=n){
            cout<<2<<endl<<n-1<<" "<<n<<endl;
        }
        else{
            cout<<1<<endl<<end<<endl;
        }
    }
}

int32_t main(){
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}