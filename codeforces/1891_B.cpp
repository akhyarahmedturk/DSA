#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
using namespace std;

int main(){//NOt solved yet
    int t;
    cin>>t;
    while(t--){
        long long n,q;
        cin>>n>>q;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<long long> arr2;
        unordered_map<int,int> mp;
        for(int i=0;i<q;i++){
            int temp;
            cin>>temp;
            if(mp.count(temp)) mp[temp]++;
            else{
                arr2.push_back(temp);
                mp[temp]=1;
            }
        }
        mp[1]=1;
        for(int i=0;i<arr2.size();i++){
            long long curr = pow(2,arr2[i]),size=mp[arr2[i]],to_add=pow(2,arr2[i]-1);
            for(int j=0;j<n;j++){
                if(arr[j]%curr == 0){
                    arr[j]+=(size*to_add);
                }
            }
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}