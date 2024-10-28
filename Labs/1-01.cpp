#include<iostream>
#include<vector>
using namespace std;
int main(){
	int row,col;
	cout<<"Enter no of rows : ";
	cin>>row;
	cout<<"Enter no of cols : ";
	cin>>col;
	int **arr,*res;
	arr=new int*[row];
	for(int i=0;i<row;i++){
		arr[i]=new int[col];
		for(int j=0;j<col;j++){
			cout<<"Enter element at row : "<<i+1<<" col : "<<j+1<<" : ";
			cin>>arr[i][j];
		}
	}
	res=new int[row*col];
	for(int i=0;i<col;i++){
		for(int j=0;j<row;j++){
			res[i*row+j]=arr[j][i];
		}
	}
	cout<<endl;
	for(int i=0;i<row*col;i++){
		cout<<" "<<res[i];
	}
	return 0;
}