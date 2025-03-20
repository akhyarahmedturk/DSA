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
        int prv=0,curr,res=0;
        for(int i=0;i<n;i++){
            cin>>curr;
            if(curr!=0 && prv==0) res++;
            prv=curr;
        }
        if(res>2) res=2;
        cout<<res<<endl;
    }
    return 0;
}