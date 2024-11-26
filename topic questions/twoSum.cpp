#include<iostream>
#include<vector>
#include<map>
using namespace std;

pair<int,int> TwoSum(vector<int> &nums,int target){
    map<int,int> hashmap;
    for(int i=0;i<nums.size();i++){
        int compliment=target-nums[i];
        if(hashmap.find(compliment)!=hashmap.end()){
            return {hashmap[compliment],i};
        }
        hashmap[nums[i]]=i;
    }
    return {-1,-1};
}
int main(){
    vector<int> nums={1,2,4,7,8};
    //int target=8;
    for(int i=0;i<18;i++){
        pair<int,int> res=TwoSum(nums,i);
        if(res.first!=-1){
            cout<<"The two indexes of nums to sum "<<i<<" are : "<<res.first<<" and "<<res.second<<endl;
        }
        else{
            cout<<"No two indexes found to sum "<<i<<endl;
        }
    }
    return 0;
}