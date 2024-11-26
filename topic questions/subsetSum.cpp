#include<iostream>
#include<vector>
using namespace std;
int subsetSum(vector<vector<int>> &dp,vector<int> &arr,int i,int sum){
    if(dp[i][sum]!=-1){
        cout<<"1 i "<<i<<" sum "<<sum<<endl;
        return dp[i][sum];
    }
    else if(arr[i-1]<=sum){
        cout<<"2 i "<<i<<" sum "<<sum<<endl;
        if(subsetSum(dp,arr,i-1,sum)==1 || subsetSum(dp,arr,i-1,sum-arr[i-1])==1){
            return dp[i][sum]=1;
        }
        else{
            return dp[i][sum]=0;
        }
    }
    else{
        cout<<"3 i "<<i<<" sum "<<sum<<endl;
        return dp[i][sum]=subsetSum(dp,arr,i-1,sum);
    }
}
int main(){
    vector<int> arr={2,3,4,5,6};
    int sum=20;
    vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,-1));
    for(int i=0;i<sum+1;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<arr.size()+1;i++){
        dp[i][0]=1;
    }
    cout<<subsetSum(dp,arr,arr.size(),sum);
    return 0;
}