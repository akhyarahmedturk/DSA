#include<iostream>
#include<vector>
using namespace std;

class solution{
    string a,b,max_int;
    int solve(vector<vector<int>> &dp, int m, int n){
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        else if(a[m-1]==b[n-1]){
            return dp[m][n]=1+solve(dp,m-1,n-1);
        }
        else{
            return dp[m][n]=max(solve(dp,m-1,n),solve(dp,m,n-1));
        }
    }
    public:
    vector<int> min_insert_del(string a1,string a2){
        vector<int> res(2);
        a=a1;
        b=a2;
        vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,-1));
        for(int i=0;i<a.length()+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<b.length()+1;i++){
            dp[0][i]=0;
        }
        int lcs=solve(dp,a.length(),b.length());
        res[0]=b.length()-lcs;
        res[1]=a.length()-lcs;
        return res;
    }
};

int main(){
    solution ob;
    vector<int> res;
    res=ob.min_insert_del("akhyar","kyra");
    cout<<"Minimum insertion required are : "<<res[0]<<endl;
    cout<<"Minimum deletion required are : "<<res[1]<<endl;  
    return 0;
}