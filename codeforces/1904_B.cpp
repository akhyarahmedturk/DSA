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
        vector<pair<long long,int>> arr(n);
        vector<int> res(n);
        for(int i=0; i<n; i++){
            cin>>arr[i].first;
            arr[i].second = i;
        }
        sort(arr.begin(), arr.end());
        int i=0,j;
        while(i<n){
            j=i+1;
            while(j<n && arr[j].first<=arr[j-1].first){
                arr[j].first+=arr[j-1].first;
                j++;
            }
            if(j<n ) arr[j].first+=arr[j-1].first;
            for(int k=i;k<j;k++) res[arr[k].second]=j-1;
            i=j;
        }
        for(int i=0;i<n;i++) cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}