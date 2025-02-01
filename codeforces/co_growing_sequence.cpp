#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
    int T,size;
    cin>>T;
    while(T--){
        cin>>size;
        long long temp;
        vector<bool> arr(30,false);
        while(size--){
            long long res=0;
            cin>>temp;
            for(int i=0;i<30;i++){
                if(arr[i]){
                    if(temp%2==0) {
                        res+=pow(2,i); 
                    }
                }
                else if(temp%2) arr[i]=true;
                temp/=2;
            }
            cout<<res<<" ";
        }
        cout<<endl;
    }
    return 0;
}