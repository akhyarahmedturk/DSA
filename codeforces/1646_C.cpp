/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-06-30 17:46 (GMT+5)

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
// #define mp make_pair
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

vector<int> fact;

int ss(int idx,vector<int> bits){//not solved
    if(idx==-1){
        int c=0;
        forn(i,0,64){ if(bits[i]) c++;}
        return c;
    }
    else{
        int a=ss(idx-1,bits);
        int i=0,temp=fact[idx];
        while(temp){
            if(temp%2){
                if(bits[i]) bits[i]=0;
                else return a;
            }
            temp/=2;
            i++;
        }
        return min(a,ss(idx-1,bits)+1);
    }
}

void solve() {
    int n;
    cin>>n;
    int nn=n,i=0;
    vi bits(64,0);
    while(nn){
        bits[i]=nn%2;
        nn/=2;
        i++;
    }
    int res=ss(fact.size()-1,bits);
    cout<<res<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    int curr=2LL;
    for(int i=3;curr<=1000000000000;i++){
        fact.pb(curr);
        curr=(curr*i);
    }
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}