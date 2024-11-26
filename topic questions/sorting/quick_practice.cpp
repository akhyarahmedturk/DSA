#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
void display(vector<int>& arr){
    for (int i = 0;i < arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void display(vector<vector<vector<int>>> layer){
    for (int i = 0;i < layer.size();i++){
        for (int j = 0;j < layer[i].size();j++){
            cout << "    ";
            for (int k = 0;k < layer[i][j].size();k++){
                cout << layer[i][j][k] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
int partition(vector<int>& arr){
    int pivot = arr.back(), x = -1;
    for (int i = 0;i < arr.size() - 1;i++){
        if (arr[i] <= pivot){
            swap(arr[++x], arr[i]);
        }
    }
    swap(arr[++x], arr[arr.size() - 1]);
    return x;
}
void QuickSort(vector<vector<vector<int>>>& layer, vector<int>& arr){
    bool check = true;
    int i = 1;
    layer.push_back({ arr });
    while (check){
        vector<vector<int>> Temp;
        check = false;
        for (int j = 0;j < layer[i - 1].size();j++){
            vector<int> temp1, temp2;
            if (layer[i - 1][j].size() == 1)
                Temp.push_back(layer[i - 1][j]);
            else{
                temp1 = layer[i - 1][j];
                display(temp1);
                cout << endl;
                int pivot = partition(temp1);
                if (pivot > 0){
                    for (int k = 0;k < pivot;k++){
                        temp2.push_back(temp1[k]);
                    }
                    if (temp2.size() > 1) check = true;
                    Temp.push_back(temp2);
                    temp2.clear();
                }
                Temp.push_back({ temp1[pivot] });
                if (pivot < temp1.size() - 1){
                    for (int k = pivot + 1;k < temp1.size();k++){
                        temp2.push_back(temp1[k]);
                    }
                    if (temp2.size() > 1) check = true;
                    Temp.push_back(temp2);
                }
            }
        }
        layer.push_back(Temp);
        i++;
    }
    sort(arr.begin(), arr.end());
    layer.push_back({ arr });
}

int main(){
    vector<int> arr{ 9,8,7,6,5,4,3,2,1 };
    vector<vector<vector<int>>> layer;
    cout << "Unsorted : ";
    display(arr);
    QuickSort(layer, arr);
    cout << "Sorted : ";
    display(arr);
    display(layer);
}