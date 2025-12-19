/*   Bismillah
*    Author: Akhyar Ahmed Turk
*    Created: 2025-11-28 19:32 (GMT+5)

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

void solve() {
    int n,q; cin>>n>>q;
    string s; cin>>s;
    //I ky bad V,X ko directly place kar ky faida hoga
    //V,X sy pehly ? ho to I ko place karo
    // baqi sath sath 2 ky pairs me IV phir IX kar sakty
    int pairs=0,one=0,ya=0,rem=0;
    int dono=0;
    int res=0;
    int l=0,r=0;
    while(r<n){
        if(s[r]=='?') { r++; continue;}
        else if(l!=r){
            int cnt=(r-l);
            if(cnt==1 && l && (s[l-1]=='I' && (s[r]=='V' || s[r]=='X'))){
                one++; ya++;
                cnt--;
                dono++;    
            }
            else {
                if(l &&  s[l-1]=='I'){
                    ya++;
                    cnt--;
                }
                if(s[r]=='V' || s[r]=='X'){
                    cnt--;
                    one++;
                }
            }
            pairs+=cnt/2;
            rem+=(cnt&1);

        }
        if(s[r]=='V'){
            res+=5;
            if(r && s[r-1]=='I') res-=2;
        }
        else if(s[r]=='X'){
            if(r && s[r-1]=='I') res-=2;
            res+=10;
        }
        else {
            res++;
        }
        r++;
        l=r;
    }
    int cnt=(r-l);
    if(l &&  s[l-1]=='I'){
        ya++;
        cnt--;
    }
    pairs+=cnt/2;
    rem+=(cnt&1);
    // cout<<res<<" "<<pairs<<" "<<one<<" "<<ya<<" "<<rem<<" "<<dono<<endl;
    while(q--){
        int pairs1=pairs,one1=one,dono1=dono,ya1=ya,rem1=rem;
        int a,b,c; cin>>a>>b>>c;
        int curr=res;
        if(c>=one1){
            curr-=2*one1;
            c-=one1;
            ya-=dono1;
            if(c>pairs1){
                curr+=min(c,rem1);
                int ya2=min(c,rem1);
                c-=ya2; rem1-=ya2; 
                curr+=min(c,ya1);
                ya2=min(c,ya1);
                c-=ya2; ya1-=ya2;
            }
            if(c>pairs){
                int vv=c-pairs1;
                curr+=2*(vv/2);
                pairs-=vv/2;
                if(vv&1){ pairs1--; rem1++;}
            }
        }
        else{
            curr-=2*c;
            ya-=min(dono1,c);
            rem1+=(one1-min(dono1,c));
            one1-=c;
        } 
        if(b+a>=ya1){
            if(ya1>b){
                curr+=3*b;
                b=0;
                a-=(ya1-b);
                curr+=(ya1-b)*8;
            }
            else{
                curr+=3*ya1;
                b-=ya1;
            }
        }
        else{
            curr+=3*b;
            curr+=8*c;
            rem1+=(ya1-b-c);
            b=0;
            c=0;
        }
        int vv=min(pairs1,min(c,b));
        curr+=4*vv;
        pairs1-=vv;
        c-=vv;
        b-=vv;
        // cout<<curr<<" dcd "<<pairs1<<" "<<rem<<endl;
        if(b){
            curr+=5LL*min(pairs1*2+rem1,b);
            if(rem1>b) {
                rem1=0;
                b-=rem1;
                pairs1-=b/2;
                if(b&1) rem1++;
            }
            else rem1-=b;
        }
        // cout<<curr<<" dcd "<<endl;
        vv=max(0LL,min(pairs1,min(c,a)));
        curr+=9*vv;
        pairs1-=vv;
        c-=vv;
        a-=vv;
        rem1+=pairs1*2;
        if(c>0){ curr+=min(rem1,c); rem1-=min(rem1,c);}
        if(b>0){ curr+=max(0LL,min(rem1,b))*5; rem1-=min(rem1,b);}
        curr+=max(0LL,rem1*10);
        cout<<curr<<endl;
    }
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