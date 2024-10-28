#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

string infixToPostfix(string s) {
        string ans="";
        stack<char>st;
        unordered_map<char,int> mp{{'^',3},{'*',2},{'/',2},{'+',1},{'-',1},{'(',-1}};
        for(int i=0;i<s.length();i++){
            cout<<" i "<<i<<endl;
            if( (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122 ) ){
                ans+=s[i];
            }
            else if(s[i]==')'){
                while( st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                while(!st.empty() && mp[s[i]]<mp[st.top()] && s[i]!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
void display(string &arr)
{
    for (int i = 0; i < arr.length(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    string s;
    cin>>s;
    string arr=infixToPostfix(s);
    display(arr);
}