#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==0){
            cout<<0<<endl;
            continue;
        }
        string str;
        cin>>str;
        int low=0,high=n-1;
        while(high-low>0){
            if(str[low]==str[high]) break;
            low++;
            high--;
        }
        cout<<high-low+1<<endl;
    }
}