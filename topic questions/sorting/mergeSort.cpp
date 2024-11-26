#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void display(vector<vector<vector<int>>>& res){
    for (int i = 0;i < res.size();i++){
        for (int j = 0;j < res[i].size();j++){
            for (int k = 0;k < res[i][j].size();k++){
                cout << res[i][j][k] << " ";
            }
            cout << "     ";
        }
        cout << endl;
    }
    cout << endl;
}
// void MergeSort(vector<vector<vector<int>>>& res, vector<int>& arr, int left, int right, int level){
//     vector<int> temp;
//     if (right-left>1){
//         cout<<"left "<<left<<" right "<<right<<" level "<<level<<endl;
//         int mid = (left + right) / 2;
//         for (int i = left;i <mid;i++){
//             temp.push_back(arr[i]);
//         }
//         res[level].push_back(temp);
//         temp.clear();
//         for (int i = mid;i < right;i++){
//             temp.push_back(arr[i]);
//         }
//         res[level].push_back(temp);
//         MergeSort(res,arr, left, mid,level+1);
//         MergeSort(res,arr, mid+1, right,level+1);
//         if(level!=floor(log2(arr.size()))+1){
//             temp.clear();
//             for (int i = left;i < mid;i++){
//             temp.push_back(arr[i]);
//             }
//             res[res.size() - 1 - level].push_back(temp);
//             temp.clear();
//             for (int i = mid;i < right;i++){
//                 temp.push_back(arr[i]);
//             }
//             res[res.size() - 1 - level].push_back(temp);
//         }
//         Merge(arr, left, mid, right);
//     }
//     else if(right-left==1 && right!=arr.size() ){
//         res[level].push_back({{arr[left]}});
//     }
// }

vector<int> Merge(vector<int> &x1,vector<int>& x2){
    vector<int> arr(x1.size()+x2.size());
    int n=0,m=0,k=0;
    while (n < x1.size() && m < x2.size()){
        if (x1[n] <= x2[m])
            arr[k++] = x1[n++];
        else
            arr[k++] = x2[m++];
    }
    while (n < x1.size()){
        arr[k++] = x1[n++];
    }
    while (m < x2.size()){
        arr[k++] = x2[m++];
    }
    return arr;
}

void solve(vector<vector<vector<int>>>& res,vector<int> &arr,int levels){
    res[0]={{arr}};
    bool check=true;
    int i=0;
    for(i=1;i<=levels;i++){
        for(int j=0;j<res[i-1].size();j++){
            vector<int> temp1;
            vector<int> temp2;
            if(res[i-1][j].size()==1){
                res[i].push_back(res[i-1][j]);
            }
            else{
                temp1=res[i-1][j];
                for(int k=0;k<temp1.size()/2;k++){
                    temp2.push_back(temp1[k]);
                }
                res[i].push_back(temp2);
                temp2.clear();
                for(int k=temp1.size()/2;k<temp1.size();k++){
                    temp2.push_back(temp1[k]);
                }
                res[i].push_back(temp2);
            }
        }
    }
    int prev=i-2,prev_i;
    for(;i<res.size();i++){
        int size=res[i-1].size(),k=0;
        prev_i=0;
        while(k+1<size){
            if(res[i-1][prev_i].size()==1 && res[prev][prev_i]==res[i-1][k]){
                res[i].push_back(res[prev][prev_i]);
                k+=1;
            }
            else{
                res[i].push_back(Merge(res[i-1][k],res[i-1][k+1]));
                k+=2;
            }
            prev_i++;
        }
        if(k!=size){
            res[i].push_back(res[i-1][k]);
        }
        prev--;
    }
}




int main(){
    vector<int> arr = { 3,6,23,0,6,2,0,6,45};
    int n = arr.size();
    vector<vector<vector<int>>> res(ceil(log2(n))*2 + 1);
    solve(res, arr,ceil(log2(n)));
    display(res);
    return 0;
} 