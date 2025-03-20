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
        long long sum = 0,prv_min,curr,prv,res;
        cin>>prv;
        sum+=prv;
        prv_min=min(0LL,prv);
        res=prv;
        for(int i=1;i<n;i++){
            cin>>curr;
            if(abs(curr)%2==abs(prv)%2){
                sum=curr;
                prv_min=min(0LL,curr);
            }
            else{
                sum+=curr;
                prv_min=min(prv_min,sum);
            }
            res=max(res,curr);
            if(sum!=prv_min) res=max(res,sum-prv_min); 
            prv=curr;
            // cout<<"i "<<i<<"r "<<res<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}