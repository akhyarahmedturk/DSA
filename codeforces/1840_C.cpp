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
        long long n,k,q;
        cin>>n>>k>>q;
        vector<long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        long long  days=0,res=0;
        for(int i=0;i<n;i++){
            if(arr[i]>q){
                if(days>=k) res+=((days-k+1)*(days-k+2))/2;
                days=0;
            }
            else days++;
        }
        if(days>=k) res+=((days-k+1)*(days-k+2))/2;
        cout<<res<<endl;
    }
    return 0;
}