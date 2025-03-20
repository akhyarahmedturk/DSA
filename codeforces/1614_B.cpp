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
        long long n,total=0,left=0,right=2;
        cin>>n;
        vector<pair<long long,long long>> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i].first;
            arr[i].second=i;
        }
        sort(arr.rbegin(),arr.rend());
        vector<long long> res(n+1);
        res[0]=1;
        for(long long i=0;i<n;i+=2){
            res[arr[i].second+1]=left;
            total+= 2*abs(res[0]-left)*arr[i].first;
            if(i==n-1) break;
            res[arr[i+1].second+1]=right;
            total+= 2*abs(res[0]-right)*arr[i+1].first;
            left--;
            right++;
        }
        cout<<total<<endl;
        for(int i=0; i<=n; i++) cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}