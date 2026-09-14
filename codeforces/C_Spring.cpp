/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-03-25 11:23 (GMT+5)

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
    int a,b,c,m; cin>>a>>b>>c>>m;
    if(!a && !b && !c){ cout<<"0 0 0"<<endl;}
    else if(a && b && c){
        int r1=(m/a)*6,r2=(m/b)*6,r3=(m/c)*6;
        int l2=lcm(a,b); r1-=(m/l2)*3; r2-=(m/l2)*3;
        int l3=lcm(b,c); r2-=(m/l3)*3; r3-=(m/l3)*3;
        int l4=lcm(a,c); r1-=(m/l4)*3; r3-=(m/l4)*3;
        int l1=lcm(a,lcm(b,c));
        r1+=(m/l1)*2; r2+=(m/l1)*2; r3+=(m/l1)*2;
        cout<<r1<<" "<<r2<<" "<<r3<<endl;
    }
    else if(a && b){
        int r1=(m/a)*6,r2=(m/b)*6,l=lcm(a,b);
        r1-=(m/l)*3; r2-=(m/l)*3;
        cout<<r1<<" "<<r2<<" 0"<<endl;
    }
    else if(a && c){
        int r1=(m/a)*6,r2=(m/c)*6,l=lcm(a,c);
        r1-=(m/l)*3; r2-=(m/l)*3;
        cout<<r1<<" 0 "<<r2<<endl;
    }
    else if(b && c){
        int r1=(m/b)*6,r2=(m/c)*6,l=lcm(b,c);
        r1-=(m/l)*3; r2-=(m/l)*3;
        cout<<"0 "<<r1<<" "<<r2<<endl;
    }
    else if(a) cout<<m/a<<" 0 0"<<endl;
    else if(b) cout<<"0 "<<m/b<<" 0"<<endl;
    else if(c) cout<<"0 0 "<<m/c<<endl;
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