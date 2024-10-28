#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findLHS(vector<int>& nums){
    sort(nums.begin(), nums.end());
    int start = 0, end = 0, res = 0;
    pair<int, int> mp = { nums[0],0 };//it is the start index of current element like for this 
    //{1,1,1,1,1,2,2,2,2,2,3} it will maintain the starting index of 2 until we get to 3 then we
    // shift our start directly to starting index of 2 i:e "5" instead of moving start from 0 to 5
    while (end < nums.size()){
        if (nums[end] - nums[start] <= 1)
            end++;
        else{
            if (nums[end - 1] - nums[start] == 1)
                res = max(res, end - start);
            start = mp.second;
            mp = { nums[end],end };
        }
        if (mp.first < nums[end - 1])
            mp = { nums[end - 1],end - 1 };
    }
    if (nums.back() - nums[start] == 1)
        res = max(res, end - start);
    return res;

}

void display(vector<int>& arr){
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << ",";
    }
    cout << "]" << endl;
}

int main(){
    vector<int> arr = { 0,0,1,4,8 };
    display(arr);
    int res = findLHS(arr);
    cout << "Length of LHS is : " << res << endl;
    return 0;
} 