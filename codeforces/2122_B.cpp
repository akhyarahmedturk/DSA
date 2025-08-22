/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-07-19 20:28 (GMT+5)

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
    int n; cin>>n;
    map<int,multiset<pii>> y_to_x,x_to_y;
    forn(i,0,n){
        int x,y; cin>>x>>y;
        y_to_x[y].insert({x,i+1});
        x_to_y[x].insert({y,i+1});
    }
    vector<vi> arr1,arr2;
    bool ch=true;
    for(auto it:y_to_x){
        if(ch){
            for(auto itt:it.second){
                arr1.push_back({it.first,itt.first,itt.second});
            }
        }
        else{
            vector<vi> temp;
            for(auto itt:it.second){
                temp.push_back({it.first,itt.first,itt.second});
            }
            reverse(all(temp));
            for(auto aa:temp) arr1.pb(aa);
        }
        ch=!ch;
    }
    for(auto it:x_to_y){
        if(ch){
            for(auto itt:it.second){
                arr2.push_back({it.first,itt.first,itt.second});
            }
        }
        else{
            vector<vi> temp;
            for(auto itt:it.second){
                temp.push_back({it.first,itt.first,itt.second});
            }
            reverse(all(temp));
            for(auto aa:temp) arr2.pb(aa);
        }
        ch=!ch;
    }
    int ans1=0,ans2=0;
    int st=0,e=n/2;
    while(e<n){
        ans1+=abs(arr1[st][0]-arr1[e][0])+abs(arr1[st][1]-arr1[e][1]);
        st++; e++;
    }
    st=0,e=n/2;
    while(e<n){
        ans2+=abs(arr2[st][0]-arr2[e][0])+abs(arr2[st][1]-arr2[e][1]);
        st++; e++;
    }
    // cout<<ans1<<"  f "<<ans2<<endl;
    if(ans1>=ans2){
        st=0,e=n/2;
        while(e<n){
            cout<<arr1[st][2]<<" "<<arr1[e][2]<<endl;
            st++; e++;
        }
    }
    else{
        st=0,e=n/2;
        while(e<n){
            cout<<arr2[st][2]<<" "<<arr2[e][2]<<endl;
            st++; e++;
        }
    }
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