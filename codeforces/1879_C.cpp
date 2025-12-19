

/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-12-09 07:59 (GMT+5)

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

const int N=2e5+10;
int fact[N];

void solve() {
  string s; cin>>s;
  int n=s.length();
  int res=0,i=0;
  vi comps;
  int sum=0;
  while(i<n){
    int l=i;
    i++;
    while(i<n && s[i]==s[l]) i++;
    comps.pb(i-l);
  }
  int a=n-comps.size();
  // now, ab 'a' erase karny
  // no of ways=a! because length kam ho rahi 1111  4 chose kary phir three option hi hen
  int r1=fact[a];
  for(auto it:comps){
    if(it==1) continue; //is ko to select nahi karna
    res=(res+it*r1)%mod2;//is elemnt sy start karo
  }
  cout<<a<<" "<<max(1LL,res)<<endl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
  int t=1;
  cin >> t;
  fact[0]=1;
  fact[1]=1;
  forn(i,2,N){
    fact[i]=(fact[i-1]*i)%mod2;
  }
  while (t--) {
    solve();
  }
  return 0;
}
//11 -> 1,2
//111 ->prv*3=6
//1111 ->prv*4=24

// n!

// 1100 //total 2 erase karny 

// 1,2  1,3  2,2  2,3  3,2  3,1  4,2  4,1 =>8
// 2*2 + 2*2(rev)=4*2

//110011 total 3 erase karny

// 8*(3P3) or 8*(3!)