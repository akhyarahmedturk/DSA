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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int > res(n);
        int start = 0,end=0;
        bool check = false;
        while(end<n){
            while(arr[start]==arr[end] && end<n) end++;
            if(end-1==start) {
                check = true;
                break;
            }
            else{
                res[start] = end;
                start++;
                while(start<end){
                    res[start] =start;
                    start++;
                }
            }
        }
        if(check) cout<<-1<<endl;
        else{
            for(int i=0; i<n;i++) cout<<res[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}