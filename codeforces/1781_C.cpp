/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-14 20:33 (GMT+5)

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
    string s;
    cin>>s;
    map<char,int> mp;
    for(char it:s) mp[it]++;
    vi arr;
    for(auto it:mp) { arr.push_back(it.second);}
    sort(allr(arr));
    int res=LONG_LONG_MAX;
    pii ans;
    int start=n/26;
    if(start*26<n) start++;
    forn(i,start,n+1){
        if(n%i) continue;
        int j=n/i;
        int curr=0;
        for(int k=0;k<arr.size() && k<j ;k++){
            curr+=min(i,arr[k]);
        }
        if(res>n-curr){
            res=n-curr;
            ans={i,j};
        }
    }
    if(!res){ cout<<0<<endl<<s<<endl; return;}
    typedef pair<int,char> pic;    
    priority_queue<pic,vector<pic>,greater<pic>> pq;
    map<char,int> ya;
    for(auto it:mp){
        pq.push({it.second,it.first});
        ya[it.first]=it.second;
        if(pq.size()>ans.second) { ya.erase(pq.top().second); pq.pop();}
    }
    forn(i,0,n){
        if(ya.find(s[i])==ya.end()){
            char req='-';
            for(auto it:ya){
                if(it.second<ans.first){ req=it.first; break;}
            }
            ya[req]++;
            s[i]=req;
        }
        else if(ya[s[i]]<=ans.first) continue;
        else if(ya[s[i]]>ans.first){
            char req='_';
            for(auto it:ya){
                if(it.second<ans.first){ req=it.first; break;}
            }
            if(req=='_'){
                for(char ch='a';ch<='z';ch++){ 
                    if(ya.find(ch)==ya.end()) { ya[s[i]]--; s[i]=ch; ya[ch]=1; break;}
                }
            }
            else{
                ya[req]++;
                ya[s[i]]--;
                s[i]=req;
            }
        }
    }
    cout<<res<<endl<<s<<endl;
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