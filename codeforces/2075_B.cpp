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
        long long n,k,ans;
        cin>>n>>k;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        if(k==1){
            if(n==2) ans=arr[0]+arr[1];
            else{
                int max_idx=1;
                for(int i=2;i<n-1;i++){
                    if(arr[i]>arr[max_idx]) max_idx=i;
                }
                if(arr[max_idx]>arr[0] || arr[max_idx]>arr[n-1]){
                    ans=arr[max_idx]+max(arr[0],arr[n-1]);
                }
                else ans=arr[0]+arr[n-1];
            }
        }
        else {
            sort(arr.rbegin(),arr.rend());
            ans=0;
            for(int i=0;i<=k;i++) ans+=arr[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}