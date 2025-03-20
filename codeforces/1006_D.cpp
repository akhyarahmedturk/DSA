#include<iostream>
#include<vector>
#include<cmath>
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
        for(int i=0;i<n;i++) cin>>arr[i];
        int start=0,end=0,max_ans=0;
        for(int i=0;i<n-1;i++){
            int temp=0;
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]) temp--;
                else if(arr[j]<arr[i]) temp++;
                if(temp>max_ans){
                    max_ans=temp;
                    start=i;
                    end=j;
                }
            }
        }
        cout<<start+1<<" "<<end+1<<endl;
    }
    return 0;
}