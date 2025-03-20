#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        double n,r,b;
        cin>>n>>r>>b;
        while(r && b){
            int curr=ceil(r/(b+1));
            for(int i=0;i<curr;i++) cout<<"R";
            cout<<"B";
            r-=curr;
            b--;
        }
        while(r--) cout<<"R";
        while(b--) cout<<"B";
        cout<<endl;
    }
    return 0;
}