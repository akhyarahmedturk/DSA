#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int n;
long long res=0;
string str;
void solve(int idx,vector<vector<bool>> &dp){
    res++;
    if(idx==n-1) return;
    if(dp[idx+1][str[idx+1]-'a']==false) {
        dp[idx+1][str[idx+1]-'a']=true;
        solve(idx+1,dp);
    }
    if(dp[idx+1][str[idx]-'a']==false) {
        swap(str[idx+1],str[idx]);
        dp[idx+1][str[idx]-'a']=true;
        solve(idx+1,dp);
        swap(str[idx+1],str[idx]);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>str;
        // n=str.length();
        vector<vector<bool>> dp(n,vector<bool>(26,false));
        res=0;
        solve(0,dp);
        cout<<res<<endl;
    }
    return 0;
}