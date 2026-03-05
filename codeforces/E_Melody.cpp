/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-03-03 15:20 (GMT+5)

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

vi check(int start,bool ch,map<int,set<pii>> g1,map<int,set<pii>> g2,vector<pii> &arr){
    int curr=start,n=arr.size();
    vi res={curr};
    g1[arr[curr].f].erase({arr[curr].ss,curr});
    g2[arr[curr].ss].erase({arr[curr].f,curr});
    while(res.size()<n){
        if(ch){
            if(g2[arr[curr].ss].empty()){ break;}
            if(g2[arr[curr].ss].begin()->f!=arr[curr].f){
                curr=g2[arr[curr].ss].begin()->ss;
            }
            else if((--g2[arr[curr].ss].end())->f!=arr[curr].f){
                curr=(--g2[arr[curr].ss].end())->ss;
            } 
            else { break;}
        }
        else{
            if(g1[arr[curr].f].empty()){  break;}
            if(g1[arr[curr].f].begin()->f!=arr[curr].ss){
                curr=g1[arr[curr].f].begin()->ss;
            }
            else if((--g1[arr[curr].f].end())->f!=arr[curr].ss){
                curr=(--g1[arr[curr].f].end())->ss;
            } 
            else{ break;}
        }
        res.pb(curr);
        ch=!ch;
        g1[arr[curr].f].erase({arr[curr].ss,curr});
        g2[arr[curr].ss].erase({arr[curr].f,curr});
    }
    return res;
}

void solve() {
    int n; cin>>n;
    map<int,set<pii>> g1,g2;
    vector<pii> arr(n);
    map<int,int> mp;
    forn(i,0,n){
        int a,b; cin>>a>>b;
        arr[i]={a,b};
        g1[a].insert({b,i});
        g2[b].insert({a,i});
        mp[a]++; mp[b]++;
    }
    int odd=0,start=-1;
    for(auto it:mp) {
        if(it.ss&1){
            start=it.f;
            odd++;
        } 
    }
    int st=0;
    if(odd && odd!=2){ cout<<"NO"<<endl; return;}
    forn(i,0,n) {
        if(arr[i].f==start) st=i;
        if(arr[i].ss==start) st=i;
    }
    vi res;
    if(arr[st].f==start) res=check(st,true,g1,g2,arr);
    else res=check(st,false,g1,g2,arr);
    if(res.size()==n){
        cout<<"YES"<<endl;
        for(auto it:res) cout<<it+1<<" ";
        cout<<endl;
        return;
    }
    else cout<<"NO"<<endl;
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

// 1 2
// 3 2
// 3 1