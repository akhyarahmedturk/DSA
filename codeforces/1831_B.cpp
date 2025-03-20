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
        unordered_map<int,int> mp1;
        int count=1,prv,temp,res=0;
        cin>>prv;
        for(int i=1;i<n;i++){
            cin>>temp;
            if(temp!=prv){
                if(mp1.find(prv)==mp1.end()) mp1[prv]=count;
                else mp1[prv]=max(mp1[prv],count);
                res=max(res,mp1[prv]);
                count=1;
            }
            else count++;
            prv=temp;
        }
        if(mp1.find(prv)==mp1.end()) mp1[prv]=count;
        else mp1[prv]=max(mp1[prv],count);
        res=max(res,mp1[prv]);
        
        count=1;
        cin>>prv;
        for(int i=1;i<n;i++){
            cin>>temp;
            if(temp!=prv){
                if(mp1.find(prv)==mp1.end()) res=max(res,count);
                else res=max(res,count+mp1[prv]);
                count=1;
            }
            else count++;
            prv=temp;
        }
        if(mp1.find(prv)==mp1.end()) res=max(res,count);
        else res=max(res,count+mp1[prv]);
        cout<<res<<endl;
    }
    return 0;
}