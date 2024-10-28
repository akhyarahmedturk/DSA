#include <iostream>
#include <vector>
using namespace std;

int toys(vector<int>& arr, int k){
	int i = 0, min;
	while (i < arr.size()){
		min = i;
		for (int j = i + 1; j < arr.size(); j++){
			if (arr[min] > arr[j])
				min = j;
		}
		if (k >= arr[min]){
			k -= arr[min];
			arr[min] = arr[i];
		}
		else
			break;
		i++;
	}
	return i;
}
void display(vector<int>& arr){
	cout << "[ ";
	for (int i = 0; i < arr.size(); i++){
		cout << arr[i] << ",";
	}
	cout << "]" << endl;
}
int main(){
	vector<int> arr = { 1, 12, 5, 111, 200, 1000, 10 }, arr1;
	arr1 = arr;
	cout << "Toys array : ";
	display(arr);
	int k = 50;
	cout << "You can Buy maximum of " << toys(arr1, k) << " toys with " << k << " rs." << endl;
	arr1 = arr;
	k = 150;
	cout << "You can Buy maximum of " << toys(arr1, k) << " toys with " << k << " rs." << endl;
	k = 1000;
	arr1 = arr;
	cout << "You can Buy maximum of " << toys(arr1, k) << " toys with " << k << " rs." << endl;
}