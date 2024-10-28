#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class comp{// custom comperator class to use it in builtin sort
           // based on the second value (location to pickup)
public:
    bool operator()(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
};

void display(vector<vector<int>>& arr){
    cout << "[";
    for (int i = 0; i < arr.size(); i++){
        cout << "[" << arr[i][0] << "," << arr[i][1] << "," << arr[i][2] << "],";
    }
    cout << "]" << endl;
}

bool carPooling(vector<vector<int>>& trips, int capacity){
    sort(trips.begin(), trips.end(), comp());
    set<pair<int, int>> st;
    for (int i = 0;i < trips.size();i++){
        for (auto it : st){
            if (it.first <= trips[i][1]){
                capacity += it.second;
                st.erase(it);
            }
        }
        capacity -= trips[i][0];
        if (capacity < 0) return false;
        st.insert({ trips[i][2],trips[i][0] });
    }
    return true;
}

int main(){
    vector<vector<int>> arr = { {2,1,3},{3,3,7} };
    display(arr);
    if (carPooling(arr, 4))
        cout << "it is possible to pick up and drop off all passengers for all the given trips." << endl;
    else
        cout << "it is not possible to pick up and drop off all passengers for all the given trips." << endl;
    return 0;
}