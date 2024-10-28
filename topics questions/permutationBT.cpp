#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

void permute(vector<string> &res,string &str,int end){
    map<char,int> check;
    if(end==-1){
        res.push_back(str);
        return;
    }
    for(int i=end;i>=0;i--){
        check[str[i]]++;
        if(check[str[i]]==1){
            swap(str[end],str[i]);
            permute(res,str,end-1);
            swap(str[end],str[i]);
        }
    }
}
int main(){
    vector<string> res;
    string str="abab";
    permute(res,str,str.length()-1);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}