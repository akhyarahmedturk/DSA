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
    map<int,vi> mp;
    forn(i,0,n){
        int a;
        cin>>a;
        mp[a].push_back(i);
    }
    vector<bool> vec(n,false);
    int res=0LL;
    for(auto it=mp.rbegin(); it!=mp.rend(); it++){
        int start=it->second[0];
        int size=it->second.size();
        vec[it->second[0]]=true;
        forn(i,1,size){
            vec[it->second[i]]=true;
            if(it->second[i]!=it->second[i-1]+1){
                int end=it->second[i-1];
                if((start!=0 && vec[start-1]) || (end!=n-1 && vec[end+1])) res=res;
                else res++;
                start=it->second[i];
            }
        }
        int end=it->second[size-1];
        if((start!=0 && vec[start-1]) || (end!=n-1 && vec[end+1])) res=res;
        else res++;
    }
    cout<<res<<endl;
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