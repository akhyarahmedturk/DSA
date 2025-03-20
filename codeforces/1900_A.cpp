#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool check=false;
        int empty=0,total=0;
        for(int i=0;i<n;i++){
            char ch;
            cin>>ch;
            if(ch=='#'){
                if(empty>=3) check=true;
                empty=0;
            }
            else{
                empty++;
                total++;
            }
        }
        if(check || empty>=3) cout<<2<<endl;
        else cout<<total<<endl;
    }
    return 0;
}