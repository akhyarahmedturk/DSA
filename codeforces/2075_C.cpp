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
        long long m,n,ans=0;
        cin>>m>>n;
        vector<long long> arr(n),prefix(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>=m) arr[i]=m-1;
        }
        sort(arr.rbegin(),arr.rend());
        prefix[0]=arr[0];
        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+arr[i];
        for(int i=0;i<n-1;i++){
            long long curr=m-arr[i],start=i+1,end=n-1,max_idx=i,mid;
            while(start<=end){
                mid=(start+end)/2;
                if(arr[mid]>=curr){
                    max_idx=mid;
                    start=mid+1;
                }
                else end=mid-1;
            }
            if(max_idx==i) break;
            ans+= 2*(prefix[max_idx]-prefix[i] + arr[i]*(max_idx-i) + (max_idx-i) - m*(max_idx-i) );
        }
        cout<<ans<<endl;
    }
    return 0;
}