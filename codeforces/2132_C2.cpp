/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-21 21:27 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");
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
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

int mx;
void solve(map<int,int> &ya) {
    int n,k; cin>>n>>k;
    if(k>=n){ cout<<3*n<<endl; return;}
    int t=n;
    int res=0,count=0;
    vector<int> bits;
    while(t>0){
        bits.pb(t%3); 
        if(t%3) count++; 
        t/=3;
    }
    if(count>k){ cout<<-1<<endl; return;}
    int curr=1;
    while(n && k>0 ){
        if(k>=n/curr){
            res+=(n/curr)*ya[curr];
            n=0;
            break;
        }
        int b=curr*3;
        int d=(n%b);
        n-=d;
        d/=curr;
        res+=(d*ya[curr]);
        k-=d;
        if(k<0) break;
        while(k-(n/b)>=2){
            int d=k-(n/b);
            d=(d+1)/3;
            k-=3*d;
            res+=(d*3*ya[curr]);
            n-=d*3*curr;
        }
        curr=b;
    }
    if(k>=0 && n==0) cout<<res+3*n<<endl;
    else cout<<-1<<endl;
}

int32_t main(){
    int t=1;
    cin >> t;
    map<int,int> ya;
    int curr=3,yy=1;
    while(curr<1e9+10){
        ya[curr]=curr*3+yy*(curr/3);
        mx=curr;
        curr*=3;
        yy++;
    }
    ya[1]=3;
    while (t--) {
        solve(ya);
    }
    return 0;
}