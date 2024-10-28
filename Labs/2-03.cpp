#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<vector<int> > res;//global variable to store the results
void permutation(vector<int>& nums,int end){
	if(end==-1){
		res.push_back(nums);
		return;
	}
	else{
		for(int i=end;i>=0;i--){
			swap(nums[end],nums[i]);
			permutation(nums,end-1);
			swap(nums[end],nums[i]);
		}
	}
}
void print(){
	cout<<"Permutations : {";
	for(int i=0;i<res.size();i++){
		cout<<"{";
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<",";
		}
		cout<<"},";
	} 
}
int main(){
	int size;
	cout<<"Enter size : ";
	cin>>size;
	vector<int> arr(size);
	for(int i=0;i<size;i++)
		cin>>arr[i];
	permutation(arr,size-1);
	print();
	return 0;
}


 