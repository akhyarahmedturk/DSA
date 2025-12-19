/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-09-20 20:33 (GMT+5)

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

void solve() {
    int n; cin>>n;
    string s;
    cin>>s;
    forn(i,2,n-2){
        if(s[i]=='0' && s[i-1]=='1' && s[i-2]=='1' && s[i+1]=='1' && s[i+2]=='1'){ yesno(false); return;}
    }
    bool ch=true;
    int i=0;
    bool margin=false;
    while(i<n-1){
        if(s[i]=='1'){ i++; continue; }
        if(i>=2 && s[i-1]=='1' && s[i-2]=='1') margin=false; // difference aagya
        if(i==0 || s[i-1]=='0') margin=true;
        if(margin){
            if(i==n-2) break;// margin hy to dono py chaly ga
            else if(s[i+1]=='0') {  i+=2;} // margin aagy pass kar do
            else if(s[i+2]=='0') {  i+=3;}
            else {i++; margin=false; }// margin khatam}
        }
        else{
            if(i==n-2){
                if(s[i+1]=='1') ch=false;
                break;
            }
            if(s[i+1]=='0') {  margin=true; i+=2;}
            else if(s[i+2]=='0') i+=3;
            else{ ch=false; break;}
        }
    }
    if(ch) {yesno(ch); return;}
    ch=true;
    i=n-1;
    margin=false;
    while(i>0){
        if(s[i]=='1'){ i--; continue; }
        if(i<n-2 && s[i+1]=='1' && s[i+2]=='1') margin=false; // difference aagya
        if(i==n-1 || s[i+1]=='0') margin=true;
        if(margin){
            if(i==1) break;// margin hy to dono py chaly ga
            else if(s[i-1]=='0') { i-=2;} 
            else if(s[i-2]=='0') { i-=3;}
            else i--;// margin khatam
        }
        else{
            if(i==1){
                if(s[0]=='1') ch=false;
                break;
            }
            if(s[i-1]=='0') {  margin=true; i-=2;}
            else if(s[i-2]=='0') i-=3;
            else{ ch=false; break;}
        }
    }
    yesno(ch);
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}