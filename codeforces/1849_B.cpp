#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    struct comp{
        bool operator()(pair<int,int> &a,pair<int,int> &b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        }
    };
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> arr(n);
        for(int i=1;i<=n;i++){
            int temp;
            cin>>temp;
            if(temp<=k) arr[i-1]={temp,i};
            else if(temp%k==0) arr[i-1]={k,i};
            else arr[i-1]={temp%k,i};
        }
        sort(arr.begin(),arr.end(),comp());
        for(int i=0;i<n;i++) cout<<arr[i].second<<" ";
        cout<<endl;
    }
    return 0;
}