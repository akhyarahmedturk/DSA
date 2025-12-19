/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-10 20:04 (GMT+5)

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
    vi arr(n); input(arr,n);
    string s;
    cin>>s;
    if(s[0]=='1' || s.back()=='1'){ cout<<-1<<endl;  return;}
    vector<pii> res;
    forn(i,0,5){
        int mm=arr[0],mx=arr[0];
        int j=0,ii=0,jj=0;
        while(j<n && s[j]=='0'){
            if(arr[j]<mm) {
                mm=arr[j];
                ii=j;
            }
            if(arr[j]>mx) {
                mx=arr[j];
                jj=j;
            }
            j++;
        }
        if(j==n) break;
        int start=-1,end=-1,v=arr[j];
        ordered_set<int> st;
        st.insert(arr[j]);
        int ya=0;
        while(j<n){
            if(arr[j]>mm && v>mm && v<arr[j]){
                int yy=1+(st.order_of_key(arr[j])-st.order_of_key(mm+1));
                if(yy>ya){
                    ya=yy;
                    start=ii; end=j;
                }
            }
            if(arr[j]<mx && v>arr[j] && v<mx){
                int yy=1+(st.order_of_key(mx)-st.order_of_key(arr[j]+1));
                if(yy>ya){
                    ya=yy;
                    start=jj; end=j;
                }
            }
            if(s[j]=='1') st.insert(arr[j]);
            j++;
        }
        if(start!=-1){
            res.pb({start+1,end+1});
            int v1=min(arr[start],arr[end]);
            int v2=max(arr[start],arr[end]);
            forn(i,start,end+1){
                if(arr[i]>v1 && arr[i]<v2) s[i]='0';
            }
        }
    }
    for(auto it:s){
        if(it=='1'){ cout<<"-1"<<endl; return;}
    }
    cout<<res.size()<<endl;
    for(auto it:res) cout<<it.f<<" "<<it.ss<<endl;
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