#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int test;
    string s;
    cin>>test;
    while(test--){
        int temp,res=0;
        cin>>temp;
        cin>>s;
        if(s[0]=='1') res++;
        for(int i=1;i<s.length();i++){
            if(s[i]!=s[i-1]) res++;
        }
        cout<<res<<endl;
    }
    return 0;
}