/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-25 19:27 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");

*    Those who can't remember the past are condemned to repeat it.
*                                                 -Dynamic Programming.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
// idx.find_by_order(n); to get the nth value by order
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
#define pb push_back
#define f first
#define ss second
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX
#define nl "\n"

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    // 1->1-> har 1 element ky bad +=2*1 sy repeat
    // 2->4-> har 3 element ky bad +=2*4 sy repeat
    // 4->16-> har 7 element ky bad +=2*16 sy repeat
    int n,q; cin>>n>>q;
    vector<map<int,int>> mp1(n),mp2(n),mp3(n);
    while(q--){
        int l,r; cin>>l>>r; l--; r--;
        int d=(r-l+1);
        forr(i,20,0){
            int v=(1LL<<i);
            if(d>=v){
                int last=l + (d/v)*v-1;
                int last_val=v*v+(last-v)*v;
                mp1[l+v-1][i]++;
                mp2[last][i]--;
                mp3[last][i]-=last_val;
            }
        }
    }
    vector<vector<pii>> mp(22,vector<pii>(22,{0,0}));
    forr(i,n-1,0){
        for(auto it:mp1[i]){
            int val=it.f;
            mp[n%val][val].f+=(it.f*it.f*it.ss);
            mp[n%val][val].ss+=it.ss;
        }
        forn(){
            
        }

        for(auto it:mp2[i]){
            int val=it.f;
            mp[n%val][val].ss+=it.ss;
        }
        for(auto it:mp2[i]){
            int val=it.f;
            mp[n%val][val].f+=it.ss;
        }
    }
    forn(i,1,n+1) cout<<res[i]<<" ";
    cout<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}