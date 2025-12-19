/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-10-30 21:32 (GMT+5)

*    brain["Motivation"].insert("Ya to win hy ya learn");

*    Those who can’t remember the past are condemned to repeat it.
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
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define INT_MAX LLONG_MAX

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

void solve() {
    int n; cin>>n;
    vector<string> arr(n); input(arr,n);
    int t=0,x,y;
    forn(i,0,n){
        forn(j,0,n) {
            if(arr[i][j]=='#') { t++; x=i; y=j; }
        }
    }
    if(!t) { cout<<"YES"<<endl; return;}
    vector<vector<string>> ya={{"LD","UR"},{"LU","DR"},{"RU","DL"},{"RD","UL"}};
    // cout<<" xx "<<x<<" yy "<<y<<endl;
    forn(i,0,4){
        int xx=x,yy=y;
        int c=1;
        while(1){
            if(ya[i][0][0]=='L') yy--;
            else if(ya[i][0][0]=='R') yy++;
            else if(ya[i][0][0]=='U') xx--;
            else if(ya[i][0][0]=='D') xx++;
            if(xx>=0 && xx<=n-1 && yy>=0 && yy<=n-1){
                if(arr[xx][yy]=='#') c++;
            }
            // cout<<"i "<<i<<" xx "<<xx<<" yy "<<yy<<endl;
            if(ya[i][0][1]=='R') yy++;
            else if(ya[i][0][1]=='L') yy--;
            else if(ya[i][0][1]=='U') xx--;
            else if(ya[i][0][1]=='D') xx++;
            // cout<<"i "<<i<<" xx "<<xx<<" yy "<<yy<<endl;
            if(xx>=0 && xx<=n-1 && yy>=0 && yy<=n-1){
                if(arr[xx][yy]=='#') c++;
            }
            else break;
        }
        xx=x,yy=y;
        while(1){
            if(ya[i][1][0]=='L') yy--;
            else if(ya[i][1][0]=='R') yy++;
            else if(ya[i][1][0]=='U') xx--;
            else if(ya[i][1][0]=='D') xx++;
            if(xx>=0 && xx<=n-1 && yy>=0 && yy<=n-1){
                if(arr[xx][yy]=='#') c++;
            }
            // cout<<"i "<<i<<" xx "<<xx<<" yy "<<yy<<endl;
            if(ya[i][1][1]=='L') yy--;
            else if(ya[i][1][1]=='R') yy++;
            else if(ya[i][1][1]=='U') xx--;
            else if(ya[i][1][1]=='D') xx++;
            // cout<<"i "<<i<<" xx "<<xx<<" yy "<<yy<<endl;
            if(xx>=0 && xx<=n-1 && yy>=0 && yy<=n-1){
                if(arr[xx][yy]=='#') c++;
            }
            else break;
        }
        if(c==t){ cout<<"YES"<<endl; return;}
    }
    if(t==4){
        if(x>0){
            if(arr[x-1][y]=='#'){
                if(y>0 && arr[x-1][y-1]=='#' && arr[x][y-1]=='#'){ cout<<"YES"<<endl; return;}
                if(y<n-1 && arr[x-1][y+1]=='#' && arr[x][y+1]=='#'){ cout<<"YES"<<endl; return;}
            }
        }
        if(x<n-1){
            if(arr[x+1][y]=='#'){
                if(y>0 && arr[x+1][y-1]=='#' && arr[x][y-1]=='#'){ cout<<"YES"<<endl; return;}
                if(y<n-1 && arr[x+1][y+1]=='#' && arr[x][y+1]=='#'){ cout<<"YES"<<endl; return;}
            }
        }
    } 
    cout<<"NO"<<endl;   
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