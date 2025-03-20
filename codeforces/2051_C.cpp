#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        // cout<<" n "<<n<<" m "<<m<<" k "<<k<<endl;
        int sum=n*(n+1)/2,temp;
        vector<int> mp(n+1,-1);
        for(int i=0;i<m;i++) {
            cin>>temp;
            mp[temp]=i;
        }
        for(int i=0;i<k;i++) {
            cin>>temp;
            sum-=temp;
        }
        if(n==k){
            string ans(m,'1');
            cout<<ans<<endl;
            continue;
        }
        string ans(m,'0');
        if(k==n-1 && mp[sum]!=-1) ans[mp[sum]]='1';
        cout<<ans<<endl;
    }
    return 0;
}