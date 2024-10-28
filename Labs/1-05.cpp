#include<iostream>
#include<vector>
using namespace std;
vector<int> search(vector<vector<int>> &arr,int t){
	int start=0,end=arr.size()-1,mid,col=arr[0].size()-1,row;
	while(start<=end){
		mid=(start+end)/2;
		if(t<arr[mid][0]){
			end=mid-1;
		}
		else if(t>arr[mid][col]){
			start=mid+1;
		}
		else{
			row=mid;
			start=0;
			end=col;
			while(start<=col){
			mid=(start+end)/2;
			if(arr[row][mid]==t){
				return {row,mid};
			}
			else if(t>arr[row][mid]){
				start=mid+1;
			}
			else{
				end=mid-1;
			}
			break;
			}	
		}
	}
	return {-1,-1};
}
int main(){
	vector<vector<int>> arr={{1,2,3,4},
							 {5,6,7,9},
							 {34,66,44,22}
							 };
	vector<int> res;
	res=search(arr,10);
	cout<<"found at row:"<<res[0]<<" col:"<<res[1];
return 0;
}