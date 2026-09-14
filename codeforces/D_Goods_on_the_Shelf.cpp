/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2026-06-12 07:03 (GMT+5)

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

bool check(vector<int> &arr,int n){
    set<int> st;
    int i=0;
    while(i<n){
        if(st.find(arr[i])!=st.end()) return false;
        st.insert(arr[i]); i++;
        while(i<n && arr[i]==arr[i-1]) i++;
    }
    return true;
}

// 2 2 1 2 2 -> 1 2 2 2 2
// 2 2 1 1 2 -> 2 2 2 1 1
// 1 2 2 1 2 -> 2 2 2 1 1
// start se pechy swap, end ke aage swap;

void solve() {
    int n; cin>>n;
    vi arr(n); input(arr,n);
    map<int,int> start,end,cnt;
    forn(i,0,n){
        end[arr[i]]=i;
        cnt[arr[i]]++;
        if(start.find(arr[i])==start.end()) start[arr[i]]=i;
    }
    if(check(arr,n)){ cout<<"YES"<<endl; return;}
    for(auto it:cnt){
        int diff=(end[it.f]-start[it.f]+1)-it.ss;
        if(!diff) continue;
        if(diff==1){
            //start/ end se replace karo
            int idx=start[it.f]+1;
            while(arr[idx]==arr[idx-1]) idx++;
            swap(arr[idx],arr[start[it.f]]);
            if(check(arr,n)){ cout<<"YES"<<endl; return;}
            swap(arr[idx],arr[start[it.f]]);
            swap(arr[idx],arr[end[it.f]]);
            if(check(arr,n)){ cout<<"YES"<<endl; return;}
            swap(arr[idx],arr[end[it.f]]);
        }
        else if(arr[start[it.f]]!=arr[start[it.f]+1]){
            int temp_start=start[it.f]+1; it.ss--;
            // find contigious block
            while(1) {
                if(arr[temp_start]!=it.f) { temp_start++;  continue; }
                if(end[it.f]-temp_start+1==it.ss) break;
                temp_start++; it.ss--;
            }
            swap(arr[start[it.f]],arr[temp_start-1]);
            if(check(arr,n)){ cout<<"YES"<<endl; return;}
            swap(arr[start[it.f]],arr[temp_start-1]);
            if(end[it.f]!=n-1){
                swap(arr[start[it.f]],arr[end[it.f]+1]);
                if(check(arr,n)){ cout<<"YES"<<endl; return;}
                swap(arr[start[it.f]],arr[end[it.f]+1]);
            }
        }
        else if(arr[end[it.f]]!=arr[end[it.f]-1]){
            int temp_end=end[it.f]-1;
            while(1) {
                if(arr[temp_end]!=it.f) { temp_end--; continue; } 
                if(temp_end-start[it.f]+1==it.ss) break;
                temp_end--; it.ss--;
            }
            swap(arr[end[it.f]],arr[temp_end+1]);
            if(check(arr,n)){ cout<<"YES"<<endl; return;}
            swap(arr[end[it.f]],arr[temp_end+1]);
            if(start[it.f]!=0){
                swap(arr[end[it.f]],arr[start[it.f]-1]);
                if(check(arr,n)){ cout<<"YES"<<endl; return;}
                swap(arr[end[it.f]],arr[start[it.f]-1]);
            }
        }
        cout<<"NO"<<endl; return;
    }
    cout<<"NO"<<endl;
}

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