/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-02-08 14:20 (GMT+5)

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

string check(int mid,int n,vector<vi> &mp){
    string res(mid,'-');
    forn(i,0,mid){
        char ya='-';
        forn(j,0,26){
            int kk=i;
            bool ch=false;
            while(kk<n){
                if(!mp[kk][j]){ ch=true; break;}
                kk+=mid;
            }
            if(!ch){
                ya='a'+j;
                break;
            }
        }
        if(ya!='-'){
            res[i]=ya;
        }
        else return "";
    }
    return res;
}

void solve() {
    int n,k; cin>>n>>k;
    vector<vi> mp(n,vi(26,0));
    forn(i,0,k){
        forn(j,0,n){
            char ch; cin>>ch;
            mp[j][ch-'a']++;
        }
    }
    string res="";
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            string ya=check(i,n,mp);
            if(ya!=""){
                res=ya;
                break;
            }
            ya=check(n/i,n,mp);
            if(ya!=""){
                res=ya;
            }
        }
    }
    string rr="";
    while(rr.length()<n) rr+=res;
    cout<<rr<<endl;
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