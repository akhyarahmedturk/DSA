#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include <sstream>
using namespace std;

int get_min(vector<int>& numbers){
    int res = 0, start = 0, end = numbers.size() - 1;
    while (start < end){
        res += numbers[start] + numbers[end];
        if (numbers[start] >= numbers[end]){
            start++;
        }
        else end--;
    }
    return res;
}

int main(){
    string line;
    string CASES;
    int cases;
    cin >> cases;
    cin.ignore(1000, '\n');
    vector<vector<int>> data;
    vector<int> res(cases);
    for (int i = 0;i < cases;i++){
        vector<int> numbers;
        getline(std::cin, line);
        std::stringstream line_stream(line); // Create a stringstream from the line
        int num;
        // Extract integers from the line
        while (line_stream >> num){
            numbers.push_back(num);
        }
        data.push_back(numbers);
    }
    for (int i = 0;i < cases;i++){
        cout << get_min(data[i]) << endl;
    }
    return 0;
}