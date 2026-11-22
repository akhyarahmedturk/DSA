/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-11-06 18:51 (GMT+5)

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


int check(int start,vi &arr,int n){
    int res=n,l=0,r=arr.size()-1,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(arr[mid]>start) res=arr[mid], l=mid+1;
        else r=mid-1;
    }
    return res;
}

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    vector<vi> arr(10);
    vi add(n+10,0);
    vi diff(n+10,0);
    forr(i,n-1,0){
        arr[s[i]-'0'].pb(i);
        int r=check(-1,arr[2],n);//2
        r=check(r,arr[0],n);//20
        r=check(r,arr[2],n);//202
        // ab 6,5 dono ko find karo
        int six=check(r,arr[6],n);
        int five=check(r,arr[5],n);
        if(six<=five) continue;
        int curr=(six-five);
        add[i]+=curr;
        diff[five+1]--;
        diff[six+1]++;
    }
    int curr=0,dx=0;
    forn(i,0,n){
        dx+=diff[i];
        curr+=add[i]+dx;
        cout<<(i+1)*(n-i)-curr<<" ";
    }
    cout<<endl;
}

// 1 2 3 4


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