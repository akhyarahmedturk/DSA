#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

void permute(vector<string> &res,string ip,string op){
    map<char,int> check;
    if(ip.length()==0){
        res.push_back(op);
        return;
    }
    for(int i=0;i<ip.size();i++){
        check[ip[i]]++;
        if(check[ip[i]]==1)
            permute(res,ip.substr(0,i)+ip.substr(i+1,ip.length()-1),op+ip[i]);
    }
}
int main(){
    vector<string> res;
    string ip="aa5";
    permute(res,ip,"");
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}