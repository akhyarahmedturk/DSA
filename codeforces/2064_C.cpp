#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long res=0,n,pos=0,neg=0;
        cin>>n;
        vector<long long> arr(n);
        for(long long i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>0) {
                pos+=arr[i];
                arr[i]=pos;
            }
        }
        res=pos;
        for(long long i=n-1;i>=0;i--){
            if(arr[i]<0) neg+=arr[i];
            else if(arr[i]+(neg*-1)>res) res=arr[i]+(neg*-1);
        }
        cout<<max(res,neg*-1)<<endl;
    }
    return 0;
}