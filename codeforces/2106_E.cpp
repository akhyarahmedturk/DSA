#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int, int>
#define mp make_pair
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

void solve() {
    int n,q;
    cin>>n>>q;
    vi arr(n+1),idx(n+1);
    forn(i,1,n+1){
        int a;
        cin>>a;
        arr[i]=a;
        idx[a]=i;
    }
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        if(idx[k]>r || idx[k]<l) { cout<<-1<<" "; continue;}
        int mid=(l+r)/2,count1=0,count2=0,t1=0,t2=0;
        while(arr[mid]!=k){
            if(arr[mid]>k && idx[k]>mid) count1++;
            if(arr[mid]<k && idx[k]<mid) count2++;
            if(mid>idx[k]) { r=mid-1; t1++;}
            else  {l=mid+1;  t2++; }
            mid=(l+r)/2;
        }
        if(count1<count2) swap(count1,count2);
        if(t2>=k || t1>(n-k)) { cout<<-1<<" "; continue;}
        cout<<count1*2<<" ";
    }
    cout<<endl;
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