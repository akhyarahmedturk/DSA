#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    res.push_back(intervals[0]);
    for (int i = 1;i < intervals.size();i++){
        if (res.back()[1] < intervals[i][0]){
            res.push_back(intervals[i]);
        } 
        else{
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
    }
    return res;
}

void display(vector<vector<int>>& arr){
    cout << "[";
    for (int i = 0; i < arr.size(); i++){
        cout << "[" << arr[i][0] << "," << arr[i][1] << "],";
    }
    cout << "]" << endl;
}

int main(){
    vector<vector<int>> arr = { {1,8},{2,6} };
    cout << "Before merging : ";
    display(arr);
    vector<vector<int>> res = merge(arr);
    cout << "After merging : ";
    display(res);
    return 0;
}