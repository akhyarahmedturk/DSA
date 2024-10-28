#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

bool backspaceCompare(string s, string t) {
        stack<char> stack1,stack2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(!stack1.empty())
                    stack1.pop();
            }
            else{
                stack1.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(!stack2.empty())
                    stack2.pop();
            }
            else{
                stack2.push(t[i]);
            }
        }
        while(!stack1.empty() && !stack2.empty()){
            if(stack1.top()!=stack2.top())
                return false;
            else{
                stack1.pop();
                stack2.pop();
            }
        }
        return (stack1.empty() && stack2.empty());
        }

int main(){
    string str1, str2;
    cout<<"Enter string 1 : ";
    cin>>str1;
    cout<<"Enter string 1 : ";
    cin>>str2;
    cout<<"Both String after applying backspasing are ";
    cout<< ((backspaceCompare(str1,str2))? "equal." : "not equal.");
    return 0;
}