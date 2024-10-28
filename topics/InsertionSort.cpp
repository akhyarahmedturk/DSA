#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int> &arr)
{
    int temp, j;
    for (int i = 1; i < arr.size(); i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 &&   arr[j]>temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
void display(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
        cin >> arr[i];
    cout << "Unsorted : ";
    display(arr, n);
    InsertionSort(arr);
    cout << "Sorted : ";
    display(arr, n);
}