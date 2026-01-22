/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-01-20 14:57 (GMT+5)

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
    int n; cin>>n;
    vi a(n),b(n); input(a,n); input(b,n);
    if(a==b){
        cout<<0<<endl; return;
    }
    int s1=accumulate(all(a),0LL);
    int s2=accumulate(all(b),0LL);
    if(s1!=s2){ cout<<-1<<endl; return ;}
    int l=1,r=2*n;
    forn(i,0,n){
        l=max(l,abs(a[i]-b[i]));
        if((abs(a[i]-b[i]))%2!=(abs(a[0]-b[0]))%2){ cout<<-1<<endl; return ;}//diff ki parity different hy
    }
    for(int i=l;i<=r;i+=2){
        bool check=true;
        vector<int> add(n);
        int ya=0;
        forn(j,0,n){
            int diff=abs(a[j]-b[j]);
            if(a[j]<=b[j]){
                add[j]=(b[j]-a[j])+(i-(b[j]-a[j]))/2;
            }
            else{
                add[j]=(i-(a[j]-b[j]))/2;
            }
            ya+=add[j];
        }
        if(ya==(i*(n/2))){
            vector<vi> res(i);
            set<pii> st;
            forn(s,0,i) st.insert({0,s});
            forn(j,0,n){
                forn(s,0,add[j]){
                    pii yaa=*st.begin(); st.erase(st.begin());
                    res[yaa.ss].pb(j+1);
                    st.insert({yaa.f+1,yaa.ss});
                }
            }
            cout<<i<<endl;
            for(auto &it:res){
                sort(all(it));
                for(auto itt:it) cout<<itt<<" ";
                cout<<endl;
            }
            return;
        }
    }
    cout<<-1<<endl;
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