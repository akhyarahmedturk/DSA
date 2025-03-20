#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<limits>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n+1,0);
        long long min_val=LLONG_MAX,max_val=LLONG_MIN,res;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            min_val=min(min_val,arr[i]);
            max_val=max(max_val,arr[i]);
            arr[i]+=arr[i-1];
        }
        res=abs(min_val-max_val);
        for(int i=2;i<=n/2;i++){
            if(n%i==0){
                min_val=LLONG_MAX;
                max_val=LLONG_MIN;
                for(int j=i;j<=n;j+=i){
                    min_val=min(min_val,arr[j]-arr[j-i]);
                    max_val=max(max_val,arr[j]-arr[j-i]);
                }
                res=max(res,abs(min_val-max_val));
            }
        }
        cout<<res<<endl;
    }
    return 0;
}