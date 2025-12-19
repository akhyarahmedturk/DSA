/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-16 19:53 (GMT+5)

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
    int a,b,n; cin>>n;
    vi arr(n); input(arr,n);
    int mx=0;
    set<pii> st;
    forn(i,0,n){ 
        st.insert({max(arr[i],arr[(i+1)%n]),i});
    }
    int res=0;
    vector<pii> graph(n);
    forn(i,0,n) graph[i]={(i-1+n)%n,(i+1)%n};
    while(1){
        pii ya=*st.begin();
        res+=ya.f;
        st.erase(st.begin());
        if(st.size()==1) break;
        int aagy=graph[ya.ss].ss,peechy=graph[ya.ss].f;
        if(arr[ya.ss]>=arr[aagy]){
            int aagy2=graph[aagy].ss;
            graph[aagy2].f=ya.ss;
            graph[ya.ss].ss=aagy2;
            st.erase({max(arr[aagy],arr[aagy2]),aagy});
            st.insert({max(arr[ya.ss],arr[aagy2]),ya.ss});
        }
        else{
            graph[aagy].f=peechy;
            graph[peechy].ss=aagy;
            st.erase({max(arr[peechy],arr[ya.ss]),peechy});
            st.insert({max(arr[peechy],arr[aagy]),peechy});
        }
    }
    cout<<res<<endl;
}

//1 2 3 4 5

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