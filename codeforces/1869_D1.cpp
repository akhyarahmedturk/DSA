/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-16 19:15 (GMT+5)

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


void solve() {
    int n;
    cin>>n;
    vi arr(n);
    int sum=0;
    forn(i,0,n){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum%n){ cout<<"NO"<<endl; return;}
    int ya=sum/n;
    map<int,int> dena,lena;
    forn(i,0,n){
        int diff=abs(ya-arr[i]);
        if(diff==0){

        }
        else{
            int bits=0,temp=diff;
            while(temp){ bits++; temp/=2; }
            int upp=(1LL<<bits);
            int dn=upp-diff;
            if(__builtin_popcount(dn)!=1){
                cout<<"NO"<<endl;
                return;
            }
            if(arr[i]>ya){
                if(lena.find(upp)!=lena.end() ){
                    lena[upp]--;
                    if(lena[upp]==0) lena.erase(upp);
                }
                else{
                    dena[upp]++;
                }
                if(dena.find(dn)!=dena.end() ){
                    dena[dn]--;
                    if(dena[dn]==0) dena.erase(dn);
                }
                else{
                    lena[dn]++;
                }
            }
            else{
                if(lena.find(dn)!=lena.end() ){
                    lena[dn]--;
                    if(lena[dn]==0) lena.erase(dn);
                }
                else{
                    dena[dn]++;
                }
                if(dena.find(upp)!=dena.end() ){
                    dena[upp]--;
                    if(dena[upp]==0) dena.erase(upp);
                }
                else{
                    lena[upp]++;
                }
            }
        }
    }
    if(lena.size() || dena.size()) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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