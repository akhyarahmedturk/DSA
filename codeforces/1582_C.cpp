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
    string str;
    cin>>str;
    set<char> st;
    bool is_p=true;
    int i=0,j=n-1,count,res=n+1;
    while(i<=j){
        st.insert(str[i]);
        st.insert(str[j]);
        if(str[i]!=str[j]) is_p=false;
        i++;
        j--;
    }
    if(is_p) cout<<0<<endl;
    else{
        for(char it:st){
            i=0,j=n-1;
            count=0;
            while(i<j){
                if(str[i]!=str[j]){
                    if(str[i]==it) i++;
                    else if(str[j]==it) j--;
                    else break;
                    count++;
                }
                else{
                    i++;
                    j--;
                }
            }
            if(i>=j) res=min(res,count);
        }
        if(res==n+1) cout<<-1<<endl;
        else cout<<res<<endl;
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