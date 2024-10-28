#include<iostream>
#include<vector>
using namespace std;
int subsetSum(vector<vector<int>> &dp,vector<int> &arr,int i,int sum){
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    else if(i==0){
        if(i==0 && sum==0)
            return 1;
        else
            return 0;
    }
    else if(arr[i-1]<=sum){
        if(subsetSum(dp,arr,i-1,sum)==1 || subsetSum(dp,arr,i-1,sum-arr[i-1])==1){
            return dp[i][sum]=1;
        }
        else{
            return dp[i][sum]=0;
        }
    }
    else{
        return dp[i][sum]=subsetSum(dp,arr,i-1,sum);
    }
}
int main(){
    vector<int> arr={10},result={0};
    int sum=0,mi;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    vector<vector<int>> dp(arr.size()+1,vector<int>(sum/2+1,-1));
    for(int i=sum/2;i>0;i--){
        if(subsetSum(dp,arr,arr.size(),i)==1)
            result.push_back(i);
    }
    subsetSum(dp,arr,arr.size(),sum);
    mi=sum;
    for(int i=0;i<result.size();i++){
        cout<<" "<<result[i];
        mi=min(mi,sum-2*result[i]);
    }
    cout<<"\nMin possible difference is : "<<mi<<endl;
    return 0;
}