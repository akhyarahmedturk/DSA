#include <iostream>
#include <vector>
using namespace std;

void Sort_colors(vector<int>& arr){
	int one = 0, two = arr.size() - 1, i = 0;
	while (i <= two){
		if (arr[i] == 0){
			if (one != i)
				swap(arr[one], arr[i]);
			else
				i++;
			one++;
		}
		else if (arr[i] == 2)
			swap(arr[two--], arr[i]);
		else
			i++;
	}
}

void display(vector<int>& arr){
	for (int i = 0; i < arr.size(); i++){
		cout << arr[i] << ",";
	}
	cout << endl;
}

int main(){
	vector<int> arr = { 2,0,2,1,1,0 };
	cout << "Arr before sort : ";
	display(arr);
	Sort_colors(arr);
	cout << "Arr After sort : ";
	display(arr);
}