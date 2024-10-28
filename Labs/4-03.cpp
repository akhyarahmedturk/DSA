#include <iostream>
#include <vector>
using namespace std;

class sort{
public:
	int comp, Swap;
	void BubbleSort(vector<int>& arr){
		comp = 0;
		Swap = 0;
		bool check;
		for (int i = 0; i < arr.size() - 1; i++){
			check = false;
			for (int j = 1; j < arr.size() - i; j++){
				comp++;
				if (arr[j] < arr[j - 1]){
					Swap++;
					swap(arr[j], arr[j - 1]);
					check = true;
				}
			}
			comp++;
			if (!check)
				break;
		}
	}
	void SelectionSort(vector<int>& arr){
		comp = 0;
		Swap = 0;
		int min;
		for (int i = 0; i < arr.size() - 1; i++){
			min = i;
			for (int j = i + 1; j < arr.size(); j++){
				comp++;
				if (arr[j] < arr[min])
					min = j;
			}
			comp++;
			if (i != min){
				Swap++;
				swap(arr[i], arr[min]);
			}
		}
	}
	void InsertionSort(vector<int>& arr){
		comp = 0;
		Swap = 0;
		int key, j;
		for (int i = 1; i < arr.size(); i++){
			j = i - 1;
			key = arr[i];
			comp++;
			while (j >= 0 && arr[j] > key){
				comp++;
				Swap++;
				arr[j + 1] = arr[j];
				j--;
			}
			Swap++;
			arr[j + 1] = key;
		}
	}
};

void display(vector<int>& arr){
	cout << "[ ";
	for (int i = 0; i < arr.size(); i++){
		cout << arr[i] << ",";
	}
	cout << "]" << endl;
}

int main(){
	vector<int> arr = { 5,4,3,2,1 }, arr1;
	sort s;
	arr1 = arr;
	cout << "Unsorted Array : ";
	display(arr);
	s.BubbleSort(arr1);
	cout << "Sorted Array : ";
	display(arr1);
	cout << "For Bubble Sort-> Comparisions=" << s.comp << " Swaps=" << s.Swap << endl;
	arr1 = arr;
	s.SelectionSort(arr1);
	cout << "Sorted Array : ";
	display(arr1);
	cout << "For Selection Sort-> Comparisions=" << s.comp << " Swaps=" << s.Swap << endl;
	arr1 = arr;
	s.InsertionSort(arr1);
	cout << "Sorted Array : ";
	display(arr1);
	cout << "For Insertion Sort-> Comparisions=" << s.comp << " Swaps=" << s.Swap << endl;
}