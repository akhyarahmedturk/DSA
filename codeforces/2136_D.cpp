/*
*    Author: Akhyar Ahmed Turk
*    Created: 2025-08-28 20:41 (GMT+5)

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

void solve() {//not solved
    int n; cin>>n;
    pii a,b;
    cin>>a.first>>a.ss;
    b=a;
    forn(i,0,n-1){
        int x,y; cin>>x>>y;
        if(abs(x+1e9)+abs(y+1e9) < abs(a.f+1e9)+abs(a.ss+1e9)) a={x,y};
        if(abs(x+1e9)+abs(y-1e9) < abs(a.f+1e9)+abs(b.ss-1e9)) b={x,y};
    }
    int dx=0LL,dy=0LL;
    int W=abs(a.f-b.f),X=1e9;
    vi arr(100,-1LL);
    cout<<"? D "<<X<<endl<<flush; cin>>arr[0]; dy+=X;
    if(arr[0]<X) { cout<<"? D "<<X<<endl<<flush; cin>>arr[1]; dy+=X;} 
    cout<<"? L "<<X<<endl<<flush; cin>>arr[2]; dx-=X;
    if(arr[2]<X) { cout<<"? L "<<X<<endl<<flush; cin>>arr[3]; dx-=X;;}
    cout<<"? R "<<X<<endl<<flush; cin>>arr[7]; dx+=X;
    cout<<"? R "<<X<<endl<<flush; cin>>arr[7]; dx+=X;
    if(arr[7]<X) { cout<<"? R "<<X<<endl<<flush; cin>>arr[7]; dx+=X; } 
    if(arr[7]<X) { cout<<"? R "<<X<<endl<<flush; cin>>arr[7]; dx+=X; }
    int d1=arr[3],d2=arr[7];
    int y=(d1+d2+W-2*X)/2;
    int rx=d2-y,ry=y;
    if(rx+dx>1e9) { rx-=X; cout<<"? L "<<X<<endl<<flush; cin>>arr[7];}
    if(rx+dx>1e9) { rx-=X; cout<<"? L "<<X<<endl<<flush; cin>>arr[7];}
    if(rx+dx<-1*1e9) { rx+=X; cout<<"? R "<<X<<endl<<flush; cin>>arr[7];}
    if(rx+dx<-1*1e9) { rx+=X; cout<<"? R "<<X<<endl<<flush; cin>>arr[7];}
    if(ry+dy<-1*X) { ry+=X; cout<<"? U "<<X<<endl<<flush; cin>>arr[7];}
    if(ry+dy<-1*X) { ry+=X; cout<<"? U "<<X<<endl<<flush; cin>>arr[7];}
    if(ry+dy>X) { ry-=X; cout<<"? D "<<X<<endl<<flush; cin>>arr[7];}
    if(ry+dy<-1*X) { ry+=X; cout<<"? D "<<X<<endl<<flush; cin>>arr[7];}
    cout<<"! "<<rx+dx<<" "<<ry+dy<<endl<<flush;
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