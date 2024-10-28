#include <iostream>
#include <vector>
using namespace std;

int BubbleSort(vector<int>& arr){
	bool check;
	int count = 0;
	for (int i = 0; i < arr.size() - 1; i++){
		check = false;
		for (int j = 1; j < arr.size() - i; j++){
			count++;
			if (arr[j] < arr[j - 1]){
				swap(arr[j], arr[j - 1]);
				check = true;
			}
		}
		if (!check)
			break;
	}
	return count;
}
void display(vector<int>& arr){
	cout << "[ ";
	for (int i = 0; i < arr.size(); i++){
		cout << arr[i] << ",";
	}
	cout << "]" << endl;
}
int main(){
	vector<int> arr = { 6, 4, 1, 3, 5, 2 };
	cout << "Unsorted Array : ";
	display(arr);
	cout << "No of comparitions : " << BubbleSort(arr) << endl;
	cout << "Sorted Array : ";
	display(arr);
}