#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<long long> dp(300000+10,-1);
    dp[0]=0;
    for(int i=1;i<=300000+2;i++){
        dp[i]=dp[i-1]^i;
    }
    while(t--){
        long long a,b;
        cin>>a>>b;
        long long Xor;
        Xor=dp[a-1];
        if(Xor==b) cout<<a<<endl;
        else if((Xor^b)==a) cout<<a+2<<endl;
        else cout<<a+1<<endl;
    }
    return 0;
}