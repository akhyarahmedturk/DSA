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
        int n,max_num=0,min_num=1000;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            max_num=max(max_num,arr[i]);
            min_num=min(min_num,arr[i]);
        }
        int res=max(0,max(max_num-arr[0],arr.back()-min_num));
        for(int i=0;i<n;i++){
            res=max(res,arr[(i-1+n)%n]-arr[i]);
            res=max(res,arr[i]-arr[(i+1)%n]);
        }
        cout<<res<<endl;
    }
    return 0;
}