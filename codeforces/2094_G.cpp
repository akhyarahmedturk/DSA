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
    int q,sum=0,res=0,rev_res=0;
    cin>>q;
    deque<int> dq;
    bool rev=false;
    while(q--){
        int s;
        cin>>s;
        if(s==1){
            if(rev){
                rev_res=rev_res+sum-dq.front()*dq.size();
                res=res-sum+dq.front()*dq.size();
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else{
                rev_res=rev_res-sum+dq.back()*dq.size();
                res=res+sum-dq.back()*dq.size();
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        else if(s==2){
            rev=!rev;
        }
        else{
            int k;
            cin>>k;
            if(rev){
                res+=sum+k; 
                sum+=k;
                rev_res+=(dq.size()+1)*k;
                dq.push_front(k);
            }
            else{
                rev_res+=sum+k;
                sum+=k;
                res+=(dq.size()+1)*k;
                dq.push_back(k);
            }
        }
        if(rev) cout<<rev_res<<endl;
        else cout<<res<<endl;
    }
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