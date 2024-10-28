#include<iostream>
#include<vector>
using namespace std;
int findsum(vector<vector<int>>& dp,vector<int>& nums,int i,int target){
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    else if(i==0){
        if(target==0 && nums[0]==0)
            return 2;
        else if(target==0 || target==nums[0])
            return 1;
        else
            return 0;
    }
    else if(nums[i]<=target){
        return dp[i][target]=findsum(dp,nums,i-1,target) + findsum(dp,nums,i-1,target-nums[i]);
    }
    else{
        return dp[i][target]=findsum(dp,nums,i-1,target);
    }
}

int main(){
    vector<int> nums={1,1};
    int target=0;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
    }
    // As, sum(Set to add) - sum(set to subtract) = target
    //     sum(Set to add) + sum(set to subtract) = sum(whole nums)    after simultaneously solving them we will get
    //     sum(set to add) = { target + sum(whole nums) }/2
    //   so,now we have to find a set with sum  ->  sum(set to add)
    if((target+sum)%2!=0 || target+sum<0){
        return 0;
    }
    else{
        target=(target+sum)/2;
    }
    vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
    cout<<findsum(dp,nums,nums.size()-1,target);
    return 0;
}