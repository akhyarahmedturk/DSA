#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// use when u need indexing in sets like (when you need lower upper bound while frequently updating set) 
// idx.order_of_key(value) for nums<value idx.order_of_key(value+1) for nums<=value
// idx.find_by_order(n); to get the nth value by order
#define int long long
#define ld long double
#define yesno(b) cout << ((b) ? "YES" : "NO") << "\n";
#define pii pair<int,int>
#define pb push_back
#define f first
#define ss second
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define mod 1000000007
#define mod2 998244353
const int inf=1e17+1;
#define INT_MAX LLONG_MAX
#define nl "\n"
#define forn(i,a,b) for(int i=a;i<b;i++)
#define forr(i,a,b) for(int i=a;i>=b;i--)
#define input(vec,n) for(int z=0;z<(n);z++) cin>>vec[z];

void solve() {
    int n;
    cin>>n;
    vi a(n),d(n+1),st(n,-1);
    input(a,n);
    vector<pii> e;
    bool ok=0;
    forn(i,0,n) {
        if(a[i]==-1) continue;
        ok=1;
        if(a[i]==0) {
            if(st[i]==0) {
                cout<<0<<nl;
                return;
            }
            st[i]=1;
            continue;
        }
        int l=max(0LL,i-a[i]+1);
        int r=min(n-1,i+a[i]-1);
        d[l]++;
        d[r+1]--;
        int x=i-a[i],y=i+a[i];
        if(x<0&&y>=n) {
            cout<<0<<nl;
            return;
        }
        if(x<0) e.pb({y,-1});
        else if(y>=n) e.pb({x,-1});
        else e.pb({x,y});
    }
    int cur=0;
    forn(i,0,n) {
        cur+=d[i];
        if(cur) {
            if(st[i]==1) {
                cout<<0<<nl;
                return;
            }
            st[i]=0;
        }
    }
    vector<vi> g(n);
    for(auto [x,y]:e) {
        if(y==-1) {
            if(st[x]==0) {
                cout<<0<<nl;
                return;
            }
            st[x]=1;
        }
        else {
            g[x].pb(y);
            g[y].pb(x);
        }
    }
    queue<int> q;
    forn(i,0,n) {
        if(st[i]!=-1) q.push(i);
    }
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(auto v:g[u]) {
            if(st[u]==0) {
                if(st[v]==0) {
                    cout<<0<<nl;
                    return;
                }
                if(st[v]==-1) {
                    st[v]=1;
                    q.push(v);
                }
            }
        }
    }
    vi fib(n+3);
    fib[0]=0;
    fib[1]=1;
    forn(i,2,n+3) fib[i]=(fib[i-1]+fib[i-2])%mod;
    vb vis(n);
    int ans=1;
    forn(i,0,n) {
        if(st[i]!=-1||vis[i]) continue;
        int len=0,cnt=0;
        queue<int> qq;
        qq.push(i);
        vis[i]=1;
        while(!qq.empty()) {
            int u=qq.front();
            qq.pop();
            len++;
            cnt+=g[u].size();
            for(auto v:g[u]) {
                if(st[v]==-1&&!vis[v]) {
                    vis[v]=1;
                    qq.push(v);
                }
            }
        }
        cnt/=2;
        if(cnt==0) ans=ans*2%mod;
        else ans=ans*fib[len+2]%mod;
    }
    if(!ok) ans=(ans-1+mod)%mod;
    cout<<ans<<nl;
}

int32_t main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

//code mera nahi he