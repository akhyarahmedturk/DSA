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
        int n,k;
        cin>>n>>k;
        vector<int> mp(26,0);
        for(int i=0;i<n;i++){
            char temp;
            cin>>temp;
            mp[temp-'a']++;
        }
        int parity=0;
        for(int it:mp){
            if(it%2!=0) parity++;
        }
        if((n-k)%2==0){
            if(parity<=k && (k-parity)%2==0) cout<<"YES\n";
            else cout<<"NO\n";
        }
        else{
            if(parity<=(k+1) && (k+1-parity)%2==0 ) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}