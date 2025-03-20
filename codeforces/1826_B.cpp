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
        long long n,res=0;
        cin>>n;
        vector<long long> arr(n);
        for(long long i=0;i<n;i++) cin>>arr[i];
        long long end=n-1;
        for(long long i=0;i<end;i++){
            if(arr[i]!=arr[end]){
                if(res==0){
                    if(abs(arr[end]-arr[i])!=res) res=abs(arr[end]-arr[i]);
                    else{
                        res=1;
                        break;
                    }
                }
                else res=abs(arr[end]-arr[i]); 
            }
            end--;
        }
        cout<<res<<endl;
    }
    return 0;
}