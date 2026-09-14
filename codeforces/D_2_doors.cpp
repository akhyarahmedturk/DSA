/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-09-09 23:40 (GMT+5)

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
    int n,m; cin>>n>>m;
    vi aand(n+10,-1);
    vector<vi> peche(n+10,vi(35,0)); // i se peche kitne log i py depend kar rahe jth bit ke liy
    vector<vector<pii>> graph(n+1);
    vi res(n+10,0);
    forn(i,0,m){
        int a,b,x; cin>>a>>b>>x;
        aand[a]=(aand[a]==-1?x:(x&aand[a]));
        aand[b]=(aand[b]==-1?x:(x&aand[b]));
        if(a==b){
            res[a]|=x;
            continue;
        }
        if(a>b) swap(a,b);
        graph[a].pb({b,x});
        forn(j,0,32){
            if(x&(1LL<<j)) peche[b][j]++;
        }
    }
    forn(i,1,n+1){
        if(aand[i]==-1) continue;
        forn(j,0,31){
            if(!(aand[i]&(1LL<<j))) continue;
            bool ch=false;
            if(peche[i][j]) ch=true; // koi peche reh gya
            if(res[i]&(1LL<<j)) ch=true; // koi peche reh gya
            for(auto it:graph[i]){
                if(!(aand[it.f]&(1LL<<j))) ch=true; // next me nahi aay gi y bit
            }
            if(ch){
                res[i]|=(1LL<<j);
                for(auto it:graph[i]){
                    if(it.ss&(1LL<<j)) peche[it.f][j]--;
                }
            }
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
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}