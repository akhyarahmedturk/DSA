/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-05-21 10:14 (GMT+5)

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
// idx.find_by_order(n); to get the nth value
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
// #define mp make_pair
#define pb push_back
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

#define forn(i, a, b) for (int i = a; i < b; i++)
#define forr(i, a, b) for (int i = a; i >= b; i--)
#define input(vec, n) for(int z = 0; z < (n); z++) cin >> vec[z];

// vector<int> getNthPermutation(int n, int length) {// pre written code
//     ordered_set<int> os;
//     vector<int> result;
//     vector<int> fact(length, 1);

//     // Precompute factorials
//     for (int i = 1; i < length; i++)
//         fact[i] = fact[i - 1] * i;

//     // Fill ordered_set with 1 to length
//     for (int i = 1; i <= length; i++)
//         os.insert(i);

//     n--; // Convert to 0-based index

//     for (int i = length - 1; i >= 0; i--) {
//         int index = n / fact[i];
//         n %= fact[i];

//         auto it = os.find_by_order(index);
//         result.push_back(*it);
//         os.erase(it);
//     }

//     return result;
// }


vector<int> fact;
void solve() {
    int n,k;
    cin>>n>>k;
    if(k==1){
        forn(i,1,n+1) cout<<i<<" ";
        cout<<endl;
        return; 
    }
    if(n<=40 && k>(1LL<<(n-1))) { cout<<-1<<endl; return;}
    int start=0,end=n-1;
    vi res(n,0);
    forn(i,1,n){
        if((n-i-1)<40 && k> (1LL<<(n-i-1))) { res[end]=i; end--; k-=(1LL<<(n-i-1));}
        else { res[start]=i; start++; }
    }
    res[start]=n;
    forn(i,0,n) cout<<res[i]<<" ";
    cout<<endl;
}

int32_t main(){
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    fact.resize(2*1e5+10,1e12*2);
    fact[1]=fact[0]=1;
    int i=2,curr=2;
    while(curr<=1e12*2){
        fact[i-1]=curr;
        curr=curr*i;
        i++;
    }
    int t=1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}