#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& arr, int end){
	int start = 0;
	while (start < end){
		swap(arr[start++], arr[end--]);
	}
}
vector<int> sort(vector<int>& arr){
	int min;
	vector<int> res;
	for (int i = 0; i < arr.size() - 1; i++){
		for (int j = 0; j < arr.size() - i - 1; j++){
			if (arr[j] == arr.size() - i){
				if (j != 0){
					reverse(arr, j);
					res.push_back(j + 1);
				}
				res.push_back(arr.size() - i);
				reverse(arr, arr.size() - i - 1);
			}
		}
	}
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
	vector<int> arr = { 4,2,5,1,3 };
	cout << "Unsorted Array : ";
	display(arr);
	vector<int> res = sort(arr);
	cout << "Sorted Array : ";
	display(arr);
	cout << "result : ";
	display(res);
}