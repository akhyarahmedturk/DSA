/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-10 17:48 (GMT+5)

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
    string s;
    cin>>s;
    vi mp={'a','b','c','d','e','f','g','h','i','j','k'};
    map<char,int> mp2;
    for(int i=0;i<10;i++) mp2[mp[i]]=i;
    if(s=="first"){
        string y="";
        int n; cin>>n;
        while(n--){
            int x; cin>>x;
            string ya=to_string(x);
            for(auto it:ya) y.pb(mp[it-'0']);
            if(ya.length()<10) y.pb('z');
        }
        cout<<y<<endl;
    }
    else{
        string y; cin>>y;
        vi arr;
        int i=0;
        while(i<y.length()){
            int c=0,curr=0;
            while(i<y.length() && c<10 && y[i]!='z'){
                curr*=10;
                curr+=mp2[y[i]];
                i++; c++;
            }
            arr.pb(curr);
            if(y[i]=='z') i++;
        }
        cout<<arr.size()<<endl;
        for(auto it:arr) cout<<it<<" ";
        cout<<endl;
    }
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}