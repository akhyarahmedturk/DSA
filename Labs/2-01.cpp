#include<iostream>
#include<conio.h>
#include<vector>
#include<stack>

using namespace std;

bool ispalindrome(string str){
	stack<char> st;
	   int i=0;
	while(i<str.size()/2){
		   st.push(str[i++]);
	}
	i=(str.size()+1)/2;
	while(i<str.size()){
		if(st.top()!=str[i++]) return false;
		st.pop();   
	}
	return true;
} 

int main(){
	string str;
	cout<<"Enter string : ";
	cin>>str;
	cout<<"The string "<<str<<" is "<<(ispalindrome(str)? "palindrome" : "not palindrome");
	return 0;
}


 