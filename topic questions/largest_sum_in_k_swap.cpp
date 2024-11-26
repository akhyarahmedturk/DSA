#include<iostream>
#include<vector>

using namespace std;
void solve(vector<string> &res,string &nums,int k,int start){
    if(k==0 || start==nums.length()-1){
        res.push_back(nums);
        return;
    }
    char x=nums[start];
    for(int i=start+1;i<nums.length();i++){
        if(nums[i]>x){
            x=nums[i];
        }
    }
    if(x<=nums[start]){
        solve(res,nums,k,start+1);
    }
    else{
        for(int i=start+1;i<nums.length();i++){
            if(x==nums[i]){
                swap(nums[start],nums[i]);
                solve(res,nums,k-1,start+1);
                swap(nums[start],nums[i]);
            }
        }
    }
    
}
int main(){
    string nums="1222995577";
    int k=7;
    vector<string> res;
    solve(res,nums,k,0);
    nums=res[0];
    for(int i=1;i<res.size();i++){
        if(res[i]>nums)
            nums=res[i];
    }
    cout<<nums<<endl;
    return 0;
}